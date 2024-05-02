#include<iostream>

using namespace std;

int main(){
    string s;
    long tc {0};
    while(cin>>s,s!="end"){
        int numStacks{0};
        char stacks[26] {};
        for(char ch:s){
            bool isAlloc {false};
            for(int i=0;i<numStacks;i++){
                if(ch <= stacks[i]){
                    isAlloc=true;
                    stacks[i] = ch;
                    break;
                }
            }
            if(!isAlloc){
                stacks[numStacks++] = ch;
            }
        }
        cout << "Case " << ++tc << ": " << numStacks << '\n';
    }
}