#include<iostream>
#include<bitset>
#define N 1000
using namespace std;
int n,c;
int main(){
    cin>>n;
    bitset<2001>m{1};
    for(int i=0;!m.test(N) && i<n;++i){
        cin >> c;
        m |= (m<<c);
    }
    for(int i=0;i<=2000;++i){
        if(m.test(N+i)){
            cout<<(N+i)<<'\n';
            break;
        }
        if(m.test(N-i)){
            cout<<(N-i)<<'\n';
            break;
        }
    }
}