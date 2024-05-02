#include<iostream>

using namespace std;

struct Birthday{
    int year, month, day;
    Birthday(int _year, int _month, int _day){
        year = _year;
        month = _month;
        day = _day;
    }

    Birthday(){

    }
    bool operator<(Birthday o){
        if(year != o.year){
            return year < o.year;
        } else if (month != o.month){
            return month  < o.month;
        } else {
            return day < o.day;
        }
    }
};

struct Person {
    string name {};
    Birthday bday {};

    bool operator<(Person o){
        return bday < o.bday;
    }
};

int main(){
    int numPeople;
    cin >> numPeople;
    Person oldest{};
    Person youngest{};
    //get first person
    Person p {};
    cin >> p.name >> p.bday.day >> p.bday.month >> p.bday.year;
    oldest = p;
    youngest = p;
    for(int i=1;i<numPeople;i++){
        Person curr {};
        cin >> curr.name >> curr.bday.day >> curr.bday.month >> curr.bday.year;

        if(curr<oldest){
            oldest = curr;
        } else if(youngest < curr){
            youngest = curr;
        }
    }
    cout << youngest.name << '\n' << oldest.name << '\n';
}