#include<iostream>
#include<malloc.h>

using namespace std;

int main(){
    long n, r;
    long curr;
    while(cin >> n >> r){
        bool *didReturn = (bool*)calloc(n+1,sizeof(bool));
        for(long i=0;i<r;i++){
            cin >> curr;
            didReturn[curr] = true;
        }

        bool allReturned{true};
        for(int i=1;i<=n;i++){
            if(!didReturn[i]){
                allReturned = false;
                cout << i << ' ';
            }
        }

        if(allReturned){
            cout << "*\n";
        } else {
            cout << '\n';
        }

        free(didReturn);
    }
}