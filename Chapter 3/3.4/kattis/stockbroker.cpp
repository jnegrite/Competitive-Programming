#include<iostream>
#include<vector>

using namespace std;

int main(){
    int prev {500};
    int curr;
    int nDays {};
    bool increasing {true};
    vector<int> prices {};

    cin >> nDays;
    prev = 501;
    while(nDays--){
        cin >> curr;
        if((increasing && curr < prev) || (!increasing && curr > prev)){
            prices.push_back(prev);
            increasing = !increasing;
        }
        prev = curr;
    }

    //simulate
    long nStocksOwned{};
    long long money {100};
    for(int i=1;i<prices.size();i++){
        
        if(i%2==1){
            //buy
            nStocksOwned = min(100000LL,money/prices[i]);
            money -= (nStocksOwned *prices[i]);
        } else {
            //sell everything
            money += prices[i] * nStocksOwned;
            nStocksOwned = 0;
        }
    }

    //sell off everything
    if(nStocksOwned != 0){
        money += curr * nStocksOwned;
        nStocksOwned = 0;
    }
    cout << money << '\n';
}