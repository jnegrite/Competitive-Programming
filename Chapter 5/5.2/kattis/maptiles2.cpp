#include<iostream>

using namespace std;

int df[4][2] {
    {0,0},
    {1,0},
    {0,1},
    {1,1},
};

int x {0}, y {0};
int factor;
int idx;

int main() {
    string s;
    cin >> s;

    factor = (1<<(s.length() - 1));
    for(char ch: s){
        idx = (ch-'0');
        x += factor * df[idx][0];
        y += factor * df[idx][1];

        factor>>=1;
    }
    cout << s.length() << ' ' << x << ' ' << y << '\n';
}