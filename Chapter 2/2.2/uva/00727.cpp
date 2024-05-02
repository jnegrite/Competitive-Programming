#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    int numCases{};
    string s;

    getline(cin,s);
    numCases = stoi(s);
    getline(cin,s);
    for(int tc=0;tc<numCases;tc++){
        string output {};
        stack<string> operators {};
        while(getline(cin,s)){
            if(s.length()==0){
                break;
            }

            if(s.at(0) >= '0' && s.at(0) <= '9'){
                output += s;
            } else if(s=="("){
                operators.emplace(s);
            } else if (s==")"){
                while(operators.top() != "("){
                    output += operators.top();
                    operators.pop();
                }
                operators.pop();
            } else if (s=="+" || s=="-"){
                while(!operators.empty() && operators.top() != "("){
                    output += operators.top();
                    operators.pop();
                }
                operators.emplace(s);
            } else if (s=="*" || s=="/"){
                while(!operators.empty() && operators.top() != "(" && operators.top() != "+" && operators.top() != "-"){
                    output += operators.top();
                    operators.pop();
                }
                operators.emplace(s);
            }
        }
        while(!operators.empty()){
            output += operators.top();
            operators.pop();
        }

        if(tc>0){
            cout << '\n';
        }
        cout << output << '\n';
    }
}