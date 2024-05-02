#include<iostream>
#include<map>
#include<set>
#include<string>
#include<sstream>

using namespace std;

int main(){
    string s;
    string temp;
    while(getline(cin,s)){
        auto strIn = stringstream(s);
        
        set<string> unseenDomain {};
        set<string> unseenCodomain {};
        set<string> seenCodomain {};

        map<string,string> knownVals {};
        bool repeatDomain {false};
        bool repeatCodomain {false};

        //remove domain
        strIn >> temp;

        while(strIn >> temp){
            unseenDomain.emplace(temp);
        }

        //get codomain
        getline(cin,s);
        strIn = stringstream(s);
        //remove codomain
        strIn >> temp;
    
        while(strIn >> temp){
            unseenCodomain.emplace(temp);
        }

        getline(cin,s);
        strIn = stringstream(s);

        int numValues;
        strIn >> numValues;

        while(numValues--){
            getline(cin,s);
            strIn = stringstream(s);
            string domain;
            string codomain;
            strIn >> domain >> temp >> codomain;

            //check if it is in the known values
            if(knownVals.find(domain) != knownVals.end()){
                if (codomain != knownVals[domain]){
                    repeatDomain = true;
                } else {
                    continue;
                }
            }

            //check if value was already used before
            if(seenCodomain.find(codomain) != seenCodomain.end()){
                repeatCodomain = true;
            }

            //clean up
            seenCodomain.emplace(codomain);
            unseenDomain.erase(domain);
            unseenCodomain.erase(codomain);
            knownVals[domain] = codomain;
        }

        bool surjective {unseenCodomain.size() == 0};
        bool injective {!repeatCodomain};

        if(repeatDomain){
            cout << "not a function";
        } else if(surjective && injective){
            cout << "bijective";
        } else if (surjective){
            cout << "surjective";
        } else if (injective){
            cout << "injective";
        } else {
            cout << "neither injective nor surjective";
        }

        cout << '\n';
    }
}