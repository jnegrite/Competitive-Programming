#include<cstdio>
#include<cstring>

using namespace std;

long long factorials[21] {};
char inputStr[21] {};
char finPosition[21] {};

void initFactorials(){
    factorials[0] = 1;
    for(int i=1;i<=20;++i){
        factorials[i] = factorials[i-1] * i;
    }
}

void setAtPosition(char ch, int pos){
    int currPos {0};
    while(true){
        if(finPosition[currPos] == '\0'){
            if(pos-- == 0){
                finPosition[currPos] = ch;
                return;
            }
        }
        ++currPos;
    }
}

int main(){
    initFactorials();

    int nCases {};
    scanf("%d\n", &nCases);

    for(int tc=1;tc<=nCases;++tc){
        long long inputIdx {};
        scanf("%s %ld",&inputStr, &inputIdx);
        memset(finPosition,'\0',sizeof(finPosition));

        int numChars {strlen(inputStr)};

        long long currVal {--inputIdx};
        for(int i=0;i<numChars; ++i){
            long long divisor {factorials[numChars-i-1]};
            long long q {currVal / divisor};

            setAtPosition(inputStr[i], q);
            currVal %= divisor;
        }

        printf("Case %d: %s\n",tc,finPosition);
    }
}