#include<iostream>
#include<malloc.h>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    long pos1 {s1.length()-1};
    long pos2 {s2.length()-1};
    int ans[10001] {};
    long posAns {0};
    int carry {0};
    int partialSum {0};
    
    while(pos1 >= 0 || pos2 >= 0 || carry > 0){
        partialSum = carry;

        if(pos1 >= 0){
            partialSum += (s1.at(pos1--) - '0');
        }

        if(pos2 >= 0){
            partialSum += (s2.at(pos2--) - '0');
        }

        ans[posAns++] = partialSum%10;
        carry = partialSum/10;
    }

    for(int i=posAns-1;i>=0;i--){
        cout << ans[i];
    }
    cout << '\n';
}