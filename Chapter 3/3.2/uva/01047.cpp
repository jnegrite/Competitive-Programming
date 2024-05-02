#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<iomanip>

using namespace std;

long serviced[20] {};

int main(){
    int nTowersAll, nTowersBuild;
    int tc {};

    while(cin >> nTowersAll >> nTowersBuild,nTowersAll != 0 && nTowersBuild != 0){
        
        //get totalServiced
        for(int i=0;i<nTowersAll;i++){
            cin >> serviced[i];
        }

        int nCommonAreas;
        cin >> nCommonAreas;
        vector<pair<vector<int>,long>> commonAreas{};
        commonAreas.reserve(nCommonAreas);
        while(nCommonAreas--){
            int nAreas, curr;
            long subscribers;

            cin >> nAreas;
            vector<int> areas {};
            while(nAreas--){
                cin >> curr;
                areas.push_back(--curr);
            }
            cin >> subscribers;

            for(int area:areas){
                serviced[area] -= subscribers;
            }

            commonAreas.push_back(pair<vector<int>,long>{areas,subscribers});
        }

        //setup combination
        vector<int> selector {};
        selector.assign(nTowersAll,1);
        for(int i=0;i<nTowersBuild;i++){
            selector[i] = 0;
        }

        set<int> bestSelected {};

        int maxCovered {};
        do {
            int currCovered {};
            
            set<int> selected {};
            for(int i=0;i<nTowersAll;++i){
                if(selector[i] == 0){
                    currCovered += serviced[i];
                    selected.emplace(i);
                }
            }

            //check for each common area if under selected
            for(auto pr:commonAreas){
                bool isSelected {false};
                for(int area:pr.first){
                    if(selected.count(area) != 0){
                        isSelected = true;
                        break;
                    }
                }

                if(isSelected){
                    currCovered += pr.second;
                }   
            }

            if(currCovered > maxCovered){
                maxCovered = currCovered;

                bestSelected.clear();
                for(auto it {selected.begin()};it!=selected.end();it++){
                    bestSelected.emplace(*it);
                }
            }
        } while(next_permutation(selector.begin(),selector.end()));

        cout << "Case Number  " << ++tc << '\n';
        cout << "Number of Customers: " << maxCovered << '\n';
        cout << "Locations recommended:";

        for(auto it {bestSelected.begin()};it!=bestSelected.end();it++){
            cout << ' ' << (*it)+1;
        }
        cout << "\n\n";
    }
}