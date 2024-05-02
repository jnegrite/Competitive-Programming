#include<iostream>
#include<set>

using namespace std;

int main(){
    while(true){
        int numDays;
        cin >> numDays;
        multiset<long> amounts {};
        long totalPaid {};
        if(numDays == 0){
            break;
        }

        for(int day=0;day<numDays;day++){
            long numEntries;
            cin >> numEntries;
            long val;
            while(numEntries--){
                cin >> val;
                amounts.emplace(val);
            }
            totalPaid += (*(--amounts.end())- *(amounts.begin()));
            amounts.erase(amounts.begin());
            amounts.erase(--amounts.end());
        }
        cout << totalPaid << '\n';
    }
}