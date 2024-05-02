#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    string name1, name2;
    int numMatches;
    string sMatch;
    getline(cin, sMatch);
    auto strIn {stringstream(sMatch)};
    if(strIn >> name1){
        if(strIn >> name2){

        }
    }
    getline(cin, sMatch);
    numMatches = stoi(sMatch);

    while(numMatches--){
        bool isValid {true};
        int points[2] {};
        getline(cin,sMatch);
        
        auto strIn {istringstream(sMatch)};
        int setsA, setsB;
        int setNum {};
        string sGame {};
        while(strIn >> sGame){
            setNum++;

            if(points[0] == 2 || points[1] ==2){
                isValid = false;
            }

            auto loc {sGame.find(':')};
            setsA = stoi(sGame.substr(0,loc));
            setsB = stoi(sGame.substr(loc + 1));
            
            if((setsA >= 6) && (setsB + 2 <= setsA) && (setNum > 2 || setsA <= 7)){
                //normal win for A
                points[0]++;
            } else if ((setsB >= 6) && (setsA + 2 <= setsB) && (setNum > 2 || setsB <= 7)){
                //normal win for B
                points[1]++;
            } else if (setNum <= 2){
                if(setsA == 7 && setsB == 6){
                    points[0]++;
                } else if (setsA == 6 && setsB == 7){
                    points[1]++;
                } else {
                    isValid = false;
                }
            } else {
                isValid = false;
            }
        }

        if(
            (name1=="federer" && points[1] > 0) || 
            (name2=="federer" && points[0] > 0) || 
            (points[0] < 2 && points[1] < 2)){
            isValid = false;
        }

        cout << (isValid?"da":"ne") << '\n';
    }
    
}