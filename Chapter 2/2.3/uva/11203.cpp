#include<iostream>

using namespace std;

int main(){
    int numCases;
    cin >> numCases;
    string s;

    while(numCases--){
        cin >> s;

        bool isOk {true};
        int counts[3] {};
        int pos {0};
        for(char ch:s){
            if(ch=='?'){
                counts[pos]++;
            } else if (pos==0 && ch=='M'){
                pos++;
            } else if (pos==1 && ch=='E'){
                pos++;
            } else {
                isOk = false;
                break;
            }
        }

        if(isOk){
            for(int i=0;i<3;i++){
                if(counts[i] == 0){
                    isOk = false;
                    break;
                }
            }
        }

        if(isOk && counts[0] + counts[1] != counts[2]){
            isOk = false;
        }

        cout << (isOk?"":"no-") << "theorem\n";
    }
}