#include<iostream>
#include<queue>
#include<string>

using namespace std;

deque<string> mainQueue {};
string sFront {};
string sBack {};

string *target {&sBack};

void resolve(){
    if(sFront.length() > 0){
        mainQueue.push_front(sFront);
        sFront = "";
    }

    if(sBack.length() > 0){
        mainQueue.push_back(sBack);
        sBack = "";
    }
}

int main(){
    string s;
    while(getline(cin,s)){
        
        
        sFront = "";
        sBack = "";
        target = &sBack;
        
        for(char ch:s){
            switch(ch){
                case '[':
                    resolve();
                    target = &sFront;
                    break;
                case ']':
                    resolve();
                    target = &sBack;
                    break;
                default:
                    (*target).push_back(ch);
            }
        }

        resolve();
        while(!mainQueue.empty()){
            cout << mainQueue.front();
            mainQueue.pop_front();
        }
        cout << '\n';
    }    
}