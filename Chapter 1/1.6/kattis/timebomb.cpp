#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

map<string, int> m {};

void initMap(){
    m["**** ** ** ****"] = 0;
    m["  *  *  *  *  *"] = 1;
    m["***  *****  ***"] = 2;
    m["***  ****  ****"] = 3;
    m["* ** ****  *  *"] = 4;
    m["****  ***  ****"] = 5;
    m["****  **** ****"] = 6;
    m["***  *  *  *  *"] = 7;
    m["**** ***** ****"] = 8;
    m["**** ****  ****"] = 9;
}


int main(){
    vector<string> data {};
    string temp;
    initMap();

    //get data
    for(int i=0;i<5;i++){
        getline(cin, temp);
        data.push_back(temp);
    }

    int numDigits {(data[0].length() + 1)/4};
    long number {};
    bool isValid {true};
    for(int i=0;isValid && i<numDigits;i++){
        string key {};
        for(int j=0;j<5;j++){
            key += data[j].substr(i*4,3);
        }

        if(m.find(key) == m.end()){
            isValid = false;
        } else {
            number *= 10;
            number += m.find(key)->second;
        }
    }

    if(isValid && number%6==0){
        cout << "BEER!!\n";
    } else {
        cout << "BOOM!!\n";
    }
}