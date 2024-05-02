#include<iostream>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;

struct Timestamp{
    int month {};
    int day {};
    int hour {};
    int minute {};

    Timestamp(){}

    bool operator<(const Timestamp& o) const {
        if(month != o.month){
            return month < o.month;
        } else if (day != o.day){
            return day < o.day;
        } else if (hour != o.hour){
            return hour < o.hour;
        } else {
            return minute < o.minute;
        }
    }
};

struct Record{
    string plate {};
    Timestamp ts {};
    string recordType {};
    long distance {};

    Record(){}
    Record(string _plate, int _month, int _day, int _hour, int _minute, string _recordType, long _distance){
        plate = _plate;
        ts.month = _month;
        ts.day = _day;
        ts.hour = _hour;
        ts.minute = _minute;
        recordType = _recordType;
        distance = _distance;
    }

    bool operator<(const Record &o) const {
        return ts < o.ts;
    }
};

int main(){
    long numCases;
    string s;
    getline(cin,s);
    numCases = stoi(s);
    getline(cin,s);
    char plateNum[21];
    char recordType[6];
    int month, day, hour, minute;
    long distance;
    map<string, set<Record>> records {};

    for(long tc=0;tc<numCases;tc++){
        records.clear();

        //get data for hours
        long hourlyCost[24] {};
        getline(cin,s);
        auto strIn{stringstream(s)};
        for(int i=0;i<24;i++){
            strIn >> hourlyCost[i];
        }

        //get data for entries/exists
        while(getline(cin,s) && !s.empty()){
            auto strIn {istringstream(s)};
            string sTime;
            strIn >> plateNum >> sTime >> recordType >> distance;
            month = stoi(sTime.substr(0,2));
            day = stoi(sTime.substr(3,2));
            hour = stoi(sTime.substr(6,2));
            minute = stoi(sTime.substr(9,2));
            Record curr {plateNum,month,day,hour,minute,recordType,distance};
            if(records.count(plateNum) == 0){
                set<Record> temp {};
                records[plateNum] = temp;
            }

            records[plateNum].emplace(curr);
        }

        //process data

        if(tc>0){
            cout << '\n';
        }

        for(auto au: records){
            string plateNum {au.first};
            auto recFrom {au.second.begin()};
            auto recTo {++(au.second.begin())};
            long totalBill {0};
            while(recTo != au.second.end()){
                if(recFrom->recordType == "enter" && recTo->recordType == "exit"){
                    totalBill += 100 + (hourlyCost[recFrom->ts.hour] * abs(recFrom->distance - recTo->distance));
                }
                recFrom++;
                recTo++;
            }

            if(totalBill > 0){
                totalBill += 200;
                cout << plateNum << " $" << totalBill/100 << '.' << setfill('0') << setw(2) << totalBill%100 << '\n';
            }

            
        }
    }
}