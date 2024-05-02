#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    int lenPass;
    string s;
    while(cin >> lenPass){
        cin >> s;
        long maxCount {};
        unordered_map<string,long> subCounts {};
        for(long i=0;i<s.length()-lenPass;i++){
            string sub {s.substr(i,lenPass)};
            if(subCounts.count(sub) == 0){
                subCounts[sub] = 1;
            } else {
                subCounts[sub]++;
            }
            maxCount = max(maxCount,subCounts[sub]);
        }

        for(auto it:subCounts){
            if(it.second == maxCount){
                cout << it.first << '\n';
                break;
            }
        }
    }
}