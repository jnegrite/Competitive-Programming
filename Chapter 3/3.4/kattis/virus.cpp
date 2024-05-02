#include<iostream>

using namespace std;

int main(){
    string sOrig{};
    string sFin{};

    cin >> sOrig >> sFin;

    long oFrom {0};

    auto oTo {sOrig.length()-1};
    auto fTo {sFin.length()-1};

    //exhaust the first part
    while(oFrom <= oTo && oFrom <= fTo && sOrig.at(oFrom) == sFin.at(oFrom)){
        ++oFrom;
    }

    //check the last part
    while(oFrom <= oTo && oFrom <= fTo && sOrig.at(oTo) == sFin.at(fTo)){
        --oTo;
        --fTo;
    }

    cout << fTo - oFrom + 1 << '\n';
}