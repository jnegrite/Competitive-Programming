#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
using ii = pair<int,int>;

int nStations, nTargets;

vector<vector<int>> paths {};
vector<ii> cc {};
vector<int> p {};
vector<int> dfs_num {};
vector<int> dfs_low {};
int ctr {};

struct cmpPair {
    bool operator()(const ii &a, const ii &b) const{
        if(a.second != b.second){
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
};

void articulationPoint(int pos){
    dfs_num[pos] = dfs_low[pos] = ctr++;
    for(int &nxt: paths[pos]){
        if(dfs_num[nxt] == -1){
            //unvisited
            if(pos==0){
                cc[0].second++;
            }
            p[nxt] = pos;

            articulationPoint(nxt);

            if(pos > 0 && dfs_low[nxt] >= dfs_num[pos]){
                cc[pos].second++;
            }
            
            dfs_low[pos] = min(dfs_low[pos],dfs_low[nxt]);
        } else if (nxt != p[pos]){
            dfs_low[pos] = min(dfs_low[pos],dfs_num[nxt]);
        }
    }
}


int main(){
    while(scanf("%d %d\n",&nStations,&nTargets),nStations!=0 || nTargets!=0){
        paths.assign(nStations,{});
        cc.assign(nStations,{0,1});
        cc[0].second = 0;
        p.assign(nStations,-1);
        dfs_num.assign(nStations,-1);
        dfs_low.assign(nStations,0);
        ctr = 0;

        for(int i=0;i<nStations;i++){
            cc[i].first=i;
        }

        int a, b;
        while(scanf("%d %d\n",&a,&b),a!=-1 && b!=-1){
            paths[a].push_back(b);
            paths[b].push_back(a);
        }

        articulationPoint(0);
        sort(cc.begin(),cc.end(),cmpPair());

        for(int i=0;i<nTargets;++i){
            printf("%d %d\n",cc[i].first,cc[i].second);
        }
        printf("\n");
    }
}