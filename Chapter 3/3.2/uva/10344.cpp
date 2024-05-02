#include<iostream>
using namespace std;

int values[5] {};
int taken {};
long currValue {};



bool isPossible(int pos){
    if(pos == 5){
        return currValue == 23;
    }

    if(pos == 0){
        for(int i=0;i<5;i++){
            currValue = values[i];
            taken = (1<<i);

            if (isPossible(pos+1)){
                return true;
            }

            taken = 0;
        }
    } else {
        for(int i=0;i<5;i++){
            if((taken & (1<<i)) == 0){
                long cacheVal = currValue;
                taken ^= (1<<i);

                //+
                currValue += values[i];
                if(isPossible(pos+1)){
                    return true;
                }

                //-
                currValue = cacheVal - values[i];
                if(isPossible(pos+1)){
                    return true;
                }

                //*
                currValue = cacheVal * values[i];
                if(isPossible(pos+1)){
                    return true;
                }

                currValue = cacheVal;
                taken ^= (1<<i);
            }
        }
    }
    return false;
}

int main(){
    while(true){
        long maxVal{0};

        //get data
        for(int i=0;i<5;i++){
            cin >> values[i];
            if(values[i]>maxVal){
                maxVal = values[i];
            }
        }

        if(maxVal == 0){
            break;
        }

        taken = 0;

        if(isPossible(0)){
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }
    }
}