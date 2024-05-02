#include<iostream>

using namespace std;

int main(){
    long a, b;
    while(cin >> a >> b, a != 0 || b != 0){
        int numCarry {0};
        int carry {0};
        while(a>0 || b >0){
            carry = (carry + a%10 + b%10)/10;
            if(carry == 1){
                numCarry++;
            }
            a/=10;
            b/=10;
        }

        if(numCarry == 0){
            cout << "No carry operation.";
        } else if (numCarry == 1){
            cout << "1 carry operation.";
        } else {
            cout << numCarry << " carry operations.";
        }
        cout << '\n';
    }
}