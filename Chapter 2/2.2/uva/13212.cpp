#include<cstdio>

using namespace std;


long inversions {};
const long arrSize {1000000};
long numbers[arrSize] {};
long holder[arrSize] {};

void mergeSort(long from, long to){
    if(from==to){
        return;
    }

    long mid {(from + to)>>1};
    mergeSort(from, mid);
    mergeSort(mid+1,to);

    //actual merging;
    long idxLeft {from};
    long idxRight {mid+1};

    for(long i=0;i<=to-from;i++){
        if(idxLeft <= mid && (idxRight > to || numbers[idxLeft] < numbers[idxRight])){
            holder[i] = numbers[idxLeft++];
        } else {
            holder[i] = numbers[idxRight++];
            inversions += (mid+1 - idxLeft);
        }
    }

    for(long i=0;i<=to-from;i++){
        numbers[from+i] = holder[i];
    }
}

int main(){
    long numItems {};
    while(scanf("%ld\n",&numItems), numItems>0){
        for(long i=0;i<numItems;i++){
            scanf("%ld\n",&numbers[i]);
        }

        inversions = 0;
        mergeSort(0,numItems-1);

        printf("%ld\n",inversions);

    }
}