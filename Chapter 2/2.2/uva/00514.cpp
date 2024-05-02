#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){

    string s;
    long numCars;
    long curr;

    while(cin >> numCars, numCars > 0){
        bool isOk {true};
        long target {};
        
        while(isOk){
            stack<long> cars {};
            long nxtCar {1};
            bool ranOut{false};
            for(int i=0;i<numCars;i++){
                cin >> target;
                if(target == 0){
                    isOk = false;
                    break;
                }

                while(target >= nxtCar){
                    cars.emplace(nxtCar++);
                }

                if(!cars.empty() && cars.top() == target){
                    cars.pop();
                } else {
                    ranOut = true;
                }
            }
            
            if(isOk){
                if(!ranOut && cars.empty() && nxtCar == numCars+1){
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
            }
        }

        cout << '\n';
    }
}