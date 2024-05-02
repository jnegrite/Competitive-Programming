#include<iostream>
#include<string>

using namespace std;

int main(){
    //preprocess
    string seed[6] {
        "BFPV",
        "CGJKQSXZ",
        "DT",
        "L",
        "MN",
        "R",
    };

    char codes[26] {};
    string s;
    for(int i=0;i<6;i++){
        s = seed[i];
        char value {'1' + i};
        for(char ch:s){
            codes[ch-'A'] = value;
        }
    }

    while(getline(cin,s)){
        char prev {'\0'};
        for(char ch:s){
            char temp {codes[ch - 'A']};
            if(prev != temp){
                if(temp!='\0'){
                    cout << temp;
                }
            }
            prev = temp;
        }
        cout << '\n';
    }
}