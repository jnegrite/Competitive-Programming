#include<iostream>

using namespace std;

int sumDigits(long val){
    long sum {};

    while(val > 0){
        sum += val%10;
        val /= 10;
    }
    return sum;
}

int main(){
    long n;

    while(cin >> n, n !=0){
        int target {sumDigits(n)};
        int ans {11};
        while(sumDigits(ans*n) != target){
            ++ans;
        }
        cout << ans << '\n';
    }
}