#include<iostream>

using namespace std;

int main(){
    int numCases;
    cin >> numCases;
    string s;
    long posFront{};
    long posBack{};
    unsigned long long len;
    unsigned long long factor {1000000007};
    for(int tc=1;tc<=numCases;tc++){
        cin >> s;
        len = s.length();
        unsigned long long val {};
        if(len%2==1){
            if(s.at(len/2) == '1'){
                val = 1;
            }
            posFront = len/2 - 1;
            posBack = len/2 + 1;
        } else {
            posFront = len/2-1;
            posBack = posFront + 1;
        }

        //actual looping
        while(posFront >= 0){
            int values[2] {};
            if(s.at(posFront) == '1' && s.at(posBack) == '1'){
                values[0] = 1;
                values[1] = 1;
            } else if (s.at(posFront) == '1' || s.at(posBack) == '1'){
                values[0] = 1;
            }

            //do looping 
            for(int i=0;i<2;i++){
                val <<= 1;
                val %= factor;
                val += values[i];
                val %= factor;
            }

            --posFront;
            ++posBack;
        }

        cout << "Case #" << tc << ": " << val << '\n';
    }
}