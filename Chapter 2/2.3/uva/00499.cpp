#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        long charCounts[52] {};
        int pos {};
        long maxVal {0};
        for(char ch:s){
            if(ch >= 'A' && ch <= 'Z'){
                pos = ch-'A';
                maxVal = max(maxVal,++charCounts[pos]);
            } else if (ch >= 'a' && ch <= 'z'){
                pos = ch-'a' + 26;
                maxVal = max(maxVal,++charCounts[pos]);
            }
        }

        //get max
        for(int i=0;i<26;i++){
            if(charCounts[i] == maxVal){
                cout << static_cast<char>('A' + i);
            }
        }
        for(int i=0;i<26;i++){
            if(charCounts[26+i] == maxVal){
                cout << static_cast<char>('a' + i);
            }
        }
        cout << ' ' << maxVal << '\n';
    }
}