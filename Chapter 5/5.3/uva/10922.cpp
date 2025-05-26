#include<iostream>

using namespace std;

pair<bool, int> check9degree(int value){
    if(value == 9){
        return {true,0};
    } else if (value < 9) {
        return {false, -1};
    }

    int currSum {0};
    while(value != 0){
        currSum += value%10;
        value /= 10;
    }

    auto res {check9degree(currSum)};
    return {res.first, res.second + 1};
}

pair<bool, int> check9degree(string s){
    int sumDigits {0};

    for(int i=s.length()-1;i>=0;--i){
        sumDigits += (s.at(i) - '0');
    }

    auto res {check9degree(sumDigits)};
    return {res.first, res.second + 1};
}


int main(){
    string s;

    while(cin >> s){
        if(s.length() == 1 && s.at(0) == '0'){
            break;
        }

        auto res {check9degree(s)};

        if(res.first){
            cout << s << " is a multiple of 9 and has 9-degree " << res.second << ".\n";
        } else {
            cout << s << " is not a multiple of 9.\n";
        }
    }



}