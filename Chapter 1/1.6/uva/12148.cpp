#include <iostream>

using namespace std;

int monthSizes[13] {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeapYear(int year){
    if (year % 400 == 0){
        return true;
    } else if (year % 100 == 0){
        return false;
    } else if (year % 4 == 0){
        return true;
    } else {
        return false;
    }
}

struct Day {
    int year {};
    int month {};
    int day {};

    Day(int _year, int _month, int _day){
        year = _year;
        month = _month;
        day = _day;
    }

    Day(){
    }

    bool operator==(Day other){
        return year == other.year && month == other.month && day == other.day;
    }

    void operator=(Day other){
        year=other.year;
        month=other.month;
        day=other.day;
    }

    Day next(){
        if (isLeapYear(year)){
            monthSizes[2] = 29;
        } else {
            monthSizes[2] = 28;
        }

        if (day < monthSizes[month]){
            return Day(year,month,day+1);
        } else {
            int tempMonth {month+1};
            int tempYear {year};
            if(tempMonth==13){
                tempYear++;
                tempMonth=1;
            }
            return Day(tempYear,tempMonth,1);
        }
    }
};



int main(){
    int numItems {};
    long consumption {};
    int numRecords{};
    long totalConsumption {};
    Day curr {}, prev {};
    long prevConsumption {};
    bool skip {true};

    while(true){
        skip = true;
        numRecords = 0;
        totalConsumption = 0;
        int numItems;

        cin >> numItems;
        if(numItems==0){
            break;
        }

        for(int i=0;i<numItems;i++){
            cin >> curr.day >> curr.month >> curr.year >> consumption;

            if (!skip && (prev.next() == curr)){
                numRecords++;
                totalConsumption+= (consumption-prevConsumption);
            }
            prevConsumption = consumption;
            prev = curr;
            skip = false;
        }

        cout << numRecords << ' ' << totalConsumption << '\n';

        
    }
}