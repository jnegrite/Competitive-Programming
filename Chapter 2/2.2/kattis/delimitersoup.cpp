#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    int numChars;
    string s;
    getline(cin,s);
    numChars = stoi(s);
    int pos {};
    bool isOk {true};
    stack<char> brackets {};

    getline(cin,s);
    while(isOk && pos < numChars){
        char targetChar {};
        switch(s.at(pos)){
            case '(':
            case '[':
            case '{':
                brackets.emplace(s.at(pos));
                break;
            case ')':
                if(s.at(pos) == ')'){
                    targetChar = '(';
                }
            case ']':
                if(s.at(pos) == ']'){
                    targetChar = '[';
                }
            case '}':
                if(s.at(pos) == '}'){
                    targetChar = '{';
                }

                if(brackets.empty() || brackets.top() != targetChar){
                    isOk = false;
                } else {
                    brackets.pop();
                }
        }
        if(isOk){
            pos++;
        }
    }

    if(isOk){
        printf("ok so far\n");
    } else {
        printf("%c %d\n",s.at(pos), pos);
    }
}