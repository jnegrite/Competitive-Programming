#include<iostream>

using namespace std;

int main(){
    int nCases;
    cin >> nCases;

    while(nCases--){
        long nFriends;
        long nBoxes;

        long ans {0};

        cin >> nFriends >> nBoxes;
        while(nBoxes--){
            long nParts;
            cin >> nParts;
            long curr {1};
            long val;
            while(nParts--){
                cin >> val;
                val %= nFriends;
                curr *= val;
                curr %= nFriends;
            }
            ans += curr;
            ans %= nFriends;
        }
        cout << ans << '\n';
    }
}