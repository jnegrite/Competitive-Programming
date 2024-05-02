#include<iostream>
#include<string>

using namespace std;

int main(){
    int tc {};
    string s;
    cin >> tc;

    getline(cin,s);

    string keys {"BUSPFTM"};

    while(tc--){
        getline(cin,s);
        bool isInc {};
        bool isDec {};

        int counters[7] {};
        bool isValid {true};
        int prevVal {};

        //process first item
        int val {keys.find(s.at(0))};
        counters[val]++;
        prevVal = val;

        for(int i=1;isValid && i<s.length();i++){
            val = keys.find(s.at(i));
            
            if (val > prevVal){
                isInc = true;
            } else if (val < prevVal){
                isDec = true;
            }

            if(isInc && isDec){
                isValid = false;
            }

           counters[val]++;
           prevVal = val;

           if(counters[val] > 9){
            isValid = false;
           }
        }

        if(!isValid){
            cout << "error\n";
            continue;
        }

        //process
        bool isLeading{true};
        for(int i=6;i>=0;i--){
            if(counters[i] == 0){
                if(!isLeading){
                    cout << '0';
                }
            } else {
                isLeading = false;
                cout << counters[i];
            }
        }

        cout << '\n';

    }
}