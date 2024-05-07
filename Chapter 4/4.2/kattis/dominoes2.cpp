#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;
int n, m, l, a, b;
vector<vector<int>> paths {};
vector<bool> isUp {};

int dfs(int pos){
    if(!isUp[pos]){
        return 0;
    }

    int ans = 1;
    isUp[pos] = false;
    for(int &nxt: paths[pos]){
        if(isUp[nxt]){
            ans += dfs(nxt);
        }
    }
    return ans;
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    while(nCases--){
        scanf("%d %d %d\n",&n,&m,&l);
        paths.assign(n+1,{});
        isUp.assign(n+1,true);
        int totalDown {};
        
        while(m--){
            scanf("%d %d\n",&a,&b);
            paths[a].push_back(b);
        }

        while(l--){
            scanf("%d\n",&a);
            totalDown += dfs(a);
        }
        printf("%d\n",totalDown);
    }
}