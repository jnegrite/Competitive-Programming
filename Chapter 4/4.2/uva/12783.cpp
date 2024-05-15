#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
using ii = pair<int,int>;

int nPoints;
int ctr;
vector<vector<int>> paths {};
vector<int> p {};
vector<int> dfs_num {};
vector<int> dfs_low {};

vector<ii> weakLinks {};

void bridges(int pos){
    dfs_num[pos] = dfs_low[pos] = ctr++;
    for(int &nxt: paths[pos]){
        if(dfs_num[nxt] == -1){
            p[nxt] = pos;

            bridges(nxt);
            
            //check if bridge
            if(dfs_low[nxt] > dfs_num[pos]){
                if(pos < nxt){
                    weakLinks.push_back({pos,nxt});
                } else {
                    weakLinks.push_back({nxt,pos});
                }
            }

            dfs_low[pos] = min(dfs_low[pos],dfs_low[nxt]);
        } else if (p[pos] != nxt){
            dfs_low[pos] = min(dfs_low[pos],dfs_num[nxt]);
        }
    }
}

int main(){
    int nEdges;
    while(scanf("%d %d\n",&nPoints,&nEdges),nPoints!=0 || nEdges!=0){
        paths.assign(nPoints,{});
        p.assign(nPoints,-1);
        dfs_num.assign(nPoints,-1);
        dfs_low.assign(nPoints,0);
        weakLinks.clear();
        ctr=0;

        int a, b;
        while(nEdges--){
            scanf("%d %d\n",&a,&b);
            paths[a].push_back(b);
            paths[b].push_back(a);
        }

        for(int i=0;i<nPoints;++i){
            if(dfs_num[i] == -1){
                bridges(i);
            }        
        }

        sort(weakLinks.begin(),weakLinks.end());

        printf("%d",weakLinks.size());
        for(ii &pr:weakLinks){
            printf(" %d %d",pr.first,pr.second);
        }
        printf("\n");
    }
}