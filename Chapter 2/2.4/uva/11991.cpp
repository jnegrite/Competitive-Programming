#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    long n, m;
    long curr;
    long pos;
    while(cin >> n >> m){
        unordered_map<long,vector<long>> locations{};
        for(long i=1;i<=n;i++){
            cin >> curr;
            if(locations.count(curr) == 0){
                locations[curr] = vector<long> {};
            }
            locations[curr].push_back(i);
        }
        for(long i=0;i<m;i++){
            cin >> pos >> curr;
            if(locations.count(curr) == 0 || locations[curr].size() < pos){
                cout << 0 << '\n';
            } else {
                cout << locations[curr][pos-1] << '\n';
            }
        }
    }
}