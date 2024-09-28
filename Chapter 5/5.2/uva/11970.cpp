#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> getLucky(int value){
    vector<int> ans {};

    int denom = 1;
    while(true){
        int sqDenom = denom*denom;

        if(sqDenom >= value){
            break;
        }

        int x = value - sqDenom;

        if(x % denom == 0){
            ans.push_back(x);
        } 

        ++denom;
    }
    reverse(ans.begin(),ans.end());

    return ans;
}

int main(){
    int nCases;
    int number;
    cin >> nCases;
    
    for(int tc=1;tc<=nCases;++tc){
        cin >> number;
        cout << "Case " << tc << ":";
        for(int val: getLucky(number)){
            cout << ' ' << val;
        }

        cout << '\n';
    }
}