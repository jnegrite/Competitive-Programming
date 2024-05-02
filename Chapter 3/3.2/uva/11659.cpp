#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int nInformants;
int nInformation;
bool isTruthful[21] {};
int currTruthful {};
int maxTruthful {};
vector<vector<int>> info {};

void backtrack(int pos){
    if(pos > nInformants){
        //validate

        bool isOk {true};
        for(int i=1;isOk && i<=nInformants;++i){
            if(!isTruthful[i]){
                continue;
            }

            for(int res:info[i]){
                if((res < 0 && isTruthful[-res])
                        || (res > 0 && !isTruthful[res])){
                    isOk = false;
                    break;
                }
            }
        }

        if(isOk && currTruthful > maxTruthful){
            maxTruthful = currTruthful;
        }

        return;
    }

    backtrack(pos+1);

    isTruthful[pos] = true;
    ++currTruthful;
    
    backtrack(pos+1);

    --currTruthful;
    isTruthful[pos] = false;
}

int main(){
    while(cin >> nInformants >> nInformation, nInformants != 0){
        
        //setup the truth table
        info.clear();
        info.assign(nInformants+1,vector<int>{});

        int from, to;
        for(int i=0;i<nInformation;i++){
            cin >> from >> to;
            info[from].push_back(to);
        }

        currTruthful = 0;
        maxTruthful = 0;

        backtrack(1);
        cout << maxTruthful << '\n';
    }
}