#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s {};
    string currWord {};
    int currValue {};

    vector<string> words {};

    while(getline(cin,s)){
        if(s == "0"){
            break;
        }
        
        s += '\n';

        for(char ch:s){
            if (isalpha(ch)){
                currWord += ch;
                cout << ch;
            } else if (isdigit(ch)){
                currValue *= 10;
                currValue += (ch - '0');            
            } else {


                if(currWord.length() > 0){
                    words.push_back(currWord);
                } else if (currValue > 0){
                    int idx = words.size()-currValue;
                    string wrd = words[idx];
                    cout << wrd;
                    words.erase(words.begin()+idx);
                    words.push_back(wrd);
                }

                currWord = "";
                currValue = 0;

                cout << ch;
            }
        }
    }
}