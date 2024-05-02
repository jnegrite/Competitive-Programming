#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    int bars[20] {};
    while(nCases--){
        int target;
        int nBars;
        scanf("%d\n%d\n",&target,&nBars);
        for(int i=0;i<nBars;i++){
            scanf("%d",&bars[i]);
        }
        sort(bars,bars+nBars);

        int rem {target};
        int minBars{0};
        while(rem > 0 && minBars < nBars){
            minBars++;
            rem -= bars[nBars-minBars];
        }

        rem = target;
        int maxBars{0};
        while(rem > 0 && maxBars < nBars){
            rem -= bars[maxBars++];
        }
        
        bool ansFound {false};
        for(int usedBars=minBars;!ansFound && usedBars<=maxBars;usedBars++){
            int perm[20] {};
            for(int i=usedBars;i<nBars;i++){
                perm[i] = 1;
            }
            
            do{
                int temp {0};
                for(int i=0;i<nBars;i++){
                    if(perm[i] == 0){
                        temp += bars[i];
                    }
                }
                if(temp == target){
                    ansFound = true;
                }
            } while(!ansFound && next_permutation(perm,perm+nBars));
        }

        printf(ansFound?"YES\n":"NO\n");
    }
}