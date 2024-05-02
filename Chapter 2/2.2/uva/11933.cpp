#include<iostream>

using namespace std;

int main(){
    unsigned long num;

    while(cin>>num, num > 0){
        unsigned long values[2] {};
        int target  {0};
        unsigned long window{1};
        while(window != 0){
            while(window != 0 && ((num & window) == 0)){
                window <<= 1;
            }

            if(window != 0){
                values[target] |= (num & window);
                target = 1 - target;
                window <<= 1;
            }
        }
        

        cout << values[0] << ' ' << values[1] << '\n';
    }
}