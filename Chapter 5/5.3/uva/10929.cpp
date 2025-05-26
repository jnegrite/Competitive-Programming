#include<iostream>

using namespace std;

int main(){
    string s;
    while(true){
        cin >> s;
        if(s.length() == 1 && s.at(0)=='0'){
            break;
        }

        int digits[1000] {};

        for(int i=0;i<s.length();++i){
            digits[i] = s.at(i) - '0';
        }

        int val {0};
        for(int i=s.length()-1;i>0;--i){
            //borrow if less then -1
            if(digits[i] < val){
                digits[i] += 10;
                digits[i-1] -= 1;
            }

            val = digits[i] - val;
        }

        cout << s << " is ";
        if(val != digits[0]){
            cout << "not ";
        }

        cout << "a multiple of 11.\n";
    }
}