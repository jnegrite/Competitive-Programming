#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        string name {};
        int numRecords {};
        double total {};
        auto strIn {stringstream(s)};

        string temp{};
        while(strIn >> temp){
            if(isalpha(temp.at(0))){
                if(name.length() != 0){
                    name += " ";
                }
                name += temp;
            } else {
                total += stod(temp);
                numRecords++;
            }
        }

        printf("%.6lf %s\n",total/numRecords,name.c_str());
    }
}