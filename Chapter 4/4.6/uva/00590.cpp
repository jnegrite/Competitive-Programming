#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
using ll = long long;

ll memo[11][1000] {};
vector<vector<vector<int>>> costs {};
int nCities, k;

int getCost(int from, int to, int day){
    auto &curr {costs[from][to]};
    if (curr.size() == 0) return 0;
    return curr[day%curr.size()];
}

ll dp(int pos, int day){
    if(day == k){
        if(pos == nCities){
            return 0LL;
        } else {
            return -2LL;
        }
    }

    auto &curr{memo[pos][day]};

    if(curr != -1LL){
        return curr;
    }

    curr = -2LL;
    //get all flights out of this place
    for(int i=1;i<=nCities;++i){
        if(i==pos) continue;

        int currCost {getCost(pos,i,day)};
        if(currCost == 0) continue;

        ll tempCost {dp(i,day+1)};
        if(tempCost == -2LL) continue;

        if(curr == -2LL || (tempCost + currCost < curr)){
            curr = tempCost + currCost;
        }
    }
    return curr;
}

int main(){
    int tc {};
    while( cin >> nCities >> k){
        if(nCities==0 && k==0) break;
        
        ll ans {-2LL};

        memset(memo,-1LL,sizeof(memo));
        vector<vector<int>> sub {};
        sub.assign(nCities+1, {});
        costs.assign(nCities+1,sub);

        int nFlights, val;
        for(int from=1;from<=nCities;++from){
            for(int to=1;to<=nCities;++to){
                if(from==to) continue;

                cin >> nFlights;
                auto &target {costs[from][to]};
                target.reserve(nFlights);
                for(int i=0;i<nFlights;++i){
                    cin >> val;
                    target.push_back(val);
                }
            }
        }

        ans = dp(1,0);

        cout << "Scenario #" << ++tc << '\n';
        if(ans == -2){
            cout << "No flight possible.\n";
        } else {
            cout << "The best flight costs " << ans << ".\n";
        }
        cout << '\n';        
    }
}