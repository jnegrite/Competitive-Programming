#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;

    while(cin >> s){

        int numBlank {};
        int numBaB {};

        if(s.at(s.length()-1) == '0'){
            ++numBlank;
            if(s.at(0) == '0'){
                ++numBaB;
            }
        }

        char prev {s.at(0)};
        for(int i=1;i<s.length();++i){
            if(prev == '0'){
                ++numBlank;
                if(s.at(i) == '0'){
                    ++numBaB;
                }   
            }
            prev = s.at(i);
        }

        int probShoot {numBaB * static_cast<int>(s.length())};
        int probRotate {numBlank * numBlank};

        if(probShoot == probRotate){
            cout << "EQUAL";
        } else if (probShoot > probRotate){
            cout << "SHOOT";
        } else {
            cout << "ROTATE";
        }
        cout << '\n';
    }
}