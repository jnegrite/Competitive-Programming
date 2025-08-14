#include<cstdio>

using namespace std;

int main(){
    int val;

    long nCases {0};
    while(scanf("%d\n",&val),val!=0){
        printf("Case %ld: %d\n",++nCases,(val>>1));
    }
}