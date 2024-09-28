#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool checkSequence(vector<int> &v){
    int len = v.size();
    int d = v[1] - v[0];
    for(int j=2;j<len;++j){
        if(v[j] - v[j-1] != d){
            return false;
        }
    }
    return true;
}

int main(){
    int nCases, nTerms;
    vector<int> values {};

    cin >> nCases;
    while(nCases--){
        cin >> nTerms;
        values.assign(nTerms,0);
        for(int i=0;i<nTerms;++i){
            cin >> values[i];
        }

        if(checkSequence(values)){
            cout << "arithmetic";
        } else {
            sort(values.begin(),values.end());
            if(checkSequence(values)){
                cout << "permuted arithmetic";
            } else {
                cout << "non-arithmetic";
            }
        }
        cout << '\n';
    }

}