#include <iostream>

using namespace std;

int main(){
    int numObs {};
    cin >> numObs;

    long minutes{};
    long seconds{};
    long a, b;

    while(numObs--){
        cin >> a >> b;
        minutes += a;
        seconds += b;
    }

    if(minutes*60 >= seconds){
        printf("measurement error\n");
    } else {
        printf("%0.8lf\n",seconds/(60.0*minutes));
    }
}