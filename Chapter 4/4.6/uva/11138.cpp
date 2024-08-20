#include<iostream>
#include<vector>

using namespace std;

int nNuts, nBolts;
vector<bool> visited {};
vector<int> match {};
vector<vector<int>> paths {};

int aug(int L) {
    if(visited[L]) return 0;

    visited[L] = true;

    for(auto tempR: paths[L]){
        if((match[tempR] == -1) || (aug(match[tempR]))){
            match[tempR] = L;
            return 1;
        }
    }
    return 0;
}

int main(){
    int nCases, val;
    cin >> nCases;

    for(int tc=1;tc<=nCases;++tc){
        cin >> nNuts >> nBolts;
        paths.assign(nNuts,{});
        match.assign(nBolts,-1);

        for(int i=0;i<nNuts;++i){
            for(int j=0;j<nBolts;++j){
                cin >> val;
                if(val == 1){
                    paths[i].push_back(j);
                }
            }
        }

        int ans {0};
        for(int i=0;i<nNuts;++i){
            visited.assign(nNuts,false);
            ans += aug(i);
        }

        cout << "Case " << tc << ": a maximum of " << ans << " nuts and bolts can be fitted together\n";
    }


}