#include<iostream>

using namespace std;

int main(){
    long numCars;
    long carNumber;
    long posDiff;
    long carPos;
    while(true){
        cin >> numCars;
        if(numCars == 0){
            break;
        }
        long cars[10001] {};
        bool isOk {true};

        for(long i=0;i<numCars;i++){
            cin >> carNumber >> posDiff;
            if(isOk){
                carPos = i + posDiff;
                if(carPos < 0 || carPos >= numCars || cars[carPos] != 0){
                    isOk = false;
                } else {
                    cars[carPos] = carNumber;
                }
            }
        }

        if(isOk){
            cout << cars[0];
            for(long i=1;i<numCars;i++){
                cout << ' ' << cars[i];
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }


    }
}