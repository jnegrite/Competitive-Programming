#include<iostream>
#include<string>

using namespace std;

string vowels {"aeiouy"};

int main(){
    string s;

    while(getline(cin,s)){
        string word {};

        while(s.length() > 0){
            long pos {s.find(' ')};
            char terminator {};

            if(pos == -1){
                terminator = '\n';
                word = s;
                s = "";
            } else {
                terminator = ' ';  
                word = s.substr(0, pos);
                s = s.substr(pos + 1);
            }

            if(vowels.find(word.at(0)) == -1){
                long pos = word.length();

                for(char ch: vowels){
                    long p = word.find(ch);
                    if(p!=-1 && p < pos){
                        pos = p;
                    }
                }
                
                cout << word.substr(pos) << word.substr(0,pos) << "ay" << terminator;

            } else {
                cout << word << "yay" << terminator;
            }
        }

    }
}