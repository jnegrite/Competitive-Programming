#include<iostream>
#include<queue>
#include<string>

using namespace std;
string sFront;
string sBack;
deque<string> mainQueue {};
bool useBack = true;

void resolve(){
    if(sFront.length() != 0){
        mainQueue.push_front(sFront);
        sFront = "";
    }

    if(sBack.length() != 0){
        mainQueue.push_back(sBack);
        sBack = "";
    }
}

int main(){
    string s;
    int numCases;
    getline(cin,s);
    numCases = stoi(s);
    long curr = 0;

    while(numCases--){
        mainQueue.clear();
        sFront = "";
        sBack = "";
        useBack = true;

        getline(cin,s);
        for(char ch:s){
            switch(ch){
                case ']':
                    resolve();
                    useBack = true;
                    break;
                case '[':
                    resolve();
                    useBack = false;
                    break;
                case '<':
                    if(useBack){
                        if(sBack.length()==0){
                            if(!mainQueue.empty()){
                                sBack = mainQueue.back();
                                mainQueue.pop_back();
                            } else if (sFront.length()==0){
                                sBack = sFront;
                                sFront = "";
                            }
                        }

                        if(sBack.length() > 0){
                            sBack = sBack.substr(0,sBack.length()-1);
                        }
                    } else {
                        if(sFront.length() > 0){
                            sFront = sFront.substr(0,sFront.size()-1);
                        }
                    }
                    break;
                default:
                    if(useBack){
                        sBack += ch;
                    } else {
                        sFront += ch;
                    }
                    break;
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