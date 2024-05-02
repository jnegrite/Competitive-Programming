#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<set<char>> chars {};


int main(){
    int nCases {};
    cin >> nCases;
    int k {};
    string s;

    while(nCases--){
        cin >> k;
        chars.assign(5,set<char>{});
        vector<set<char>> seenChars {};
        seenChars.assign(5,set<char>{});
        
        //initial grid
        for(int i=0;i<6;i++){
            cin >> s;
            for(int j=0;j<5;j++){
                seenChars[j].emplace(s.at(j));
            }
        }

        //comparison grid
        for(int i=0;i<6;i++){
            cin >> s;
            for(int j=0;j<5;j++){
                char ch {s.at(j)};
                if(seenChars[j].count(ch) != 0){
                    chars[j].emplace(ch);
                }
            }
        }

        //check if k is within bounds
        long totalPos {1};
        for(int j=0;j<5;j++){
            totalPos *= chars[j].size();
        }

        if(k > totalPos){
            cout << "NO\n";
        } else {
            char word[6] {};
            word[5] = '\0';
            k--;
            for(int j=4;j>=0;--j){
                int pos = k% chars[j].size();
                k /= chars[j].size();

                auto it {chars[j].begin()};
                for(int i=0;i<pos;i++){
                    ++it;
                }
                word[j] = *it;
            }
            cout << word << '\n';
        }
    }
}


