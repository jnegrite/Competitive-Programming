#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getRepr(pair<string,string> dt){
    int pos {0};

    if(dt.first == dt.second){
        return dt.first;
    }
    for(;dt.first.at(pos) == dt.second.at(pos);pos++){}

    return dt.first + "-" + dt.second.substr(pos);
}


int main(){
    int tc {0};
    long numItems{};
    string s;
    long currVal {}, prevVal {};
    string startStr {}, endStr{};
    while(cin >> numItems){
        if(numItems == 0){
            break;
        }
        vector<pair<string,string>> ranges {};

        //get first number
        cin >> startStr;
        prevVal = stol(startStr.substr(1));
        endStr = startStr;

        for(int i=1;i<numItems;i++){
            cin >> s;
            currVal = stod(s.substr(1));

            if(prevVal+1 == currVal){
                endStr = s;
            } else {
                pair<string,string> temp {startStr,endStr};
                ranges.push_back(temp);
                startStr = s;
                endStr = s;
            }

            prevVal = currVal;
        }

        pair<string,string> temp {startStr,endStr};
        ranges.push_back(temp);

        cout << "Case " << ++tc << ":\n";

        for(auto dt: ranges){
            cout << getRepr(dt) << '\n';
        }

        cout << '\n';

    }

}