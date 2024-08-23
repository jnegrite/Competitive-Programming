#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int nWords {};
vector<priority_queue<string,vector<string>,greater<string>>> wordPaths {};
vector<int> netDir {};
vector<string> ans {};
string s;

pair<char,char> evaluateWord(string s){
    return {s.at(0)-'a',s.at(s.length()-1)-'a'};
}

int main(){
    int nCases;

    cin >> nCases;
    while(nCases--){ 
        //get data
        cin >> nWords;
        wordPaths.clear();
        wordPaths.assign(26,{});
        netDir.assign(26,0);

        for(int i=0;i<nWords;++i){
            cin >> s;
            pair<int,int> currVal {evaluateWord(s)};
            wordPaths[currVal.first].emplace(s);
            --netDir[currVal.first];
            ++netDir[currVal.second];
        }

        bool isOk {true};
        int startIdx {-1};
        int endIdx {-1};
        int numOdd {0};
        //evaluate paths

        for(int i=0;isOk && i<26;++i){
            if(netDir[i] == 0) continue;

            if(netDir[i] == -1){
                if(startIdx == -1){
                    startIdx = i;
                } else {
                    isOk = false;
                }
            } else if(netDir[i] == 1) {
                if(endIdx == -1){
                    endIdx = i;
                } else {
                    isOk = false;
                }
            } else {
                isOk = false;
            }
        }


        if(isOk){
            
            if(startIdx==-1){
                startIdx=0;
                while(wordPaths[startIdx].empty()){
                    ++startIdx;
                }
            }

            ans.clear();
            ans.reserve(nWords);
            stack<string> st {};
            st.push(wordPaths[startIdx].top());
            wordPaths[startIdx].pop();

            while(!st.empty()){
                string curr {st.top()};
                auto currVal {evaluateWord(curr)};
                int nxtIdx {currVal.second};

                if(wordPaths[nxtIdx].empty()){
                    st.pop();
                    ans.push_back(curr);
                } else {
                    st.push(wordPaths[nxtIdx].top());
                    wordPaths[nxtIdx].pop();
                }
            }
            reverse(ans.begin(),ans.end());

            if(ans.size() < nWords){
                isOk = false;   
            }
        }
        
        if(!isOk){
            cout << "***\n";
        } else {
            auto it {ans.begin()};
            cout << *(it++);
            while(it != ans.end()){
                cout << '.' << *(it++);
            }
            cout << '\n';
        }
    }
}