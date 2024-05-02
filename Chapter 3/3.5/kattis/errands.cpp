#include<iostream>
#include<cstring>
#include<sstream>
#include<unordered_map>
#include<stack>
#include<cmath>

#define INF 1e9
#define LSOne(x) ((x) & -(x))

using namespace std;

double distances[100][100] {};
double memo[12][1<<12] {};
string locations[100] {};
unordered_map<string,int> locationsMap {};
double coords[100][2] {};
int middleWare[12] {};

int idHome;
int idWork;
int nLocations;
int nLocsToday;
string s;
stack<int> bestPath {};

double dp(int pos, int mask){
    if(mask==0){
        return distances[middleWare[pos]][idHome];
    }

    auto &curr {memo[pos][mask]};

    if(curr > 0){
        return curr;
    }

    curr = INF;

    int tMask {mask};
    while(tMask != 0){
        int flag {LSOne(tMask)};
        int target {__builtin_ctz(flag)};
        curr = min(curr, distances[middleWare[pos]][middleWare[target]] + dp(target, mask ^ flag));
        tMask -= flag;
    }
    return curr;
}

void traceBack(int pos, int mask){
    if(mask==0){
        return;
    }

    double minDist {INF};
    int bestPos {-1};
    int tMask {mask};
    double curr;
    while(tMask != 0){
        int flag {LSOne(tMask)};
        int target {__builtin_ctz(flag)};
        curr = distances[middleWare[pos]][middleWare[target]] + dp(target, mask ^ flag);
        if(curr < minDist){
            bestPos = target;
            minDist = curr;
        }
        tMask -= flag;
    }

    traceBack(bestPos,mask ^ (1<<bestPos));
    bestPath.push(bestPos);
}

int main(){
    //read location data;
    cin >> nLocations;
    for(int i=0;i<nLocations;++i){
        cin >> locations[i] >> coords[i][0] >> coords[i][1];
        locationsMap[locations[i]] = i;

        if(locations[i] == "home"){
            idHome = i;
        } else if (locations[i] == "work"){
            idWork = i;
        }
    }

    //get distances
    for(int i=0;i<nLocations;++i){
        distances[i][i] = 0;
        for(int j=i+1;j<nLocations;++j){
            double dx {abs(coords[i][0] - coords[j][0])};
            double dy {abs(coords[i][1] - coords[j][1])};
            distances[i][j] = distances[j][i] = sqrt(dx*dx + dy*dy);
        }
    }

    cin >> ws;
    while(getline(cin,s),!s.empty()){
        auto strIn {stringstream(s)};
        nLocsToday = 0;
        while(strIn >> s){
            middleWare[nLocsToday++] = locationsMap[s];
        }

        middleWare[nLocsToday] = idWork;

        //now we have list of locations to visit, do dp
        memset(memo,-1,sizeof(memo));
        dp(nLocsToday,(1<<nLocsToday)-1);
        
        while(!bestPath.empty()){
            bestPath.pop();
        }

        traceBack(nLocsToday,(1<<nLocsToday)-1);
        while(!bestPath.empty()){
            cout << locations[middleWare[bestPath.top()]];
            bestPath.pop();
            cout << (bestPath.empty()?'\n':' ');
        }
    }
}