#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int nNodes;
int endPoint[1001][2] {};
int forcedMoves[1001] {};
vector<vector<int>> regMoves{};
int nAns {};

void dfs(int node, int lvl){
    //lvl 0 = glitch unused
    //lvl 1 = glitch used;
    if(endPoint[node][lvl] >= 0) return;
    
    endPoint[node][lvl] = 0;
    //conditions for stopping

    //no valid move
    if(forcedMoves[node]==0 ||
        (forcedMoves[node]==0 && regMoves[node].size()==0)){
        endPoint[node][lvl]=1;
    }

    //ok to continue with forced move
    if(forcedMoves[node]!=0){
        dfs(forcedMoves[node],lvl);
    }

    //glitch if necessary
    if(lvl==0){
        for(int &nxt:regMoves[node]){
            dfs(nxt,1);
        }
    }
    
}

int main(){
    int nEdges;
    scanf("%d %d\n",&nNodes,&nEdges);
    memset(endPoint,-1,sizeof(endPoint));
    regMoves.assign(nNodes+1,{});

    int a, b;
    while(nEdges--){
        scanf("%d %d\n",&a,&b);
        if(a<0){
            forcedMoves[-a] = b;
        } else {
            regMoves[a].push_back(b);
        }
    }
    dfs(1,0);

    for(int i=1;i<=nNodes;i++){
        if(endPoint[i][0] == 1 || endPoint[i][1] == 1){
            nAns++;
        }
    }
    printf("%d\n",nAns);
}