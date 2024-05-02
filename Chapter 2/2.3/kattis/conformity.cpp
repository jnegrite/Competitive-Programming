#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string toString(const vector<int> s){
    string output = to_string(s[0]);
    for(int i=1;i<s.size();i++){
        output += "-" + to_string(s[i]);
    }
    return output;
}

int main(){
    long numStudents{};
    long maxAns {};
    int curr;
    cin >> numStudents;

    unordered_map<string,long> combinations{};
    for(long i=0;i<numStudents;i++){
        vector<int> temp {};
        for(int j=0;j<5;j++){
            cin >> curr;
            temp.push_back(curr);
        }
        sort(temp.begin(), temp.end());
        string repr = toString(temp);
        if(combinations.count(repr) == 0){
            combinations[repr] = 0;
        }

        combinations[repr]++;
        maxAns = max(maxAns,combinations[repr]);
    }

    long ans {};
    for(auto it:combinations){
        if(it.second == maxAns){
            ans += it.second;
        }
    }
    cout << ans << '\n';

}