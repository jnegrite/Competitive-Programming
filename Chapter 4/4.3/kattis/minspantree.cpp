#include<cstdio>
#include<vector>
#include<algorithm>
#include<tuple>

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

int nPoints;

int main(){
    int nEdges {};
    vector<tuple<int,int,int>> paths {};
    vector<pair<int,int>> ans {};
    while(scanf("%d %d\n",&nPoints,&nEdges),nPoints!=0 || nEdges!=0){
        paths.clear();
        paths.reserve(nEdges);
        ans.clear();
        ans.reserve(nPoints-1);

        int a, b, w;
        while(nEdges--){
            scanf("%d %d %d\n",&a,&b,&w);
            paths.emplace_back(w,a,b);
        }

        sort(paths.begin(),paths.end());
        
        UFDS u {nPoints};

        int totalWeight {0};
        for(auto &t:paths){
            int p1 {get<1>(t)};
            int p2 {get<2>(t)};
            if(!u.sameSet(p1,p2)){
                if(p1 > p2){
                    swap(p1,p2);
                }
                u.join(p1,p2);
                ans.emplace_back(p1,p2);
                totalWeight+=get<0>(t);

                if(ans.size() >= nPoints-1){
                    break;
                }
            }
        }

        if(ans.size() < nPoints-1){
            printf("Impossible\n");
        } else {
            printf("%d\n",totalWeight);
            sort(ans.begin(),ans.end());
            for(auto &pr: ans){
                printf("%d %d\n",pr.first,pr.second);
            }
        }
    }
}