#include<cstdio>
#include<cmath>


using namespace std;

using ld = long double;
ld d {};
ld s {};

ld getLength(ld a){
    ld val {d/a};
    return a * (exp(val) - exp(-val));
}

int main(){
    scanf("%Lf %Lf\n",&d,&s);

    ld low {0.01};
    ld high {100.00};

    d /= 2.0;
    ld mid;
    while(true){
        ld left {high + s};
        ld val {d/high};
        ld right {high * (exp(val) + exp(-val)) / 2.0};

        if(left < right){
            low = high;
            high *= 2.0;
        } else {
            break;
        }
    }
    
    while(true){
        ld vLow {getLength(low)};
        ld vHigh {getLength(high)};

        if(abs(vLow-vHigh) < 1e-7){
            break;
        }

        ld mid {(low+high)/2.0};
        ld left {mid + s};
        ld val {d/mid};
        ld right {mid * (exp(val) + exp(-val)) / 2.0};

        if(left < right){
            low = mid;
        } else {
            high = mid;
        }
    }
    ld val {getLength(low)};
    printf("%.08Lf\n",val);
}