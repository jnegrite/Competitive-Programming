#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int nCases;
    cin >> nCases;
    int minDist;
    int maxDist;
    long l, nAnts;
    long d1, d2;
    while(nCases--){
        cin >> l >> nAnts;
        cin >> minDist;
        maxDist = l-minDist;

        if(minDist > maxDist){
            swap(minDist,maxDist);
        }
        while(--nAnts){
            cin >> d1;
            d2 = l-d1;
            if(d1>d2){
                swap(d1,d2);
            }

            if(d1 > minDist){
                minDist = d1;
            }

            if(d2 > maxDist){
                maxDist = d2;
            }
        }
        cout << minDist << ' ' << maxDist << '\n';
    }
}