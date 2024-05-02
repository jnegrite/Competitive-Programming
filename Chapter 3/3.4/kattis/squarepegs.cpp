#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<double> plots {};
    vector<double> houses {};
    plots.reserve(n);
    houses.reserve(m+k);

    double curr;
    for(int i=0;i<n;i++){
        cin >> curr;
        plots.push_back(curr);
    }

    for(int i=0;i<m;i++){
        cin >> curr;
        houses.push_back(curr);
    }

    double factor {sqrt(2.0)};
    for(int i=0;i<k;i++){
        cin >> curr;
        houses.push_back(curr/factor);
    }
    sort(plots.begin(),plots.end());
    sort(houses.begin(),houses.end());

    int idxPlots {n-1};
    int idxHouses {m+k-1};

    int ans {};
    while(idxPlots >= 0 && idxHouses >= 0){
        if(houses[idxHouses--] < plots[idxPlots]){
            ++ans;
            --idxPlots;
        }
    }
    cout << ans << '\n';
}