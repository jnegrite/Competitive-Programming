#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<char,char> mapChar {};

bool grid[1000][1000] {};

int getCode(char ch){
    auto it {mapChar.find(ch)};

    if(it == mapChar.end()){
        return -1;
    }

    return it->second;
}

int reg(char ch){
    int ans = getCode(ch);
    if(ans != -1){
        return ans;
    }

    ans = mapChar.size();
    return mapChar[ch] = ans;
}

int main(){
    int nTranslations;
    int wordTrans;

    cin >> nTranslations >> wordTrans;

    char c1, c2;
    int v1, v2;
    while(nTranslations--){
        cin >> c1 >> c2;
        v1 = reg(c1);
        v2 = reg(c2);
        grid[v1][v2] = true;
    }

    for(int i=0;i<mapChar.size();i++){
        grid[i][i] = true;
    }

    for(int k=0;k<mapChar.size();k++){
        for(int i=0;i<mapChar.size();i++){
            if(!grid[i][k]) continue;

            for(int j=0;j<mapChar.size();j++){
                if(!grid[k][j]) continue;

                grid[i][j] = true; 
            }
        }
    }

    string s1, s2;
    while(wordTrans--){
        bool match {true};
        cin >> s1 >> s2;

        if(s1.length() != s2.length()){
            match = false;
        }

        if(match){
            for(int i=0;match && i<s1.length();i++){
                int v1, v2;
                char c1, c2;

                c1 = s1.at(i);
                c2 = s2.at(i);

                if(c1 == c2){
                    continue;
                }

                v1 = getCode(c1);
                v2 = getCode(c2);

                if(v1 == -1 || v2 == -1 || !grid[v1][v2]){
                    match = false;
                    break;
                }
            }
        }

        cout << (match ? "yes\n" : "no\n");
    }
}