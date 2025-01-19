#include<iostream>
#include<set>
#include<vector>
#include<bitset>

using namespace std;

const int MAXVAL {32000};

int main(){
    set<int> primes {2};
    bitset<MAXVAL+1> isPrime {};
    isPrime.set();

    for(int i=4;i<=MAXVAL;i+=2){
        isPrime.reset(i);
    }

    for(int i=3;i<=MAXVAL;i++){
        if(!isPrime.test(i)){
            continue;
        }
        int increment {i<<1};
        primes.emplace(i);
        for(int j=i*i;j<=MAXVAL;j+=increment){
            isPrime.reset(j);
        }
    }

    vector<int> ans{};
    int nCases;
    cin >> nCases;
    while(nCases--){
        int val;
        cin >> val;
        int midVal {val>>1};
        ans.clear();

        for(auto it {primes.begin()};*it <= midVal; ++it){
            if(primes.find(val-*it) != primes.end()){
                ans.push_back(*it);
            }
        }
        cout << val << " has " << ans.size() << " representation(s)\n";
        for(int i:ans){
            cout << i << "+" << (val-i) << '\n';
        }
        cout << '\n';
    }
}

