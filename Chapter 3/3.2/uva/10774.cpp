#include<cstdio>

using namespace std;

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    for(int tc=1;tc<=nCases;tc++){
        
        long nParticipants {};
        scanf("%ld\n",&nParticipants);
        long mask {1};
        while(mask <= nParticipants){
            mask <<= 1;
        }
        int reps{0};
        while(true){
            reps++;
            long temp {nParticipants};
            while(mask > temp){
                mask >>= 1;
            }

            temp ^= mask;
            temp <<= 1;
            temp++;

            if(nParticipants==temp){
                break;
            } else {
                nParticipants=temp;
            }
        }
        


        printf("Case %d: %d %ld\n",tc,reps-1,nParticipants);
    }
}