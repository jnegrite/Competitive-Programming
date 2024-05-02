#include<iostream>
#include<malloc.h>
#include<cmath>
#include<vector>

using namespace std;

const long upperBound {1000000000};

bool *notPrime;
long ansCount{1};

int main(){

    //build sieve
    notPrime = (bool*)calloc(upperBound+1,sizeof(bool));
    int seed = 2;
    vector<long> answers {3};
    do{
        if(notPrime[seed]){
            seed++;
            continue;
        }

        //cout << "Removing multiples of " << seed << '\r' << flush;
        for(long temp = (seed<<1);temp<=upperBound;temp+=seed){
            notPrime[temp] = true;
        }

        seed++;
    } while(seed*seed <= upperBound);
    //cout << endl;

    //do simulation
    for(long i=4;i<=upperBound;i++){
        if(!notPrime[i+1]){
            continue;
        }

        bool hasPrime {false};
        for(long v:answers){
            if(!notPrime[i+1-v]){
                hasPrime = true;
                break;
            }
        }
        if(!hasPrime){
            cout << i << "," << endl;
            answers.push_back(i);
        }
    }

    free(notPrime);    
}