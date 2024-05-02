#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

using ii = pair<int,int>;

struct cmpPair{
    bool operator()(const ii &a, const ii &b) const {
        if(a.second != b.second){
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
};

int main(){
    int nSoldiers;
    vector<ii> values {};
    int b, j;
    int tc {0};
    while(cin >> nSoldiers, nSoldiers != 0){
        values.clear();
        values.reserve(nSoldiers);
        for(int i=0;i<nSoldiers;i++){
            cin >> b >> j;
            values.push_back({b,j});
        }
        sort(values.begin(),values.end(),cmpPair());

        long base {0};
        long maxVal {0};
        for(auto it {values.begin()};it!=values.end();it++){
            base += it->first;
            maxVal = max(maxVal,base+ it->second);
        }
        cout << "Case " << ++tc << ": " << maxVal << '\n';
    }
}