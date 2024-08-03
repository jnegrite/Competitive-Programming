#include<iostream>
#include<vector>

using namespace std;

int nCampsites;
int nDays;
vector<int> distances {};

bool isPossible(int val){
    int curr {0};

    int temp {};
    for(auto it {distances.begin()};(curr<= nDays) && (it!=distances.end());++it){
        temp += *it;

        if(temp > val){
            ++curr;
            temp = *it;
        }
    }

    return curr <= nDays;
}

int main(){
    while(cin >> nCampsites >> nDays){
        distances.clear();
        distances.assign(nCampsites+1,0);

        int high {0};
        int low {0};
        for(int i=0;i<=nCampsites;++i){
            cin >> distances[i];
            high += distances[i];
            low = max(low,distances[i]);
        }

        while(low < high){
            int mid {(low+high)>>1};
            if(isPossible(mid)){
                high = mid;
            } else {
                low = mid+1;
            }
        }
        cout << low << '\n';
    }
}