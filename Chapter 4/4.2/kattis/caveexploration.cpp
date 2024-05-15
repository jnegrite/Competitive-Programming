#include<cstdio>
#include<vector>

using namespace std;

int nChambers;
vector<vector<int>> paths {};
vector<int> p {};
vector<int> dfs_num {};
vector<int> dfs_low {};
int ctr {};

int getChambers(int pos){
    int ans {1};
    dfs_num[pos] = dfs_low[pos] = ctr++;
    for(int &nxt:paths[pos]){
        if(dfs_num[nxt] == -1){
            p[nxt] = pos;
            int temp {getChambers(nxt)};

            if(dfs_low[nxt] <= dfs_num[pos]){
                ans += temp;
            }

            dfs_low[pos] = min(dfs_low[pos],dfs_low[nxt]);
        } else if(p[pos] != nxt){
            dfs_low[pos] = min(dfs_low[pos],dfs_num[nxt]);
        }
    }

    return ans;
}

int main(){
    int nTunnels;
    scanf("%d %d\n",&nChambers,&nTunnels);
    paths.assign(nChambers,{});
    p.assign(nChambers,-1);
    dfs_num.assign(nChambers,-1);
    dfs_low.assign(nChambers,0);

    int a, b;
    while(nTunnels--){
        scanf("%d %d\n",&a,&b);
        paths[a].push_back(b);
        paths[b].push_back(a);
    }

    printf("%d\n",getChambers(0));
}