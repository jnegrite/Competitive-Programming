#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

long long getValue(string s){
    long long curr {};

    for(char ch:s){
        curr <<=5;
        curr |= (ch-'a'+1);
    }
    return curr;
}

int main(){
    string sMessage;
    while(getline(cin,sMessage)){
        auto strIn {stringstream(sMessage)};
        string curr;

        vector<long long> values {};
        long long ans{26};
        while(strIn >> curr){
            auto temp {getValue(curr)};
            ans=min(ans,temp);
            values.push_back(temp);
        }

        //loop through values;
        bool ansFound{false};

        while(!ansFound){
            bool isMultiple {};
            for(auto val:values){
                if(ans%val == 0){
                    isMultiple = true;
                    break;
                }
            }

            if(isMultiple){
                vector<int> isUsed {};
                isUsed.assign(values.size(),-1);

                bool validConfig{true};

                for(int i=0;validConfig && i<values.size();i++){
                    int hashed {(ans/values[i])%values.size()};

                    if(isUsed[hashed]==-1){
                        isUsed[hashed] = i;
                    } else if(values[i] != values[isUsed[hashed]]){
                        validConfig = false;
                        ans = min(((ans/values[i])+1)*values[i],((ans/values[isUsed[hashed]])+1)*values[isUsed[hashed]]);
                        break;
                    }
                }

                if(validConfig){
                    ansFound = true;
                    break;
                }
            }
        }   
        cout << sMessage << '\n';
        cout << ans << "\n\n";
    }
}