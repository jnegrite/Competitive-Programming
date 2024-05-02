#include<iostream>
#include<stack>

using namespace std;

int main(){
    long numSocks {};
    cin >> numSocks;
    numSocks <<= 1;
    long curr;
    stack<long> socks {};

    for(long i=0;i<numSocks;i++){
        cin >> curr;
        if(!socks.empty() && (socks.top() == curr)){
            socks.pop();
        } else {
            socks.emplace(curr);
        }
    }

    if(socks.empty()){
        cout << numSocks << '\n';
    } else {
        cout << "impossible\n";
    }
}