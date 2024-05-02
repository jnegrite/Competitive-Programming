#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    long nGames, nGoals;
    while(cin >> nGames >> nGoals){
        int a, b;
        priority_queue<int,vector<int>,greater<int>> q {};
    
        long totalScore {};
        for(long i=0;i<nGames;++i){
            cin >> a >> b;
            if(a > b){
                totalScore += 3;
            } else {
                q.emplace(b-a);
            }
        }

        //run through pq to adjust goals
        int score {};
        while(!q.empty() && nGoals >= q.top()){
            int target {q.top()};
            q.pop();

            if(nGoals > target){
                totalScore += 3;
                nGoals -= (target+1);
            } else if (nGoals == target){
                nGoals = 0;
                ++totalScore;
            } else {
                break;
            }
        }

        cout << totalScore << '\n';

    }
}