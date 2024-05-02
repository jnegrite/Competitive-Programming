#include<cstdio>
#include<iostream>

using namespace std;

long getCost(long consumption){
    long ans {0};
    ans += 2 * min(100L,consumption);
    if(consumption > 100L){
        ans += 3 * (min(10000L,consumption) - 100L);
        if(consumption > 10000L){
            ans += 5 * (min(1000000L,consumption) - 10000L);

            if(consumption > 1000000L){
                ans += 7 * (consumption-1000000L);
            }
        }
    }
    return ans;
}


int main(){
    long a, b;
    while(scanf("%ld %ld\n",&a, &b),a!=0 || b!=0){
        long low {0};
        long high {512};

        //find the total consumption
        while(a > getCost(high)){
            low = high+1;
            high <<= 1;
        }

        //do BSTA
        long mid;
        while(low <= high){
            mid = (low+high)>>1;
            long cost {getCost(mid)};
            if(a == cost){
                break;
            } else if (a<cost){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        long totalConsumption = mid;
        low = 0;
        high = (totalConsumption)>>1;

        long diff;
        while (low <= high){
            mid = (low+high)>>1; 
            diff = getCost(totalConsumption - mid) - getCost(mid);
            
            if(diff==b){
                break;
            } else if (diff > b){
                low = mid+1;
            } else {
                high = mid-1;
            }

        }

        printf("%ld\n",getCost(mid));
    }
}