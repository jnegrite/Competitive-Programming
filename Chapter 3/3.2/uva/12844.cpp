#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){
    int nCases;
    int curr;
    cin >> nCases;
    for(int tc=1;tc<=nCases;tc++){
        //get data
        multiset<int> totalWeights {};
        int ans[5] {};

        for(int i=0;i<10;i++){
            cin >> curr;
            totalWeights.emplace(curr);
        }

        int minWeight {*(totalWeights.begin())};
        for(int a=1;a<=minWeight/2;a++){
            int b = minWeight-a;
            
            ans[0] = a;
            ans[1] = b;
            
            totalWeights.erase(totalWeights.begin());

            for(int c=b;c<=200;c++){
                bool allOk {true};

                vector<int> removed {};
                for(int i=0;i<2;i++){
                    auto it = totalWeights.find(c+ans[i]);
                    if(it == totalWeights.end()){
                        allOk = false;
                        break;
                    } else {
                        totalWeights.erase(it);
                        removed.push_back(c+ans[i]);
                    }
                }

                //try next value if all ok
                if(!allOk){
                    for(int r:removed){
                        totalWeights.emplace(r);
                    }
                    continue;
                }

                ans[2] = c;
                for(int d=c;d<=200;d++){
                    bool allOk {true};

                    vector<int> removed {};
                    for(int i=0;i<3;i++){
                        auto it = totalWeights.find(d+ans[i]);
                        if(it == totalWeights.end()){
                            allOk = false;
                            break;
                        } else {
                            totalWeights.erase(it);
                            removed.push_back(d+ans[i]);
                        }
                    }

                    //try next value if all ok
                    if(!allOk){
                        for(int r:removed){
                            totalWeights.emplace(r);
                        }
                        continue;
                    }

                    ans[3] = d;
                    for(int e=d;e<=400;e++){
                        bool allOk {true};

                        vector<int> removed {};
                        for(int i=0;i<4;i++){
                            auto it = totalWeights.find(e+ans[i]);
                            if(it == totalWeights.end()){
                                allOk = false;
                                break;
                            } else {
                                totalWeights.erase(it);
                                removed.push_back(e+ans[i]);
                            }
                        }

                        //try next value if all ok
                        if(allOk){
                            ans[4] = e;
                            goto exitSearch;
                        }
                        
                        for(int r:removed){
                            totalWeights.emplace(r);
                        }
                    }
                
                    for(int r:removed){
                        totalWeights.emplace(r);
                    }
                }
            
                for(int r:removed){
                    totalWeights.emplace(r);
                }
            }
            totalWeights.emplace(minWeight);
        }

exitSearch:
        printf("Case %d:",tc);

        for(int i=0;i<5;i++){
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
}

