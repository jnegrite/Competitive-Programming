#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using ii = pair<int,int>; 

long totalDeposit {};
long currDep, currTime;

int main(){
    int n, t;
    cin >> n >> t;
    vector<ii> customers {};
    customers.reserve(n);
    while(n--){
        cin >> currDep >> currTime;
        customers.push_back({currTime,currDep});
    }
    sort(customers.begin(), customers.end());

    priority_queue<long, vector<long>, greater<long>> q {};
    for(ii p: customers){
        if(q.size() <= p.first){
            q.emplace(p.second);
            totalDeposit += p.second;
        } else {
            long change {p.second - q.top()};
            
            if(change > 0){
                q.pop();
                q.emplace(p.second);
                totalDeposit += change;
            }
        }
    }
    cout << totalDeposit << '\n';
}