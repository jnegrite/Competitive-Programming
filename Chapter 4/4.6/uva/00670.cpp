#include<iostream>
#include<vector>
#include<cmath>
#include<math.h>

using namespace std;

int nLeft, nRight;
vector<pair<int,int>> pointsLeft {};
vector<pair<int,int>> pointsRight {};
vector<vector<int>> paths {};
vector<bool> visited {};
vector<int> matchRight {};
vector<int> matchLeft {};

double getDist(pair<int,int> &a, pair<int,int> &b){
    double dx {a.first-b.first};
    double dy {a.second-b.second};

    return sqrt((dx*dx) + (dy*dy));
}

bool aug(int L){
    if(visited[L]) return false;

    visited[L] = true;
    for(int &R: paths[L]){
        if((matchRight[R] == -1) || (aug(matchRight[R]))){
            matchRight[R] = L;
            return true;
        }
    }
    return false;
}

int main(){
    int nCases;
    cin >> nCases;

    int x, y;
    while(nCases--){
        cin >> nLeft >> nRight;
        
        pointsLeft.clear();
        pointsRight.clear();
        pointsLeft.reserve(nLeft);
        pointsRight.reserve(nRight);
        paths.clear();
        paths.assign(nLeft,{});
        matchLeft.assign(nLeft,-1);
        matchRight.assign(nRight,-1);

        for(int i=0;i<nLeft;++i){
            cin >> x >> y;
            pointsLeft.emplace_back(x,y);
        }

        for(int i=0;i<nRight;++i){
            cin >> x >> y;
            pointsRight.emplace_back(x,y);
        }

        for(int i=0;i<(nLeft-1);++i){
            double maxDist = 2*getDist(pointsLeft[i],pointsLeft[i+1]);

            for(int j=0;j<nRight;++j){
                double d1 {getDist(pointsLeft[i],pointsRight[j])};

                if(d1 > maxDist) continue;

                double d2 {getDist(pointsLeft[i+1],pointsRight[j])};

                if((d2 > maxDist) || ((d1+d2) > maxDist)) continue;

                paths[i].push_back(j);
            }
        }

        for(int i=0;i<(nLeft-1);++i){
            visited.assign(nLeft,false);
            aug(i);
        }

        matchLeft.assign(nLeft,-1);
        for(int i=0;i<nRight;++i){
            int L = matchRight[i];

            if(L==-1) continue;
            
            matchLeft[L] = i;
        }

        vector<pair<int,int>> finAns {};
        for(int i=0;i<nLeft-1;++i){
            finAns.push_back(pointsLeft[i]);
            if(matchLeft[i] != -1){
                finAns.push_back(pointsRight[matchLeft[i]]);
            }
        }
        cout << finAns.size()+1 << '\n';
        for(auto &pr: finAns){
            cout << pr.first << ' ' << pr.second << ' ';
        }
        pair<int,int> &end {pointsLeft[nLeft-1]};
        cout << end.first << ' ' << end.second << '\n';
        
        if(nCases){
            cout << '\n';
        }
    }
}