#include<iostream>
#include<cstring>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

long long nCurr;
unordered_map<string,long long> mapCurr{};
long long dist[200][200][2] {};

void reduce(long long &v1, long long &v2){
    long long low {v1};
    long long high {v2};
    long long temp;
    if(low > high){
        swap(low,high);
    }

    while(low > 0){
        temp = high % low;
        high = low;
        low = temp;
    }
    if(high>0){
        v1 /= high;
        v2 /= high;
    }
}

pair<long long, long long> getCross(long long i, long long j, long long k){
    const auto &p1 {dist[i][k]};
    const auto &p2 {dist[k][j]};

    long long num = p1[0] * p2[0];
    long long denom = p1[1] * p2[1];

    reduce(num, denom);
    return {num, denom};
}

int main(){
    while(cin >> nCurr, nCurr!=0){
        mapCurr.clear();
        memset(dist,0,sizeof(dist));
        for(long long i=0;i<nCurr;i++){
            dist[i][i][0] = dist[i][i][1] = 1;
        }

        string s;
        for(long long i=0;i<nCurr;i++){
            cin >> s;
            mapCurr[s] = i;
        }

        long long nConversions;
        string sFrom, sTo;
        long long v1, v2;
        long long idFrom, idTo;

        cin >> nConversions;
        while(nConversions--){
            cin >> sFrom >> sTo >> s;
            auto pos {s.find(':')};
            v2 = stoi(s.substr(0,pos));
            v1 = stoi(s.substr(pos+1));
            idFrom = mapCurr[sFrom];
            idTo = mapCurr[sTo];

            auto &curr {dist[idFrom][idTo]};
            
            if(curr[0] == 0 ||
                ((v1*curr[1]) > (curr[0] * v2))){
                dist[idFrom][idTo][0] = v1;
                dist[idFrom][idTo][1] = v2;
            }
            
        }
        //do algo
        for(long long k=0;k<nCurr;k++){
            for(long long i=0;i<nCurr;i++){
                if(dist[i][k][0] == 0) continue;
                
                for(long long j=0;j<nCurr;j++){
                    if(dist[k][j][0] == 0) continue;

                    auto temp {getCross(i,j,k)};
                    long long n1 {temp.first};
                    long long d1 {temp.second};

                    reduce(n1,d1);

                    bool update {dist[i][j][0] == 0 || 
                        ((n1 * dist[i][j][1]) > (d1 * dist[i][j][0]))};

                    if(update){
                        dist[i][j][0] = n1;
                        dist[i][j][1] = d1;
                    }
                
                }
            }
        }

        //check arbitrage
        bool hasArbitrage {false};
        for(long long i=0;!hasArbitrage && i<nCurr;i++){
            if(dist[i][i][0] > dist[i][i][1]){
                hasArbitrage = true;
            }
        }
         
        cout << (hasArbitrage ? "Arbitrage" : "Ok") << '\n';
    }
}