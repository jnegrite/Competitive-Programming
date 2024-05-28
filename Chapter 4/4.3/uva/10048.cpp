#include<cstdio>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>

using namespace std;

class UFDS{
public:    
    UFDS(int size){
        p.assign(size,0);
        for(int i=0;i<size;++i){
            p[i] = i;
        }
    }
    
    bool sameSet(int i, int j){
        return getParent(i) == getParent(j);
    }

    void join(int i, int j){
        int p1 {getParent(i)};
        int p2 {getParent(j)};
        if(p1 > p2){
            swap(p1,p2);
        }
        p[p2] = p1;
    }

private:
    vector<int> p {};
    int getParent(int i){
        return p[i] == i ? i : p[i]=getParent(p[i]);
    }
};

int nPoints, nEdges, nQueries;
int capacity[101][101] {};
bool visited[101] {};
int rootNode;
vector<vector<pair<int,int>>> mstPaths {};

void dfs(int pos, int currMax){
    visited[pos] = true;
    capacity[rootNode][pos] = capacity[pos][rootNode] = currMax;
    for(auto &nxt:mstPaths[pos]){
        if(!visited[nxt.first]){
            dfs(nxt.first,max(currMax,nxt.second));
        }
    }
}

int main(){
    int tc{};

    while(scanf("%d %d %d\n",&nPoints,&nEdges,&nQueries), nPoints!=0 || nEdges!=0 || nQueries!=0){
        vector<tuple<int,int,int>> origPaths {};
        mstPaths.clear();
        mstPaths.assign(nPoints+1,{});
        origPaths.reserve(nEdges);
        int a, b, w;
        while(nEdges--){
            scanf("%d %d %d\n",&a,&b,&w);
            origPaths.emplace_back(w,a,b);
        }
        sort(origPaths.begin(), origPaths.end());
        
        UFDS u {nPoints+1};

        //do mst
        for(auto &t:origPaths){
            w = get<0>(t);
            int p1 {get<1>(t)};
            int p2 {get<2>(t)};
            if(!u.sameSet(p1,p2)){
                mstPaths[p1].emplace_back(p2,w);
                mstPaths[p2].emplace_back(p1,w);
                u.join(p1,p2);
            }
        }

        memset(capacity,-1,sizeof(capacity));
        //for every query
        tc++;
        if(tc>1){
            printf("\n");
        }
        printf("Case #%d\n",tc);

        while(nQueries--){
            scanf("%d %d\n",&a,&b);
            if(capacity[a][b] == -1){
                memset(visited,false,sizeof(visited));
                rootNode=a;
                dfs(a,0);
                for(int i=1;i<=nPoints;++i){
                    if(capacity[a][i] == -1){
                        capacity[a][i] = capacity[i][a] = -2;
                    }
                }
            }

            if(capacity[a][b] == -2){
                printf("no path\n");
            } else {
                printf("%d\n",capacity[a][b]);
            }
        }
        
    }
}