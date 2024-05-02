#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

long currIdx {0};
vector<string> a {""};
vector<string> b {};
vector<string> *mainVector {&a};
vector<string> *holder {&b};
unordered_map<string,long> idx {};

int main(){

    string s;
    //preprocess
    while(true){
        holder->clear();

        if(mainVector->size() == 0){
            break;
        }

        for(string s: *mainVector){
            if(s.length() == 0){
                for(char ch='a';ch <= 'z'; ch++){
                    string temp {s + ch};
                    idx[temp] = ++currIdx;
                    holder->push_back(temp);
                }
            } else {
                for(char ch=s.at(s.length() - 1)+1;ch<='z';ch++){
                    string temp {s + ch};
                    idx[temp] = ++currIdx;
                    if(s.length() <= 5){
                        holder->push_back(temp);
                    }
                }
            }
        }
        vector<string> *temp = mainVector;
        mainVector = holder;
        holder = temp;
    }

    //actual queries
    while(getline(cin,s)){
        if(idx.count(s) == 0){
            cout << "0\n";
        } else {
            cout << idx[s] << '\n';
        }
    }
}