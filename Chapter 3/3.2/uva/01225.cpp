#include<iostream>

using namespace std;

long counts[10] {};


void reset(){
    for(int i=0;i<10;i++){
        counts[i] = 0;
    }
}

void encode(int n){
    while(n>0){
        counts[n%10]++;
        n/=10;
    }
}

int main(){
    int numValues;

    int val;
    cin >> numValues;
    while(numValues--){
        cin >> val;
        reset();
        for(int i=0;i<=val;i++){
            encode(i);
        }

        cout << counts[0];
        for(int i=1;i<10;i++){
            cout << ' ' << counts[i];
        }
        cout << '\n';
    }
}