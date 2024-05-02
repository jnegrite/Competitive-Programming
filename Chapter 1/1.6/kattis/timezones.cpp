#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

struct Time {
    int hour {};
    int minutes {};

    Time(int _hour, int _minutes){
        hour = _hour;
        minutes = _minutes;
    }

    Time(){
        hour = 0;
        minutes = 0;
    }

    void simplify(){
        while(minutes >= 60){
            minutes -= 60;
            hour++;
        }

        while(minutes < 0){
            minutes += 60;
            hour--;
        }

        while(hour > 24){
            hour -= 24;
        }

        while(hour <= 0){
            hour += 24;
        }
    }

    void operator+=(Time o){
        hour += o.hour;
        minutes += o.minutes;
    }

    void operator-=(Time o){
        hour -= o.hour;
        minutes -= o.minutes;
    }

    string repr(){
        if(minutes == 0 && (hour == 0 || hour == 24)){
            return "midnight";
        } else if (minutes == 0 && hour == 12){
            return "noon";
        } else {
            int actualHour = hour;
            while (actualHour <= 0){
                actualHour += 12;
            }
            while(actualHour > 12){
                actualHour -= 12;
            }
            string output = to_string(actualHour) +  ":" + (minutes<10? "0":"") + to_string(minutes) + " ";
            if (hour >= 12 && hour < 24){
                output += "p.m.";
            } else {
                output += "a.m.";
            }
            return output;
        }
    }
};

int main(){
    string s, temp;

    map<string,Time> tz {};
    tz["UTC"] = Time(0,0);
    tz["GMT"] = Time(0,0);
    tz["BST"] = Time(1,0);
    tz["IST"] = Time(1,0);
    tz["WET"] = Time(0,0);
    tz["WEST"] = Time(1,0);
    tz["CET"] = Time(1,0);
    tz["CEST"] = Time(2,0);
    tz["EET"] = Time(2,0);
    tz["EEST"] = Time(3,0);
    tz["MSK"] = Time(3,0);
    tz["MSD"] = Time(4,0);
    tz["AST"] = Time(-4,0);
    tz["ADT"] = Time(-3,0);
    tz["NST"] = Time(-3,-30);
    tz["NDT"] = Time(-2,-30);
    tz["EST"] = Time(-5,0);
    tz["EDT"] = Time(-4,0);
    tz["CST"] = Time(-6,0);
    tz["CDT"] = Time(-5,0);
    tz["MST"] = Time(-7,0);
    tz["MDT"] = Time(-6,0);
    tz["PST"] = Time(-8,0);
    tz["PDT"] = Time(-7,0);
    tz["HST"] = Time(-10,0);
    tz["AKST"] = Time(-9,0);
    tz["AKDT"] = Time(-8,0);
    tz["AEST"] = Time(10,0);
    tz["AEDT"] = Time(11,0);
    tz["ACST"] = Time(9,30);
    tz["ACDT"] = Time(10,30);
    tz["AWST"] = Time(8,0);
    
    getline(cin, s);
    int numInputs;
    stringstream(s) >> numInputs;
    
    while(numInputs--){
        
        string tzFrom, tzTo;
        Time curr {0,0};
        int hrFrom, minFrom;
        getline(cin, s);
        auto strIn {stringstream(s)};
        
        strIn >> temp;
        if(temp == "noon"){
            curr.hour = 12;
            curr.minutes = 0;
        } else if (temp == "midnight"){
            curr.hour = 0;
            curr.minutes = 0;
        } else {
            auto pos {temp.find(':')};
            curr.hour = stoi(temp.substr(0,pos));
            curr.minutes = stoi(temp.substr(pos+1));

            //handle am/pm
            strIn >> temp;
            if((curr.hour < 12 && temp == "p.m.") || (curr.hour == 12 && temp=="a.m.")){
                curr.hour += 12;
            }
        }

        strIn >> tzFrom >> tzTo;
        curr -= tz[tzFrom];
        curr += tz[tzTo];
        curr.simplify();
        cout << curr.repr() << '\n';
    }


    
    
    
}