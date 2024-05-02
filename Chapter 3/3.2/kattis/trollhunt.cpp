#include<iostream>

using namespace std;

int main(){
    int b, k, g;

    cin >> b >> k >> g;

    --b;
    int numGroups {k/g};
    int ans{b/numGroups};
    if(b%numGroups){
        ++ans;
    }
    cout << ans << '\n';
}