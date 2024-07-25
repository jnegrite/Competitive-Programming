#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<tuple>

#define UBOUND 400001
using namespace std;

struct cheer {
    int id {};
    int ds {};
    int cost {};

    cheer(int _id, int _ds, int _cost){
        id=_id;
        ds=_ds;
        cost=_cost;
    }

    bool operator<(const cheer &o) const {
        return ds < o.ds;
    }
};


int dist[UBOUND] {};
int parent[UBOUND] {};
int nCheers;
int mTarget;
vector<cheer> cheers {};

int main(){
    memset(dist,-1,sizeof(dist));
    memset(parent,-1,sizeof(parent));
    cin >> nCheers >> mTarget;

    int value, cost;
    cheers.reserve(nCheers++);
    int minDS {0};
    for(int i=2;i<=nCheers;++i){
        int ds;
        long long cost;
        cin >> ds >> cost;

        if(cost > mTarget) continue;

        minDS = min(minDS, ds);
        cheers.emplace_back(i,ds,cost);
    }

    const int maxVal {mTarget-minDS};
    sort(cheers.begin(),cheers.end());
    dist[0] = parent[0] = 0;
    
    int bestDist{mTarget};
    int bestDistLoc{0};

    int nxtNode, nxtDist;
    bool didUpdate {true};
    while(didUpdate){
        didUpdate = false;
        for(int pos=0;pos<=maxVal;){
            int nxtPos {pos+1};

            if(dist[pos] != -1){
                if(dist[pos] <= bestDist){
                    int tempDist {dist[pos] + mTarget - pos};

                    if((pos<=mTarget) && (tempDist < bestDist)){
                        bestDist = tempDist;
                        bestDistLoc = pos;
                    }

                    for(int i=0;i<cheers.size();++i){
                        auto  &curr {cheers[i]};

                        nxtNode = pos + curr.ds;
                        nxtDist = dist[pos] + curr.cost;

                        //if(nxtDist >= bestDist) continue;
                        if((nxtNode < 0) || (nxtNode > maxVal)) continue;

                        //check if improves the next node
                        if(dist[nxtNode] == -1 || nxtDist < dist[nxtNode]){
                            dist[nxtNode] = nxtDist;
                            parent[nxtNode] = i;
                            didUpdate = true;
                        }
                    }
                }
            }
            pos = nxtPos;
        }
    }

    int val {bestDistLoc};
    vector<int> nodes {};
    nodes.assign(mTarget-bestDistLoc,1);
    while(val != 0){
        cheer &p {cheers[parent[val]]};
        nodes.push_back(p.id);
        val -= p.ds;
    }

    sort(nodes.begin(),nodes.end());
    cout << nodes.size() << '\n';
    cout << nodes[0];
    for(auto it {++nodes.begin()}; it!=nodes.end();++it){
        cout << ' ' << *it;
    }
    cout << '\n';
}