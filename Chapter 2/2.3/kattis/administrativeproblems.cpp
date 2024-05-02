#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

struct Record {
    long time {};
    char recordType {};
    string carName {};
    long value {};

    Record(){};
   
    bool operator<(const Record &o) const {
        return time < o.time;
    }

};

map<string,vector<long>> cars;
map<string,set<Record>> userRecords {};

int numCars;
int numRecords;

string user, carName;
long timeStamp, value;
char recordType;

int main(){
    int numCases;
    cin >> numCases;
    
    while(numCases--){
        cars.clear();
        userRecords.clear();
        cin >> numCars >> numRecords;
        while(numCars--){
            cin >> carName;
            vector<long>  temp{};
            temp.reserve(3);
            for(int i=0;i<3;i++){
                cin >> value;
                temp.push_back(value);
            }
            cars[carName] = temp;
        }

        while(numRecords--){
            cin >> timeStamp >> user >> recordType;

            if(userRecords.count(user) == 0){
                set<Record> temp {};
                userRecords[user] = temp;
            }
            
            Record curr {};
            curr.time = timeStamp;
            curr.recordType = recordType;

            switch(recordType){
                case 'p':
                    cin >> carName;
                    curr.carName = carName;
                    break;
                case 'r': case 'a':
                    cin >> value;
                    curr.value = value;
                    break;
            }

            userRecords[user].emplace(curr);
        }

        //processing per user
        for(auto user: userRecords){
            string currentCar {};
            long totalCost {};

            for(Record curr: user.second){
                if(curr.recordType == 'p'){
                    if(currentCar!=""){
                        totalCost = -1;
                        break;
                    }

                    currentCar = curr.carName;
                    totalCost += cars[currentCar][1];
                } else if(curr.recordType == 'r'){
                    if(currentCar==""){
                        totalCost = -1;
                        break;
                    }

                    totalCost += cars[currentCar][2] * curr.value;
                    currentCar = "";
                } else if(curr.recordType == 'a'){
                    if(currentCar==""){
                        totalCost = -1;
                        break;
                    }

                    long tempCost {cars[currentCar][0] * curr.value};
                    totalCost += tempCost/100;
                    if(tempCost%100 > 0){
                        totalCost++;
                    }
                }
            }

            if(currentCar!=""){
                totalCost = -1;
            }

            cout << user.first << ' ';
            if(totalCost == -1){
                cout << "INCONSISTENT\n";
            } else {
                cout << totalCost << '\n';
            }
        }
    }
}
