#include<iostream>
#include<vector>

using namespace std;

vector<long> factors {};

void factorize(long val, vector<long> &f){
    if(val < 0){
        f.push_back(-1);
        factorize(-val,f);
    } else {
        long prev;
        if(f.empty() || f.back() < 0){
           prev = 2;
        } else {
            prev = f.back();
        }

        while(val%prev != 0 && (prev*prev <= val)){
            ++prev;
        }

        if(val%prev == 0){
            f.push_back(prev);
            factorize(val/prev,f);
        } else if (val != 1 || f.empty()){
            f.push_back(val);
        }
    }
}

int main(){
    long val;
    while(cin >> val, val != 0){
        factors.clear();
        factorize(val,factors);
        cout << val << " = " << factors[0];
        for(long i=1;i<factors.size();++i){
            cout << " x " << factors[i];
        }
        cout << "\n";
    }
}