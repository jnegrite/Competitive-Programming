#include<iostream>
#include<cmath>

using namespace std;

int main(){
    long long D;
    cin >> D;
    bool ansFound {false};
    for(long long lower=0;lower <= (D>>1);lower++){
        long long sum = D+lower*lower;
        long long upper {sqrt(sum)};

        if(upper*upper == sum){
            ansFound = true;
            cout << lower << ' ' << upper << '\n';
            break;
        }
    }

    if(!ansFound){
        cout << "impossible\n";
    }
}