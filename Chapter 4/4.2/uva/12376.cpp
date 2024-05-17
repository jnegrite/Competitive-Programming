#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int weights[100] {};
int nNodes;
int endNode;
vector<vector<int>> paths {};

int traverse(int pos){
    
    if (paths[pos].size()==0){
        endNode = pos;
        return weights[pos];
    }

    auto &curr {paths[pos]};
    int bestWeight {weights[curr[0]]};
    int bestIdx {curr[0]};

    for(int i=1;i<curr.size();i++){
        if(weights[curr[i]] > bestWeight){
            bestWeight = weights[curr[i]];
            bestIdx = curr[i];
        }
    }

    return weights[pos] + traverse(bestIdx);
}

int main(){
    int nCases;
    int nConnections;
    scanf("%d\n",&nCases);
    for(int tc=1;tc<=nCases;++tc){
        scanf("%d %d\n",&nNodes,&nConnections);
        paths.assign(nNodes,{});

        for(int i=0;i<nNodes;++i){
            scanf("%d",&weights[i]);
        }
        
        int a, b;
        while(nConnections--){
            scanf("%d %d\n",&a,&b);
            paths[a].push_back(b);
        }

        int bestWeight {traverse(0)};
        printf("Case %d: %d %d\n",tc,bestWeight,endNode);
    }
}