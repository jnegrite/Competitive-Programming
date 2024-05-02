#include <iostream>

using namespace std;

int main(){
    char month[20];
    int day, year, fromHr, fromMn, toHr, toMn;
    while(scanf("%s %d %d %d:%d %d:%d\n",month,&day,&year,&fromHr,&fromMn,&toHr,&toMn) != EOF){
        int hours {toHr - fromHr};
        int minutes {toMn - fromMn};

        if(minutes < 0){
            minutes += 60;
            --hours;
        }

        printf("%s %d %d %d hours %d minutes\n",month,day,year,hours,minutes);
    }
}