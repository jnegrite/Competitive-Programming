#include<iostream>
#include<vector>

using namespace std;

int coefs[7] {};
vector<int> ans {};
int degree;

int evalExp(int x){
    int ans {0};
    for(int i=0;i<=degree;++i){
        ans *= x;
        ans += coefs[i];
    }
    return ans;
}

vector<vector<int>> binomials {
    {1},
    {1,1},
    {1,2,1},
    {1,3,3,1},
    {1,4,6,4,1},
    {1,5,10,10,5,1},
    {1,6,15,20,15,6,1},
};

int main(){
    cin >> degree;
    
    for(int i=0;i<=degree;++i){
        cin >> coefs[i];
    }

    ans.push_back(coefs[degree]);

    for(int i=1;i<=degree;++i){
        int target {evalExp(i)};
        auto &binom {binomials[i]};

        for(int j=0;j<ans.size();++j){
            target -= binom[j]*ans[j];
        }
        ans.push_back(target);
    }

    cout << ans[0];
    for(int i=1;i<ans.size();++i){
        cout << ' ' << ans[i];
    }
    cout << '\n';
}