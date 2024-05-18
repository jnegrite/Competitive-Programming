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


int main(){
    int nPoints;
    vector<tuple<int,int,int>> paths {};
    scanf("%d\n",&nPoints);
    paths.reserve((nPoints * (nPoints-1))>>1);

    int dist;
    for(int i=1;i<=nPoints;i++){
        for(int j=1;j<=nPoints;j++){
            scanf("%d",&dist);
            if(j>i){
                paths.emplace_back(dist,i,j);
            }
        }
    }

    sort(paths.begin(), paths.end());

    UFDS u {nPoints+1};
    int nLinks {1};
    for(auto curr:paths){
        int p1 {get<1>(curr)};
        int p2 {get<2>(curr)};
        if(!u.sameSet(p1,p2)){
            printf("%d %d\n",p1,p2);
            u.join(p1,p2);
            if(++nLinks >= nPoints){
                break;
            }
        }
    }
}