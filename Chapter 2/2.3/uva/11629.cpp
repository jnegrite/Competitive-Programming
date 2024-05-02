#include<iostream>
#include<unordered_map>
#include<string>
#include<sstream>

using namespace std;

int main(){
    int numParties;
    long numGuesses;
    string s, s2;
    long value;
    int decimal;

    cin >> numParties >> numGuesses;
    
    unordered_map<string, long> parties {};
    while(numParties--){
        cin >> s >> s2;
        value = 10 * stol(s2.substr(0, s2.length()-2)) + stol(s2.substr(s2.length()-1));
        parties[s] = value;
    }

    for(long guess=1;guess<=numGuesses;guess++){
        getline(cin>>ws, s);
        long left {0};
        long right;
        auto strIn {stringstream(s)};
        string sub;
        string comp;

        strIn >> ws >> sub;
        left = parties[sub];
        while(true){
            strIn >> comp >> sub;
            if(comp == "+"){
                left += parties[sub];
            } else {
                right = stol(sub);
                right *= 10;
                break;
            }
        }

        bool isCorrect {false};

        if(comp == "<" && left < right){
            isCorrect = true;
        } else if (comp==">" && left > right){
            isCorrect = true;
        } else if (comp=="<=" && left <= right){
            isCorrect = true;
        } else if (comp==">=" && left >= right){
            isCorrect = true;
        } else if (comp=="=" && left == right){
            isCorrect = true;
        }

        cout << "Guess #" << guess << " was " << (isCorrect ? "correct" : "incorrect") << ".\n";

    }
}

