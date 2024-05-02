#include <iostream>
#include <string>

using namespace std;

string vowels = "aeiouAEIOU";

bool isVowel(char ch){

    return vowels.find(ch) != -1;
}

int main(){
    string s {};
    while(getline(cin,s)){
        string currWord {};
        s += '\n';

        for(char ch: s){
            if(isalpha(ch)){
                currWord += ch;
            } else {
                //process
                if(currWord.length() > 0){
                    if(!isVowel(currWord.at(0))){
                        currWord += currWord.at(0);
                        currWord = currWord.substr(1);
                    }
                    cout << currWord << "ay";
                }

                cout << ch;
                currWord = "";
            }
        }
    }
}