#include<cstdio>
#include<malloc.h>
#include<algorithm>

long *p;
long *rank;

long getParent(long i){
    return p[i]==i ? i : p[i]=getParent(p[i]);
}

int main(){
    long N, Q;
    scanf("%ld %ld\n",&N,&Q);
    char op;
    long a, b;
    p = (long*)malloc(N*sizeof(long));
    rank = (long*)calloc(N,sizeof(long));
    for(long i=0;i<N;i++){
        p[i] = i;
    }
    while(Q--){
        scanf("%c %ld %ld\n",&op,&a,&b);
        long p1 = getParent(a);
        long p2 = getParent(b);
        if(op == '?'){
            if(p1 == p2){
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else {
            if(rank[p1] < rank[p2]){
                std::swap(a,b);
            }
            p[p[b]] = p[p[a]];
            if(rank[p1] == rank[p2]){
                rank[p[a]]++;
            }
        }
    }

    free(p);
    free(rank);
}

