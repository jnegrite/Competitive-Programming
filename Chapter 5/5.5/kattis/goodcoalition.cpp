#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

int nParties;
int partyMembers[150] {};
double partyProb[150] {};
int value;

double memo[151][76] {};
bool visited[151][76] {};

double dp(int pos, int remSeats){
    if(remSeats <= 0){
        return 1;
    }
    if(pos == nParties){
        return 0;
    }

    double &ans {memo[pos][remSeats]};
    bool &isVisited {visited[pos][remSeats]};

    if(isVisited){
        return ans;
    }

    isVisited = true;
    ans = max(dp(pos+1, remSeats),dp(pos+1,remSeats-partyMembers[pos])*partyProb[pos]);

    return ans;
}

int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        //ingest input
        cin >> nParties;

        memset(memo,0,sizeof(memo));
        memset(visited,false,sizeof(visited));

        for(int i=0;i<nParties;++i){
            cin >> partyMembers[i] >> value;
            partyProb[i] = value/100.0;
        }

        cout << fixed << setprecision(6) << dp(0,76)*100 << '\n';
    }
}