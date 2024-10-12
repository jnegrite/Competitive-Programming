#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    int baseNum, rem;
    int numer, denom;
    while(cin >> n){
        baseNum = static_cast<int>(((-1 + sqrt(1+ 8*n))/2));
        rem = n-((baseNum * (baseNum+1))>>1);

        if(rem==0){
            if(baseNum%2==0){
                numer=baseNum;
                denom=1;
            } else {
                numer=1;
                denom=baseNum;
            }
        } else {
            int nxtSum = baseNum+2;
            if(baseNum%2){
                numer=rem;
                denom=nxtSum-rem;
            } else {
            denom = rem;
            numer = nxtSum - rem; 
            }
        }
        cout << "TERM " << n << " IS " << numer << '/' << denom << '\n';
    }
}