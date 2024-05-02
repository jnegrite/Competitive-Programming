#include<iostream>
#include<stack>

using namespace std;

int main(){
    long numQueries {};
    stack<string> dreams {};
    string s;
    cin >> numQueries;
    while(numQueries--){
        cin >> s;
        if(s == "Test"){
            if(dreams.empty()){
                cout << "Not in a dream\n";
            } else {
                cout << dreams.top() << '\n';
            }
        } else if (s == "Kick"){
            if(!dreams.empty()){
                dreams.pop();
            }
        } else if (s == "Sleep"){
            cin >> s;
            dreams.emplace(s);
        }
    }
}