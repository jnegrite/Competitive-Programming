#include<iostream>

using namespace std;

const string code {"VUCD"};

int n1, n2, n3;
string ops[3] {};

int decode(string s){
    int ans {0};
    for(char ch: s){
        ans <<= 2;
        ans += code.find(ch);
    }
    return ans;
}

int main(){
    int nCases;
    
    string s;

    cout << "COWCULATIONS OUTPUT\n";
    cin >> nCases;
    while(nCases--){
        cin >> s;
        n1 = decode(s);

        cin >> s;
        n2 = decode(s);

        for(int i=0;i<3;++i){
            cin >> s;
            switch(s.at(0)){
                case 'A':
                    n2 += n1;
                    break;
                case 'R':
                    n2 >>= 2;
                    break;
                case 'L':
                    n2 <<= 2;
            }
        }

        cin >> s;
        n3 = decode(s);
        
        if(n2 == n3){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    cout << "END OF OUTPUT\n";
}