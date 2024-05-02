#include<iostream>

using namespace std;

struct Fraction {
    long numer {};
    long denom {};

    Fraction(long _numer, long _denom){
        numer = _numer;
        denom = _denom;
    }

    bool operator<(const Fraction &o) const {
        return numer*o.denom < denom*o.numer;
    }
};

int main(){
    int nCases;
    cin >> nCases;

    while(nCases--){
        int numEquations;
        int bestEq{1};
        Fraction bestVal {0,0};

        cin >> numEquations;

        for(int eq=1;eq<=numEquations;eq++){
            long a, b, c;
            cin >> a >> b >> c;
            long numer {b*b+4*a*c};
            long denom {4*a};

            Fraction curr {numer,denom};

            if(eq==1 || bestVal < curr){
                bestVal = curr;
                bestEq = eq;
            }
        }
        cout << bestEq << '\n';
    }
}