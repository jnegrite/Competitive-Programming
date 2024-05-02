#include<iostream>

using namespace std;

int main(){
    long nValues {};

    cin >> nValues;

    int decoder[256]{};
    
    for(int i=0;;i++){
        auto hash {(i^(i<<1))%256};

        decoder[hash] = i;

        if(i==255){
            break;
        }
    }
    int curr;

    cin >> curr;
    cout << ' ' << decoder[curr];

    for(long i=1;i<nValues;i++){
        cin >> curr;
        cout << ' ' << decoder[curr];
    }
    cout << '\n';
}