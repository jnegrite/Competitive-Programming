#include<iostream>
#include<unordered_map>
#include<set>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int numCases;
    string s;
    getline(cin,s);
    numCases = stoi(s);
    
    for(int tc=1;tc<=numCases;tc++){
        unordered_map<string,set<long>> wordPositions {};
        vector<string> words {""};
        long wordPos{0};

        while(getline(cin,s), s != "END"){
            string currWord = "";

            for(char ch: s){
                if(isalpha(ch)){
                    currWord += ch;
                } else if(currWord != ""){
                    //processWord

                    if(wordPositions.count(currWord) == 0){
                        set<long> temp {};
                        wordPositions[currWord] = temp;
                    }
                    wordPositions[currWord].emplace(++wordPos);
                    words.push_back(currWord);
                    currWord = "";
                }
            }

            if(currWord != ""){
                if(wordPositions.count(currWord) == 0){
                    set<long> temp {};
                    wordPositions[currWord] = temp;
                }
                wordPositions[currWord].emplace(++wordPos);
                words.push_back(currWord);
            }
        }

        long ansFrom {1};
        long ansTo {1};
        long tempFrom {1};
        long tempTo;
        long minDist;
        
        priority_queue<long,vector<long>,greater<long>> q {};

        //get initial settings
        for(auto au: wordPositions){
            long seed = *(au.second.lower_bound(1));
            q.emplace(seed);
            ansTo = max(ansTo,seed);
        }
        tempTo = ansTo;
        minDist = ansTo - ansFrom;

        while(true){
            long prevVal {q.top()};
            string toReplace = words[q.top()];
            q.pop();
            auto nextPos = wordPositions[toReplace].upper_bound(prevVal);

            if(nextPos == wordPositions[toReplace].end()){
                break;
            }

            long nextVal = *nextPos;
            q.emplace(nextVal);
            tempTo = max(tempTo,nextVal);
            tempFrom = q.top();

            if(tempTo - tempFrom < minDist){
                minDist = tempTo - tempFrom;
                ansTo = tempTo;
                ansFrom = tempFrom;

                if(minDist + 1 == wordPositions.size()){
                    break;
                }
            }
        }

        cout << "Document " << tc << ": " << ansFrom << ' ' << ansTo << '\n';
    }
}