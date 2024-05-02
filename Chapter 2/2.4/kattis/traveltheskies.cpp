#include<iostream>
#include<vector>
#include<malloc.h>

using namespace std;

struct Flight{
    int from {};
    int to {};
    long capacity {};

    Flight(int _from, int _to, long _capacity){
        from = _from;
        to = _to;
        capacity = _capacity;
    }
};

vector<vector<Flight>> flights {};
long newEntries[9][13] {};

int main(){
    int nAirports;
    int nDays;
    int nFlights;
    
    cin >> nAirports >> nDays >> nFlights;
    long *departing = (long*)calloc(nAirports+1,sizeof(long));
    long *arriving = (long*)calloc(nAirports+1,sizeof(long));
    

    //get data for flights
    for(int i=0;i<=nDays;i++){
        flights.push_back(vector<Flight> {});
    }

    int from, to, day;
    long capacity;
    for(int i=0;i<nFlights;++i){
        cin >> from >> to >> day >> capacity;
        Flight curr {from, to, capacity};
        flights[day].push_back(curr);
    }

    //get arrival dates
    int numStats = nAirports * nDays;
    int airportNum;
    long numPeople;
    for(int i=0;i<numStats;i++){
        cin >> airportNum >> day >> numPeople;
        newEntries[day][airportNum] += numPeople;
    }

    //simulation
    bool isOk {true};
    for(int day=1;day<=nDays;day++){
        //simulate arrivals
        for(int airport=1;airport<=nAirports;airport++){
            departing[airport] += newEntries[day][airport];
        }

        //check flights
        if(flights[day].size() == 0){
            continue;
        }

        //movements for flighs
        for(Flight f: flights[day]){
            if(f.capacity > departing[f.from]){
                isOk = false;
                goto exitSim;
            }

            departing[f.from] -= f.capacity;
            arriving[f.to] += f.capacity;
        }

        //simulate arrival
        for(int airport=1;airport<=nAirports;airport++){
            departing[airport] += arriving[airport];
            arriving[airport] = 0;
        }
    }

exitSim:
    if(!isOk){
        cout << "sub";
    }
    cout << "optimal\n";

    free(departing);
    free(arriving);
}