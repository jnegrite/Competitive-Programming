#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int nValues;
    long curr;
    while(cin >> nValues, nValues != 0){
        priority_queue<long, vector<long>, greater<long>> q {};

        for(int i=0;i<nValues;i++){
            cin >> curr;
            q.emplace(curr);
        }
        
        long totalCost {};
        long temp {};
        while(q.size() >= 2){
            temp = 0;
            for(int i=0;i<2;i++){
                temp += q.top();
                q.pop();
            }
            totalCost += temp;
            q.emplace(temp);
        }
        cout << totalCost << '\n';
    }
}