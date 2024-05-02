#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    int numVars;
    string s;
    stack<int> stackVals {};
    int values[26] {};
    cin >> numVars;
    for(int i=0;i<numVars;i++){
        cin >> s;
        values[i] = (s.at(0)=='T'?1:0);
    }

    //get inputs
    while(cin >> s){
        int v1, v2;
        switch(s.at(0)){
            case '*':
                v1 = stackVals.top();
                stackVals.pop();
                v2 = stackVals.top();
                stackVals.pop();
                stackVals.emplace(v1 & v2);
                break;
            case '+':
                v1 = stackVals.top();
                stackVals.pop();
                v2 = stackVals.top();
                stackVals.pop();
                stackVals.emplace(v1 | v2);
                break;
            case '-':
                stackVals.top() ^= 1;
                break;
            default:
                stackVals.emplace(values[s.at(0)-'A']);
        }
    }

    cout<< (stackVals.top() == 1 ? "T" : "F") << '\n';
    }