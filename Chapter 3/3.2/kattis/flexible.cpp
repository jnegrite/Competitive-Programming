#include<iostream>
#include<vector>
#include<set>

using namespace std;

int partitions[100] {};
set<int> roomSizes {};

int main(){
    int nPartitions;
    int roomWidth;
    int curr;

    cin >> roomWidth >> nPartitions;
    partitions[nPartitions] = roomWidth;

    roomSizes.emplace(roomWidth);
    for(int i=0;i<nPartitions;++i){
        cin >> partitions[i];
        roomSizes.emplace(partitions[i]);
    }

    for(int i=0;i<=nPartitions;++i){
        for(int j=i+1;j<=nPartitions;++j){
            roomSizes.emplace(partitions[j] - partitions[i]);
        }
    }
    auto it {roomSizes.begin()};
    cout << *(it++);
    for(;it!=roomSizes.end();it++){
        cout << ' ' << *it;
    }
    cout << '\n';
}