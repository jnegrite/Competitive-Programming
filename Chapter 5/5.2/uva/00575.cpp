#include<iostream>

using namespace std;

int main(){
    string s;
    while(cin >> s, s != "0"){
        int len = s.length();
        unsigned int currPower {2u};

        unsigned int ans {0};
        for(int pos=len-1;pos>=0;--pos, (currPower<<=1)){
            ans += static_cast<unsigned>(s.at(pos)-'0') * (currPower-1u);
        }
        cout << ans << '\n';
    }
}