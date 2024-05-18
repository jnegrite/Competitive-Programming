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

int nCats;

vector<tuple<int,int,int>> paths {};

int main(){
    int nEdges;
    int availMilk;
    int nCases;
    scanf("%d\n",&nCases);
    while(nCases--){
        scanf("%d %d\n",&availMilk,&nCats);
        nEdges = ((nCats * (nCats-1))>>1);
        paths.clear();
        paths.reserve(nEdges);

        UFDS u {nCats};
        int a, b, w;

        while(nEdges--){    
            scanf("%d %d %d\n",&a,&b,&w);
            paths.emplace_back(w,a,b);
        }

        sort(paths.begin(),paths.end());

        for(auto t:paths){
            int p1 {get<1>(t)};
            int p2 {get<2>(t)};
            if(!u.sameSet(p1,p2)){
                u.join(p1,p2);
                availMilk -= get<0>(t);
            }
        }
        if(availMilk<nCats){
            printf("no\n");
        } else {
            printf("yes\n");
        }
    }
}