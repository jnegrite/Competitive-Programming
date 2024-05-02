#include<iostream>
#include<vector>
#include<string>
#include<regex>

using namespace std;

regex reg("[^\\d]*");

string cleanUp(string s){
    return regex_replace(s,reg,"");
}

int main(){
    string s;

    int tc {0};
    while(true){
        int nTarget {};
        int nAnswer {};

        vector<string> sTarget {};
        vector<string> sAnswer {};
        string snTarget {};
        string snAnswer {};

        getline(cin, s);
        nTarget = stoi(s);

        if(nTarget == 0){
            break;
        }

        for(int i=0;i<nTarget;i++){
            getline(cin,s);
            sTarget.push_back(s);
            snTarget += cleanUp(s);
        }

        getline(cin, s);
        nAnswer = stoi(s);

        for(int i=0;i<nAnswer;i++){
            getline(cin,s);
            sAnswer.push_back(s);
            snAnswer += cleanUp(s);
        }

        string output {};

        if(nTarget != nAnswer){
            if(snTarget == snAnswer){
                output = "Presentation Error";
            } else {
                output = "Wrong Answer";
            }
        } else {
            bool completeMatch {true};

            for(int i=0;i<nAnswer;i++){
                if(sTarget[i] != sAnswer[i]){
                    completeMatch = false;
                }
            }

            if(completeMatch){
                output = "Accepted";
            } else if (snTarget == snAnswer){
                output = "Presentation Error";
            } else {
                output = "Wrong Answer";
            }
        }

        cout << "Run #" << ++tc << ": " << output << '\n';
    }
}