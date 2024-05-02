#include<iostream>
#include<string>

using namespace std;

int main(){
    int heightTree{};
    long val {1};
    cin >> heightTree;
    string s;

    if(cin>>s){
        for(char ch:s){
            switch(ch){
                case 'L':
                    val <<= 1;
                    break;
                case 'R':
                    val <<= 1;
                    val |= 1;
                    break;
            }
        }
    }
    
    cout << ((1l << (heightTree+1)) - val) << '\n';
    
}