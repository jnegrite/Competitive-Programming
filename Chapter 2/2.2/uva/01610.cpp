#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string getSeparator(string s1, string s2){
    if(s1.length()==1){
        //when s1 only has 1 char left
        return s1;
    } else if(s1.at(0) == s2.at(0)){
        //when both s1 and s2 have the same char
        string s;
        s.push_back(s1.at(0));
        s += getSeparator(s1.substr(1),s2.substr(1));
        return s;
    } else if (s1.at(0)+1 != s2.at(0)) {
        //if i can just increment the char for s1
        string s{static_cast<char>(s1.at(0)+1)};
        return s;
    } else if(s2.length() != 1){
        string s {s2.at(0)};
        return s;
    } else {
        //case here when s2's char is right after s1
        string s {};
        s.push_back(s1.at(0));
        bool applied{false};

        for(int i=1;i<s1.length()-1;i++){
            if(s1.at(i) == 'Z'){
                s += 'Z';
            } else {
                s.push_back(s1.at(i)+1);
                applied = true;
                break;
            }
        }

        if(!applied){
            s.push_back(s1.at(s1.length()-1));
        }
        return s;
    }
}

int main(){
    int numNames;
    vector<string> names {};
    string s;

    while(true){
        cin >> numNames;

        if(numNames == 0){
            break;
        }
        names.clear();
        for(int i=0;i<numNames;i++){
            cin >> s;
            names.push_back(s);
        }
        sort(names.begin(),names.end());
        cout << getSeparator(names[numNames/2 -1],names[numNames/2]) << '\n';;
    }
}