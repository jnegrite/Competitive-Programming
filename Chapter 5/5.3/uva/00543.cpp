#include<iostream>
#include<cstring>

using namespace std;

int main(){
    bool isPrime[1000000] {};
    memset(isPrime,true,sizeof(isPrime));

    //generate the sieve
    for(int i=3;i<1000;i+=2){
        if(!isPrime[i]){
            continue;
        }

        int increment {i<<1};
        for(int j=i*i;j<1000000;j+=increment){
            isPrime[j] = false;
        }
    }

    int value, low, high;
    while(cin >> value, value > 0){
        int found {false};

        for(low=3,high=value-3; low <= high; low+=2, high-=2){
            if(!isPrime[low] || !isPrime[high]){
                continue;
            }

            if(low+high == value){
                found = true;
                break;
            }
        }

        if(found){
            cout << value << " = " << low << " + " << high << '\n';
        } else {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}