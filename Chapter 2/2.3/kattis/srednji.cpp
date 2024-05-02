#include<cstdio>
#include<map>
#include<malloc.h>

using namespace std;

int main(){
    long nNumbers;
    long nMedian;
    long medianPos;

    scanf("%ld %ld\n",&nNumbers,&nMedian);
    long curr;
    long *values {(long*)malloc(nNumbers * sizeof(long))};

    for(int i=0;i<nNumbers;i++){
        scanf("%ld",&curr);
        if(curr < nMedian){
            values[i] = -1;
        } else if (curr > nMedian){
            values[i] = 1;
        } else {
            values[i] = 0;
            medianPos = i;
        }
    }

    //consolidate per partial sum
    //left sums
    map<long,pair<long,long>> counts {};
    counts[0] = {0,0};
    long subTotal {0};
    for(long i=medianPos-1;i>=0;i--){
        subTotal += values[i];
        
        pair<long,long> temp {0,0};

        if(counts.count(subTotal) > 0){
            temp = counts[subTotal];
        }
        temp.first++;
        counts[subTotal] = temp;
    }

    //right sums
    subTotal = 0;
    for(long i=medianPos+1;i<nNumbers;i++){
        subTotal += values[i];
        
        pair<long,long> temp {0,0};

        if(counts.count(subTotal) > 0){
            temp = counts[subTotal];
        }
        temp.second++;
        counts[subTotal] = temp;
    }
    free(values);

    //check for 0
    long ans;
    auto temp {counts[0]};
    ans = (temp.first + 1) * (temp.second + 1);

    //iterate through all other values
    auto itFront {counts.begin()};
    auto itBack {--counts.end()};

    while(itFront != itBack){
        long diff {itFront->first + itBack->first};
        if(diff==0){
            ans += itFront->second.first * itBack->second.second;
            ans += itFront->second.second * itBack->second.first;

            itFront++;
            itBack--;
        } else if (diff < 0){
            itFront++;
        } else {
            itBack--;
        }
    }
    printf("%ld\n",ans);
}