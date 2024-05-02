#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    long numCases;
    string s;
    getline(cin,s);
    numCases = stol(s);
    while(numCases--){
        getline(cin,s);
        bool isOk{true};
        stack<char> brackets {};
        for(char ch: s){
            switch(ch){
                case '(':
                case '[':
                    brackets.emplace(ch);
                    break;
                case ')':
                    if(!brackets.empty() && brackets.top() == '('){
                        brackets.pop();
                    } else {
                        isOk = false;
                    }
                    break;
                case ']':
                    if(!brackets.empty() && brackets.top() == '['){
                        brackets.pop();
                    } else {
                        isOk = false;
                    }
                    break;
            }
            if(!isOk){
                break;
            }
        }

        if(isOk && brackets.empty()){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

}