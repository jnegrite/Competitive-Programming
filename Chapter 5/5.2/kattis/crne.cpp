#include<iostream>

using namespace std;

int main(){
    long long val;
    long long rows;
    long long cols;

    cin >> val;
    val += 2;
    rows = val/2;
    cols = val-rows;
    cout << rows * cols << '\n';
}