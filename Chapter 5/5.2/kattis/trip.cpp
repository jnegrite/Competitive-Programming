#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main(){
    string s;
    long long totalCost;
    
    vector<long long> costs {};
    while(getline(cin,s), s!= "0"){
        int nTerms = stoi(s);
        bool exact {true};

        costs.clear();
        costs.reserve(nTerms);
        totalCost = 0;

        for(int i=0;i<nTerms;++i){
            getline(cin,s);
            long long val {round(100*stold(s))};
            costs.push_back(val);
            totalCost+=val;
        }

        long long minCost {totalCost/nTerms};
        long long maxCost {minCost};
        if(totalCost%nTerms != 0){
            ++maxCost;
            exact = false;
        }

        long long above {0};
        long long below {0};

        for(long long val: costs){
            if(val >= maxCost){
                above += (val-maxCost);
                
            } else {
                below += (minCost-val);
            }
        }
        
        long long totalDiff = max(above,below);
        
        cout << "$";
        long long q {totalDiff / 100LL};
        if(q == 0){
            cout << "0.";
        } else {
            cout << q << '.';
        }

        q = totalDiff%100;
        if(q < 10){
            cout << '0';
        }
        cout << q << '\n';
    }
}
