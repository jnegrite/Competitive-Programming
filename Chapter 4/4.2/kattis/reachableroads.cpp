#include<cstdio>
#include<vector>
#include<cstring>
#include<bitset>

using namespace std;

int nPoints;
bitset<1000> visited {};
vector<vector<int>> paths {};
int a, b;

void dfs(int pos){
    visited.set(pos);
    for(int &nxt: paths[pos]){
        if(!visited.test(nxt)){
            dfs(nxt);
        }
    }
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    while(nCases--){
        visited.reset();
        scanf("%d\n",&nPoints);
        paths.assign(nPoints,{});

        int nEdges;
        scanf("%d\n",&nEdges);

        while(nEdges--){
            scanf("%d %d\n",&a,&b);
            paths[a].push_back(b);
            paths[b].push_back(a);
        }

        int ccs {};
        for(int i=0;i<nPoints;++i){
            if(!visited.test(i)){
                ccs++;
                dfs(i);
            }
        }
        printf("%d\n",ccs-1);
    }    
}