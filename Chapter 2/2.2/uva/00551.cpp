#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

pair<string, int> getNextToken(string &s,int pos){
    while(pos < s.length()){
        string output {};
        switch(s.at(pos)){
            case '[': case ']':
            case '{': case '}':
            case '<': case '>':
            case ')':
                output.push_back(s.at(pos));
                return pair<string,int>{output,pos};
                break;  
            case '(':
                if(pos+1<s.length() && s.at(pos+1) == '*'){
                    return pair<string,int>{"(*",pos};
                } else {
                    return pair<string,int>{"(",pos};;
                }
                break;
            case '*':
                if(pos+1<s.length() && s.at(pos+1) == ')'){
                    return pair<string,int>{"*)",pos};
                }
                break;
        }
        pos++;
    }
    return pair<string,int>{"",-1};
}

vector<string> openBrackets {"(","[","{","<","(*"};
vector<string> closeBrackets {")","]","}",">","*)"};

int getIndex(vector<string> &from, string &toFind){
    for(int i=0;i<from.size();i++){
        if(from.at(i) == toFind){
            return i;
        }
    }
    return -1;
}

int main(){
    string s;
    while(getline(cin,s)){
        int offsets {-1};
        stack<string> brackets {};
        int pos {0};
        bool hasMismatch{false};
        while(true){
            pair<string,int> pr = getNextToken(s,pos);
            if(pr.second==-1){
                break;
            } else {
                pos = pr.second;
            }

            if(getIndex(openBrackets,pr.first) != -1){
                brackets.emplace(pr.first);
            } else {
                int closeIdx = getIndex(closeBrackets,pr.first);
                if(closeIdx != -1){
                    if(brackets.empty()){
                        hasMismatch = true;
                        break;
                    }

                    int topIdx = getIndex(openBrackets,brackets.top());
                    if(topIdx == closeIdx){
                        brackets.pop();
                    } else {
                        hasMismatch = true;
                        break;
                    }

                }
            }
            pos += pr.first.length();
            
            if(pr.first.length() == 2){
                offsets++;
            }
        }

        if(hasMismatch){
            cout << "NO " << pos-offsets << '\n';
        } else if(!brackets.empty()){
            cout << "NO " << s.length()-offsets << '\n';
        } else {
            cout << "YES\n";
        }
    }
}