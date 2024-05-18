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

int ans {};
int nPoints;

vector<tuple<int,int,int>> paths {};

int main(){
    int nEdges;
    while(scanf("%d %d\n",&nPoints,&nEdges),nPoints!=0 || nEdges!=0){
        paths.reserve(nEdges);
        paths.clear();
        UFDS u {nPoints};
        int a, b, w;
        while(nEdges--){    
            scanf("%d %d %d\n",&a,&b,&w);
            paths.emplace_back(w,a,b);
        }

        sort(paths.begin(),paths.end());
        int totalSaved {};

        for(auto t:paths){
            int p1 {get<1>(t)};
            int p2 {get<2>(t)};
            if(u.sameSet(p1,p2)){
                totalSaved += get<0>(t);
            } else {
                u.join(p1,p2);
            }
        }
        printf("%d\n",totalSaved);
    }
}