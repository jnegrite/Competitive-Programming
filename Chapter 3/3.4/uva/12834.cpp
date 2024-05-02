#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int nCases;
    cin >> nCases;
    long nPlaces, k;
    vector<long> collected {};
    long curr, earned;
    long netProfit {};
    for(int tc=1;tc<=nCases;++tc){
        cin >> nPlaces >> k;

        netProfit=0;
        collected.clear();
        collected.assign(nPlaces,0);
        for(long i=0;i<nPlaces;i++){
            cin >> collected[i];
        }
        priority_queue<long> refunds {};
        for(long i=0;i<nPlaces;i++){
            cin >> curr;
            earned = (curr-collected[i]);
            netProfit += earned;
            if(earned < 0){
                refunds.emplace(-earned);
            }
        }

        //reversals
        while(!refunds.empty() && k-- > 0){
            netProfit+=refunds.top();
            refunds.pop();
        }

        cout << "Case " << tc << ": ";
        if(netProfit <= 0){
            cout << "No Profit\n";
        } else {
            cout << netProfit << '\n';
        }
    }
}