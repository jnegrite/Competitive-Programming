#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    long val;
    vector<long> values {};
    while(cin >> val){
        values.push_back(val);
        sort(values.begin(), values.end());

        if(values.size() % 2 == 1){
            cout << values.at(values.size()/2) << '\n';
        } else {
            cout << (values.at((values.size()/2)-1) + values.at((values.size()/2)))/2 << '\n';
        }
    }

}