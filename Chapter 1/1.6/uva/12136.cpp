#include<iostream>

using namespace std;

struct Time {
    int hour {};
    int minute {};

    Time(int _hour, int _minute){
        hour = _hour;
        minute = _minute;
    }

    Time(){
    }

    bool operator<(Time other){
        return hour < other.hour || (hour==other.hour && minute < other.minute);
    }
};

int main(){
    int numCases;
    scanf("%d\n",&numCases);

    for(int tc=1;tc<=numCases;tc++){
        Time aFrom{}, aTo{}, bFrom{}, bTo{};
        scanf("%02d:%02d %02d:%02d\n",&aFrom.hour,&aFrom.minute,&aTo.hour,&aTo.minute);
        scanf("%02d:%02d %02d:%02d\n",&bFrom.hour,&bFrom.minute,&bTo.hour,&bTo.minute);

        bool noConflict {bTo < aFrom || aTo < bFrom};

        cout << "Case " << tc << ": " << (noConflict?"Hits":"Mrs") << " Meeting\n";
    }
}