#include<iostream>

using namespace std;

long long H(long long previousHash, string &transaction,
            long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

int main(){
    long long prevHash {};
    string text {"a"};
    cin >> prevHash;
    
    for(int i=0;i<2;i++){
        long long rawHash {H(prevHash,text,0)};
        long long targetHash {(1+(rawHash/10000000)) * 10000000};
        prevHash = targetHash;
        cout << text << ' ' << (targetHash - rawHash) << '\n';
    }
}