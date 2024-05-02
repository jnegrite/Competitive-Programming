#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

vector<long> primeFactors {};
void getPrimeFactors(long val){
    long factor {2};

    primeFactors.clear();
    while(factor <= val){
        if(val%factor==0){
            primeFactors.push_back(factor);
            val /= factor;
        } else {
            factor++;
        }
    }
}

long sumFactors {};
long currFactor {};
int prevIdx {};
long num;

bool backtrack(int pos){
    if(pos == primeFactors.size()){
        if(currFactor != num){
            sumFactors += currFactor;
            if(sumFactors > num){
                return true;
            }
        }
        return false;
    }

    backtrack(pos+1);

    if(pos == 0 || primeFactors[pos] != primeFactors[pos-1] || prevIdx+1 == pos){
        int cachePrev = prevIdx;
        int cacheVal = currFactor;

        prevIdx = pos;
        currFactor *= primeFactors[pos];
        if(backtrack(pos+1)){
            return true;
        }
        currFactor = cacheVal;
        prevIdx = cachePrev;
    }

    return false;
}

int main(){
    cout << "PERFECTION OUTPUT\n";
    while(cin >> num,num != 0){
        getPrimeFactors(num);
        sumFactors = 0;
        prevIdx = -1;
        currFactor = 1;
        backtrack(0);

        cout << setw(5) << num << "  ";
        if(sumFactors == num){
            cout << "PERFECT";
        } else if (sumFactors < num){
            cout << "DEFICIENT";
        } else {
            cout << "ABUNDANT";
        }
        cout << '\n';
    }
    cout << "END OF OUTPUT\n";
}