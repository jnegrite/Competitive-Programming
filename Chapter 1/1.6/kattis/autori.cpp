#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    string output {s.at(0)};
    auto idx = s.find('-');

    while (idx != -1){
        output += s.at(idx+1);
        s=s.substr(idx+1);
        idx = s.find('-');
    }
    cout << output << '\n';
}