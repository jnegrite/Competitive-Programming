#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

long pegs[50] {};
int usedPegs;
long maxBall{};

bool isPerfectSquare(long num){
    long root {floor(sqrt(num))};
    return root * root == num;
}

void backtrack(long ball) {
    maxBall = max(maxBall, ball-1);

    for(int peg=0;peg<usedPegs;peg++){
        if(pegs[peg] == 0 || isPerfectSquare(pegs[peg]+ball)){
            long prevVal = pegs[peg];
            pegs[peg] = ball;
            backtrack(ball+1);
            pegs[peg] = prevVal;
        }

        if(pegs[peg] == 0){
            break;
        }
    }
}


int main(){
    for(usedPegs=1;usedPegs<=50;usedPegs++){

        //clear the towers
        for(int i=0;i<usedPegs;i++){
            pegs[i] = 0;
        }
        maxBall = 0;

        backtrack(1);
        cout << '{' << usedPegs << ',' << maxBall << "}," << endl;
    }
}