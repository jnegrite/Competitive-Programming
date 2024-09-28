#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int d, r, t;
    int b, c;

    cin >> d >> r >> t;

    b = d+1;
    c = (d*(d+1)>>1)-9-r-t;

    int disc = sqrt(b*b - (4*c));

    int x = (-b + disc)>>1;

    int actualR = (x+d)*(x+d+1)/2 - 6;
    cout << r - actualR << '\n';
    
}