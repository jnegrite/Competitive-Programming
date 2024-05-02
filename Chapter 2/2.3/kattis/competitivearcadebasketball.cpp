#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    long nParticipants;
    long nPoints;
    long nRecords;
    cin >> nParticipants >> nPoints >> nRecords;

    string s;
    long curr, prev;
    unordered_map<string, long> points {};
    for(long i=0;i<nParticipants;i++){
        cin >> s;
        points[s] = 0;
    }

    bool hasWinner {false};
    for(long i=0;i<nRecords;i++){
        cin >> s >> curr;
        prev = points[s];
        points[s] += curr;
        if(prev < nPoints && points[s] >= nPoints){
            hasWinner = true;
            cout << s << " wins!\n";
        }
    }

    if(!hasWinner){
        cout << "No winner!\n";
    }
}
