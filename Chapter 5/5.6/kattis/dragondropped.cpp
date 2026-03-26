#include<iostream>

using namespace std;

string sSpike {"SPIKE"};
string sGabby {"GABBY"};
long long nSteps {};
long long spike {0};
long long gabby {0};
long long startOfCycle {0};
long long cycleLength {0};
pair<int,int> curr {};

pair<int,int> getInput(){
    int a, b;
    cin >> a >> b;
    return {a, b};
}

pair<int,int> movePerson(string p){
    cout << "NEXT " << p << '\n';
    cout.flush();
    return getInput();
}

pair<int,int> resetPerson(string p){
    cout << "RETURN " << p << '\n';
    cout.flush();
    return getInput();
}

void askPerson(string p){
    cout << "ASK " << p << '\n';
    cout.flush();
}

bool step_1(){

    while(true){

        //move gaby twice,
        for(int i=0;i<2;++i){
            ++gabby;
            curr = movePerson(sGabby);
            if(curr.first == 0){
                askPerson(sGabby);
                return true;
            } else if (curr.second == 1){
                return false;
            }
        }

        //move spike once
        curr = movePerson(sSpike);
        ++spike;
        if(curr.first == 0){
            askPerson(sSpike);
            return true;
        } else if(curr.second == 1){
            return false;
        }
    }
    
    return false;
}

int main(){

    cin >> nSteps;

    if(step_1()){
        return 0;
    }
    
    startOfCycle = spike;
    long cycleLength = gabby-spike;
    long maxIter = cycleLength/2 + 1;

    //step 3, move again until cycle length is found
    for(long iter=0;iter<maxIter;++iter){
        ++gabby;
        curr = movePerson(sGabby);
        if(curr.first == 0){
            askPerson(sGabby);
            return 0;
        }
        if(curr.second == 1){
            cycleLength = gabby - spike;
            break;
        }
    }

    //get target location
    long long targetGabby = {((nSteps-(startOfCycle))%cycleLength)+(startOfCycle)};
    while(targetGabby < gabby){
        targetGabby += cycleLength;
    }

    long long targetSpike = {((nSteps-(startOfCycle))%cycleLength)+startOfCycle};
    while(targetSpike < spike){
        targetSpike += cycleLength;
    }
    
    long long dGabby {targetGabby - gabby};
    long long dSpike {targetSpike - spike};

    if(dGabby <= dSpike){
        for(int i=0;i<dGabby;++i){
            movePerson(sGabby);
        }
        askPerson(sGabby);
    } else {
        for(int i=0;i<dSpike;++i){
            movePerson(sSpike);
        }
        askPerson(sSpike);
    }
    return 0;
}