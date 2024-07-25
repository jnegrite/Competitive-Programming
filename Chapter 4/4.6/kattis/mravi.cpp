#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<tuple>
#include<iomanip>

using namespace std;

vector<double> values {};
vector<int> cntIn {};
vector<vector<tuple<int,int,int>>> paths {};

int main(){
    int nPoints;
    cin >> nPoints;
    
    cntIn.assign(nPoints+1,0);
    values.assign(nPoints+1,-1);
    paths.assign(nPoints+1,{});

    int a, b, pct, pow;
    for(int i=1;i<nPoints;i++){
        cin >> a >> b >> pct >> pow;
        paths[b].emplace_back(a,pct,pow);
        cntIn[a]++;
    }

    queue<int> q {};
    for(int i=1;i<=nPoints;i++){
        cin >> values[i];
        if(values[i] > 0.0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int currPos {q.front()};
        q.pop();

        double currVal {values[currPos]};
        for(auto nxt: paths[currPos]){
            int nxtPos {get<0>(nxt)};
            double nxtVal {currVal};
            if(currVal > 1 && (get<2>(nxt)==1)){
                nxtVal = sqrt(nxtVal);
            }
            values[nxtPos] = max(values[nxtPos],nxtVal * 100.00 / get<1>(nxt));
            if(--cntIn[nxtPos] == 0){
                q.push(nxtPos);
            }
        }
    }

    cout << setprecision(5) << fixed << values[1] << '\n';
}