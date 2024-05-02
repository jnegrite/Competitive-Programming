#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){
    long curr;
    int numCases;
    cin >> numCases;
    for(int tc=1;tc<=numCases;tc++){
        long ans[3][2] {};
        long numCandies[3] {};
        vector<set<long>> candies {};
        for(int i=0;i<3;i++){
            cin >> numCandies[i];
        }

        //get candies
        set<long>::iterator it[3] {};
        for(int i=0;i<3;i++){
            set<long> currCandies {};
            for(long j=0;j<numCandies[i];j++){
                cin >> curr;
                if(currCandies.count(curr) == 0){
                    currCandies.emplace(curr);
                }
            }
            candies.push_back(currCandies);
            
        }

        for(int i=0;i<3;i++){
            it[i] = candies[i].begin();
        }
        //process
        while(true){
            //check if all empty
            bool allEmpty = true;
            for(int i=0;i<3;i++){
                if(it[i] != candies[i].end()){
                    allEmpty = false;
                    break;
                }
            }
            if(allEmpty){
                break;
            }

            //get min value
            long currMin {1000000};
            for(int i=0;i<3;i++){
                if(it[i] != candies[i].end()){
                    currMin = min(currMin, *(it[i]));
                }
            }

            int existence {0};
            for(int i=0;i<3;i++){
                if(it[i] != candies[i].end() && *(it[i]) == currMin){
                    existence |= (1<<i);
                }
            }

            switch(existence){
                case 1:
                    ans[0][0]++;
                    break;
                case 2:
                    ans[1][0]++;
                    break;
                case 4:
                    ans[2][0]++;
                    break;
                case 3:
                    ans[2][1]++;
                    break;
                case 5:
                    ans[1][1]++;
                    break;
                case 6:
                    ans[0][1]++;
                    break;
            }

            //moving the iterators
            for(int i=0;i<3;i++){
                if(existence & (1<<i)){
                    it[i]++;
                }
            }
        }

        cout << "Case #" << tc << ":\n";
        for(int i=0;i<3;i++){
            cout << ans[i][0] << ' ' << ans[i][1] << '\n';
        }
    }
}