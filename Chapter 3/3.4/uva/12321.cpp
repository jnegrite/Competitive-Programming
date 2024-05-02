#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using ll = pair<long,long>;

struct cmp{
    bool operator()(const ll &a, const ll &b) const {
        if(a.first != b.first){
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    }
};




int main(){
    long l, g, x, r;
    while(cin >> l >> g, l!=0 || g!=0){
        vector<ll> stations {};
        stations.reserve(g);

        for(long i=0;i<g;i++){
            cin >> x >> r;
            stations.push_back(ll{x-r,x+r});
        }
        sort(stations.begin(),stations.end());

        long currPos {0};
        long currSpan {0};
        long stationsRemaining {};

        auto it {stations.begin()};
        while(it != stations.end()){
            
            //check if can position
            if(it->first <= currPos){
                if(it->second > currSpan){
                    currSpan = it->second;

                    if(currSpan >= l){
                        currPos = currSpan;
                        ++stationsRemaining;
                        break;
                    }
                }
                ++it;
            } else if (currSpan > currPos){
                ++stationsRemaining;
                currPos = currSpan;
            } else {
                break;
            }
        }

        if(currPos < l){
            cout << -1 << '\n';
        } else {
            cout << g - stationsRemaining << '\n';
        }

    }
}