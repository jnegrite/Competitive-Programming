#include<cstdio>
#include<cmath>
using namespace std;

double sides[30] {};
long counts[30] {};
long addedTapes[30] {};
int maxN;
double tapeUsed {};


bool create(int pos,long qty){
    if(pos+1 >= maxN){
        return false;
    }

    long actualQty {qty<<1};

    if(counts[pos+1] < actualQty){
        int needed {actualQty-counts[pos+1]};
        if(!create(pos+1,needed)){
            return false;
        }
    }

    //if has enough from next
    if(counts[pos+1] >= actualQty){
        counts[pos+1] -= actualQty;
        addedTapes[pos+1] += qty;
        counts[pos] += qty;
        return true;
    }

    return false;
}

int main(){
    sides[1] = exp2(-3.0/4.0);
    sides[2] = exp2(-5.0/4.0);
    
    scanf("%d\n",&maxN);
    //initialize sides measurement
    for(int i=3;i<maxN;i++){
        sides[i] = sides[i-2]/2.0;
    }
    
    //get data
    for(int i=1;i<maxN;i++){
        scanf("%ld",&counts[i]);
    }

    //simulate
    create(0,1);

    if(counts[0] == 1){
        for(int i=1;i<maxN;i++){
            tapeUsed += addedTapes[i] * sides[i];
        }
        printf("%.07lf\n",tapeUsed);
    } else {
        printf("impossible\n");
    }
}