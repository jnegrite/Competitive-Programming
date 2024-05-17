#include<cstdio>
#include<bitset>
#include<vector>

using namespace std;

int lb, ub;
int nEmployees;
vector<vector<int>> paths {};
vector<vector<int>> pathsRev {};
bitset<5001> visited {};

int dfs(int pos, vector<vector<int>> &basis){
    if(visited.test(pos)) return 0;

    visited.set(pos);
    int ans {1};
    auto &curr {basis[pos]};
    for(int nxt:curr){
        ans += dfs(nxt,basis);
    }
    return ans;
}

int main(){
    int nRelations;
    scanf("%d %d %d %d\n",&lb,&ub,&nEmployees,&nRelations);
    paths.assign(nEmployees,{});
    pathsRev.assign(nEmployees,{});
    
    visited.reset();

    //get input for edges
    int a, b;
    while(nRelations--){
        scanf("%d %d\n",&a,&b);
        paths[a].push_back(b);
        pathsRev[b].push_back(a);
    }

    int ans[3] {};
    for(int i=0;i<nEmployees;++i){
        visited.reset();
        int dependents {dfs(i,paths)};
        visited.reset();
        int needToUnlock {dfs(i,pathsRev)};

        int forcedOpen {nEmployees-dependents};

        if(forcedOpen < lb){
            ans[0]++;
        }

        if(forcedOpen < ub){
            ans[1]++;
        }

        if(needToUnlock > ub){
            ans[2]++;
        }
    }

    for(int i=0;i<3;i++){
        printf("%d\n",ans[i]);
    }
}