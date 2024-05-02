#include<cstdio>
#include<cstring>

using namespace std;

char cards[99][99] {};
int nextCards[99] {};
int numCards {};
int currPos {};
int prevPos {};

int main(){
    while(true){
        scanf("%d",&numCards);

        if(numCards==0){
            break;
        }

        for(int i=0;i<numCards-1;i++){
            nextCards[i] = i+1;
        }
        nextCards[numCards-1] = 0;

        currPos = numCards-1;
        prevPos = currPos;
        char code[99] {}, word[99] {};

        for(int i=0;i<numCards;i++){
            scanf("%s %s",code, word);
            int len = strlen(word);
            for(int j=0;j<len;j++){
                prevPos = currPos;
                currPos = nextCards[currPos];
            }
            strcpy(cards[currPos],code);
            nextCards[prevPos] = nextCards[currPos];
        }

        printf("%s",cards[0]);
        for(int i=1;i<numCards;i++){
            printf(" %s",cards[i]);
        }
        printf("\n");
    }
}