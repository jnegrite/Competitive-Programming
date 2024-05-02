#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<long> producers {};
vector<long> consumers {};
long nProducers;
long nConsumers;


void getInput(vector<long> &target){
    long curr;
    scanf("%ld",&curr);
    target.push_back(curr);
}

long getPriceProducers(long nAngry){
    if(nAngry==nProducers){
        return 0;
    } else if(nAngry==0){
        return producers[nProducers-1];
    } else {
        return producers[nProducers - nAngry -1];
    }
}

long getPriceConsumers(long nAngry){
    if(nAngry==nConsumers){
        return 2000000000L;
    } else if(nAngry==0){
        return consumers[0]; 
    } else {
        return consumers[nAngry];
    }
}

long testMaxAngry(long &nAngry){
    long maxProducers = min(nProducers,nAngry);
    long maxConsumers = min(nConsumers,nAngry);

    for(long cntProducers=maxProducers, cntConsumers=nAngry-maxProducers;
            cntConsumers <= maxConsumers;
            cntProducers--,cntConsumers++){

        long p1 {getPriceProducers(cntProducers)};
        long p2 {getPriceConsumers(cntConsumers)};
        if(p1 <= p2){
            return p1;
        }
    }
    return -1L;
}

int main(){
    long nCases;
    scanf("%ld\n",&nCases);
    long price;
    while(nCases--){
        scanf("%ld %ld\n",&nProducers,&nConsumers);
        producers.clear();
        consumers.clear();
        producers.reserve(nProducers);
        consumers.reserve(nConsumers);
    
        long curr;
        for(long i=0;i<nProducers;i++){
            getInput(producers);
        }

        for(long i=0;i<nConsumers;i++){
            getInput(consumers);
        }

        sort(producers.begin(),producers.end());
        sort(consumers.begin(),consumers.end());

        long low {0};
        long high {nProducers + nConsumers};
        long mid;
        long testPrice;
        price = 0;
        while(low<high){
            mid = (low+high)>>1;
            testPrice = testMaxAngry(mid);
            if(testPrice==-1L){
                low=mid+1;
            } else {
                price = testPrice;
                high=mid;
            }
        }
        
        printf("%ld %ld\n",price,low);
    }
}