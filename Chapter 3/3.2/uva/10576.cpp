#include<iostream>

using namespace std;

long s, d;
long maxSurplus {-1};

const int maxNum {(1<<12)};
const int mask {(1<<5)-1};

void testConfig(){
    for(int i=0;i<maxNum;i++){
        
        //check every month if not deficit
        bool okConfig {true};
        for(int j=0;okConfig &&j<8;j++){
            int nS {__builtin_popcount((i>>j) & mask)};
            int nD {5-nS};
            
            if(s*nS - d*nD >= 0){
                okConfig = false;
            }
        }

        if(!okConfig){
            continue;
        }

        int monthsS{__builtin_popcount(i)};

        maxSurplus = max(maxSurplus, s*monthsS - d*(12-monthsS));
    }
}

int main(){
    while(cin >> s >> d){
        maxSurplus = -1;
        testConfig();

        if(maxSurplus < 0){
            cout << "Deficit\n";
        } else {
            cout << maxSurplus << '\n';
        }
    }
}