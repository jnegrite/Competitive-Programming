#include<cstdio>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>

#define INF 1000000000
using namespace std;


int nPoints;
int currMin;
int currMax;

vector<tuple<int,int,int>> paths {};
vector<unordered_map<int,int>> edges {};
vector<int> visited{};

class UFDS {
private:
    vector<int> p {};
    vector<int> size {};
    int sourceP {};
    int targetP {};

public:
    UFDS(int n){
        p.assign(n,0);
        size.assign(n,1);
        for(int i=0;i<n;i++){
            p[i]=i;
        }
    }

    int getParent(int i){
        return (p[i]==i)?i:(p[i]=getParent(p[i]));
    }

    bool sameSet(int i, int j){
        return getParent(i)==getParent(j);
    }

    void join(int i, int j){
        //process ufds
        int p1 {getParent(i)};
        int p2 {getParent(j)};

        p[p2] = p1;
        size[p1] += size[p2];
        
        //process connections
        currMin = INF;
        currMax = 0;
        visited.assign(nPoints,false);
        sourceP = p1;
        process(p1);
    }

    void process(int pos){
        visited[pos] = true;
 
        for(const auto &nxt: edges[pos]){
            int p = getParent(nxt.first);
            if(p == sourceP){
                currMin = min(currMin,nxt.second);
                if(!visited[nxt.first]){
                    process(nxt.first);
                }
            } else {
                currMax = max(currMax,nxt.second);
            }
        }
    }

    int getSize(int i){
        return size[getParent(i)];
    }
};

int main(){
    int nCases;
    int nEdges;
    scanf("%d\n",&nCases);
    while(nCases--){
        scanf("%d %d\n",&nPoints,&nEdges);
        ++nPoints;
        UFDS u {nPoints};
        paths.clear();
        paths.reserve(nEdges);
        edges.assign(nPoints,{});
        int ans {};

        int a, b, w;    
        while(nEdges--){
            scanf("%d %d %d\n",&a,&b,&w);
            paths.emplace_back(-w,a,b);
            edges[a][b] = w;
            edges[b][a] = w;
        }

        sort(paths.begin(), paths.end());

        for(int i=0;i<paths.size();i++){
            //join
            auto &t {paths[i]};
            int p1 {get<1>(t)};
            int p2 {get<2>(t)};
            int currW {-get<0>(t)};

            if(!u.sameSet(p1,p2)){
                u.join(p1,p2);
                if(currMin > currMax){
                    //printf("Added %d while connecting %d to %d\n",u.getSize(p1),p1,p2);
                    ans += u.getSize(p1);
                }
            }
        }

        printf("%d\n",ans);
    }
}