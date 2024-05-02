#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

int main(){
    long maxDist {0};
    long left {-1};
    long minDepth{-1};
    long right {-1};
    long nMountains;
    long curr;

    scanf("%ld",&nMountains);
    for(long i=0;i<nMountains;i++){
        scanf("%ld",&curr);

        if(left==-1){
            //case for leftmost
            left = curr;
        } else if (curr >= left){
            //this one is higher than the leftmost

            if(minDepth == -1){
                left = curr;
            } else {
                //evaluate if right is higher
                maxDist = max(maxDist,left-minDepth);
                left = curr;
                minDepth = -1;
            }
        } else {
            //if curr < left
            if(minDepth == -1){
                minDepth = curr;
            } else if(curr < minDepth){
                minDepth = curr;
            } else if (curr > minDepth){
                maxDist = max(maxDist,curr-minDepth);
            }
        }
    }
    cout << maxDist << '\n';
}