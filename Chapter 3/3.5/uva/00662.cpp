#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;
int memo[202][202][31] {};
int memoStation[202][202] {};
int n, k;
int idDepot {};
int locations[201] {};


int dp(int idxFrom, int idxTo, int nStations){
    auto &curr {memo[idxFrom][idxTo][nStations]};

    if(curr != -1){
        return curr;
    }

    //if nStations is 1, compute
    if(nStations == 1){
        curr = 0;
        //compute base case
        int basis {locations[idxFrom]};
        for(int j=idxFrom; j<=idxTo;++j){
            curr += abs(locations[j] - basis);
        }
        memoStation[idxFrom][idxTo] = idxFrom;
        for(int i=idxFrom+1;i<=idxTo;i++){
            int temp {};
            basis = locations[i];
            for(int j=idxFrom; j<=idxTo;++j){
                temp += abs(locations[j] - basis);
            }
            if(temp < curr){
                curr = temp;
                memoStation[idxFrom][idxTo] = i;
            }
        }
    } else {
        //set base case 
        curr = dp(idxFrom, idxFrom, 1) + dp(idxFrom+1,idxTo,nStations-1);

        for(int ub {idxFrom +1}; ub + nStations <= idxTo + 1; ++ub){
            curr = min(curr, dp(idxFrom, ub, 1) + dp(ub+1,idxTo,nStations-1));
        }

    }
    return curr;
}

void traceBack(int idxFrom, int idxTo, int nStations){
    if(nStations == 1){
        printf("Depot %d at restaurant %d serves ",++idDepot, memoStation[idxFrom][idxTo]);
        if(idxFrom == idxTo){
            printf("restaurant %d\n",idxFrom);
        } else {
            printf("restaurants %d to %d\n",idxFrom, idxTo);
        }
    } else {
        for(int ub {idxFrom}; ub + nStations <= idxTo + 1; ++ub){
            if(dp(idxFrom, idxTo, nStations) == dp(idxFrom, ub, 1) + dp(ub+1,idxTo,nStations-1)){
                traceBack(idxFrom,ub,1);
                traceBack(ub+1,idxTo,nStations-1);
                break;
            }
        }
    }
}

int main(){
    int tc{};
    while(scanf("%d %d\n",&n,&k), n> 0 || k > 0){
        for(int i=1;i<=n;++i){
            scanf("%d\n",&locations[i]);
        }

        //do dp
        memset(memo,-1,sizeof(memo));
        memset(memoStation,-1,sizeof(memoStation));
        int minDist {dp(1,n,k)};
        
        printf("Chain %d\n",++tc);
        idDepot = 0;
        traceBack(1,n,k);
        printf("Total distance sum = %d\n\n",minDist);
    }
}