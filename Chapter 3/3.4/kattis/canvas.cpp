#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int nCases;
    cin >> nCases;
    long nCanvasses;
    long curr, nxt;
    long long ans {};
    while(nCases--){
        priority_queue<long, vector<long>, greater<long>> q {};
        cin >> nCanvasses;
        while(nCanvasses--){
            cin >> curr;
            q.emplace(curr);
        }
        
        ans = 0;
        while(q.size() >= 2){
            long temp {};
            for(int i=0;i<2;i++){
                temp += q.top();
                q.pop();
            }
            ans += temp;
            q.emplace(temp);
        }
        cout << ans << '\n';
    }
}