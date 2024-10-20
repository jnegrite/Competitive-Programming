#include<iostream>

using namespace std;

int main(){
    int a, b, c, d;
    int tc {0};

    while(cin >> a >> b >> c >> d){
        int disc = a*d - b*c;
        cout << "Case " << ++tc << ":\n";
        cout << d/disc << ' ' << -b/disc << '\n';
        cout << -c/disc << ' ' << a/disc << '\n';
    }
}