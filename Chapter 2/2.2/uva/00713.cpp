#include<iostream>

using namespace std;

int main(){
    string s1, s2;
    int numCases;
    int sum;
    cin >> numCases;
    while(numCases--){
        cin >> s1 >> s2;
        int maxLen {max(s1.length(), s2.length())};
        sum = 0;
        bool leading{true};
        for(int i=0;sum > 0 || i<maxLen;i++){
            if(i<s1.length()){
                sum += (s1.at(i) - '0');
            }
            if(i<s2.length()){
                sum += (s2.at(i) - '0');
            }

            if(sum%10 > 0){
                leading = false;
            }
            
            if(!leading){
                cout << sum % 10;
            }
            sum /= 10;
        }
        cout << '\n';
    }
}