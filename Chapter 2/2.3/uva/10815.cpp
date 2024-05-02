#include<iostream>
#include<set>
#include<string>

using namespace std;

int main(){
    string s;
    set<string> words {};
    string currWord {};

    while(getline(cin,s)){
        for(char ch:s){
            if(isalpha(ch)){
                currWord += tolower(ch);
            } else if (currWord.length() != 0){
                if(words.count(currWord)==0){
                    words.emplace(currWord);
                }
                currWord = "";        
            }
        }

        if (currWord.length() != 0){
            if(words.count(currWord)==0){
                words.emplace(currWord);
            }
            currWord = "";        
        }
    }

    for(auto it = words.begin();it!= words.end();it++){
        cout << *it << '\n';
    }
}