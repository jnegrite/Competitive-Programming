#include<cstdio>
#include<set>
#include<malloc.h>

using namespace std;

int main(){
    long numItems;
    scanf("%ld\n",&numItems);

    long *arr = (long*)malloc((numItems+1)*sizeof(long));
    long curr;
    set<long> seenVals {};
    long totalDepth {};
    long depth;
    set<long>::iterator it;

    while(numItems--){
        scanf("%ld\n",&curr);
        depth = 0;

        it = seenVals.upper_bound(curr);
        if(it != seenVals.end()){
            depth = max(depth, arr[*it] + 1);
        }

        if(it != seenVals.begin()){
            it--;
            depth = max(depth, arr[*it] + 1);
        }

        seenVals.emplace(curr);
        arr[curr] = depth;

        totalDepth += depth;
        printf("%ld\n",totalDepth);
    }

    free(arr);
}