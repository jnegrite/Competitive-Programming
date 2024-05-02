#include<iostream>
#include<map>
#include<string>

using namespace std;

map<char,string> encoding {};

void initMapping(){
    encoding['a'] = "@";
    encoding['b'] = "8";
    encoding['c'] = "(";
    encoding['d'] = "|)";
    encoding['e'] = "3";
    encoding['f'] = "#";
    encoding['g'] = "6";
    encoding['h'] = "[-]";
    encoding['i'] = "|";
    encoding['j'] = "_|";
    encoding['k'] = "|<";
    encoding['l'] = "1";
    encoding['m'] = "[]\\/[]";
    encoding['n'] = "[]\\[]";
    encoding['o'] = "0";
    encoding['p'] = "|D";
    encoding['q'] = "(,)";
    encoding['r'] = "|Z";
    encoding['s'] = "$";
    encoding['t'] = "']['";
    encoding['u'] = "|_|";
    encoding['v'] = "\\/";
    encoding['w'] = "\\/\\/";
    encoding['x'] = "}{";
    encoding['y'] = "`/";
    encoding['z'] = "2";

    for (char ch='A'; ch<= 'Z'; ch++){
        encoding[ch] = encoding[ch-'A' + 'a'];
    }
}

int main(){
    initMapping();
    string s;

    getline(cin,s);

    for(char ch: s){
        if(isalpha(ch)){
            cout << encoding[ch];
        } else {
            cout << ch;
        }
    }
}