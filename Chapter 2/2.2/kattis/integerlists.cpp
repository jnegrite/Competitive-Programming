#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(){
    int numCases;
    string s;
    getline(cin,s);
    numCases = stoi(s);
    while(numCases--){
        string commands;
        long numIntegers;
        deque<int> values {};
        bool isFront {true};

        getline(cin, commands);
        getline(cin,s);
        numIntegers = stol(s);
        getline(cin,s);

        if(numIntegers == 1){
            int val {stol(s.substr(1,s.length()-2))};
            values.push_back(val);
        } else if (numIntegers>1) {
            long prev =1;
            int val;
            for(long i=1;i<numIntegers;i++){
                long curr = s.find(',',prev);
                val = stoi(s.substr(prev,curr-prev));
                values.push_back(val);
                prev = curr+1;
            }
            
            //last item
            values.push_back(stoi(s.substr(prev,s.length()-1-prev)));
        }
        
        bool isError {};
        for(auto ch:commands){
            if(ch == 'R'){
                isFront = !isFront;
            } else if (ch == 'D'){
                if(values.empty()){
                    isError = true;
                    break;
                }
                if(isFront){
                    values.pop_front();
                } else {
                    values.pop_back();
                }
            }
        }
        if(isError){
            cout << "error\n";
        } else {
            cout << '[';
            if(isFront){
                if(!values.empty()){
                    cout << values.front();
                    values.pop_front();
                }

                while(!values.empty()){
                    cout << ',' << values.front();
                    values.pop_front();
                }
            } else {
                if(!values.empty()){
                    cout << values.back();
                    values.pop_back();
                }

                while(!values.empty()){
                    cout << ',' << values.back();
                    values.pop_back();
                }
            }

            cout << "]\n";
        }
    }

}