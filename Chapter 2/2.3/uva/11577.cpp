#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main(){
    long numCases;
    string s;
    cin >> numCases;
    while(numCases--){
        long charCounts[26] {};
        getline(cin >> ws,s);

        for(char ch:s){
            if(ch >= 'a' && ch <='z'){
                charCounts[ch-'a']++;
            } else if (ch >= 'A' && ch <= 'Z'){
                charCounts[ch-'A']++;
            }
        }

        long maxCount {0};
        for(int i=0;i<26;i++){
            maxCount = max(maxCount,charCounts[i]);
        }
        for(int i=0;i<26;i++){
            if(charCounts[i] == maxCount){
                cout << static_cast<char>('a' + i);
            }
        }
        cout << '\n';
    }
}