#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>


using namespace std;

const int INF {~(1<<31)};
int nJunctions, nRoads;
int costStart, costStop;
vector<tuple<int,int,int>> paths {};

class UFDS {
private:
    int size;
    vector<int> p {};
    int getParent(int i){
        return i==p[i] ? i : (p[i]=getParent(p[i]));
    }

public:
    UFDS(int _size){
        size = _size;
        p.reserve(size);
        for(int i=0;i<size;++i){
            p.push_back(i);
        }
    }

    bool sameSet(int i, int j){
        return getParent(i)==getParent(j);
    }

    void join(int i, int j){
        int p1 {getParent(i)};
        int p2 {getParent(j)};

        p[p2] = p1;
    }

};

int getSpan(int a, int b, int pos){
    UFDS u {nJunctions};

    for(int i=pos;i<paths.size();++i){
        auto &curr {paths[i]};
        u.join(get<1>(curr),get<2>(curr));
        if(u.sameSet(a,b)){
            return (get<0>(curr)) - (get<0>(paths[pos]));
        }
    }   

    return INF;
}

int getBestCost(int from, int to){
    int ans {INF};
    for(int i=0;i<paths.size();i++){
        if(i>0 && get<0>(paths[i])==get<0>(paths[i-1])) continue;

        ans = min(ans,getSpan(from, to, i));
    }
    return ans;
}

int main(){
    while(cin >> nJunctions >> nRoads){
        ++nJunctions;
        paths.clear();
        
        int a, b, w;
        while(nRoads--){
            cin >> a >> b >> w;
            paths.emplace_back(w,a,b);
        }
        sort(paths.begin(), paths.end());
        cin >> costStart >> costStop;

        int nQueries;
        cin >> nQueries;
        while(nQueries--){
            cin >> a >> b;
            cout << costStart + costStop + getBestCost(a,b) << '\n';
        }
    }
}