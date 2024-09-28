#include<iostream>

using namespace std;

int main(){
    int nCases;
    int tc;
    string s;
    int numer, denom;

    cin >> nCases;
    while(nCases--){
        cin >> tc >> s;
        string ans;
        int pos = s.find('/');
        numer = stoi(s.substr(0,pos));
        denom = stoi(s.substr(pos+1));

        if (denom == 1){
            ans = "1/" + to_string(numer+1);
        } else {
            int reps {numer/denom};
            int rem = {numer%denom};

            int actualDenom = denom - rem;
            int newNumer = rem + actualDenom;
            actualDenom += (newNumer * reps);
            ans = to_string(newNumer) + "/" + to_string(actualDenom);
        }
        cout << tc << ' ' << ans << '\n';

    }
}