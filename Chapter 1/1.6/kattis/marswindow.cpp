#include <iostream>

using namespace std;

int main(){
    long year {};
    cin >> year;
    long months {(year-2018)*12+22};
    cout << ((months/26 != (months+12)/26)? "yes" : "no") << '\n';
}