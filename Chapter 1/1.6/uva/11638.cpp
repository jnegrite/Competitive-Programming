#include<iostream>
#include<bitset>
#include<vector>

using namespace std;

long interval {};
long delay {};


int main(){
    long numCases {};
    cin >> numCases;

    for(long tc=1;tc<=numCases;tc++){
        long thresholds[4] {};
        bool triggered[4] {};
        bitset<8> settings {};
        unsigned int tempSettings {};

        cin >> interval >> delay;
        for(long i=0;i<4;i++){
            cin >> thresholds[i];
        }

        cin >> tempSettings;
        settings = static_cast<bitset<8>>(tempSettings);

        long k {};
        cin >> k;

        long currTime {-(delay+1)};
        
        bool isFirst{true};

        while(k--){
            long time, temperature;
            cin >> time >> temperature;
            
            if(isFirst){
                time++;
                isFirst = false;
            }

            long endTime {currTime + time};

            if(endTime >= 0 && (currTime < 0 || (currTime/interval != endTime/interval))){
                for(long i=0;i<4;i++){
                    if(!triggered[i] && settings.test(i)){
                        if((settings.test(4+i) && temperature > thresholds[i]) ||
                        (!settings.test(4+i) && temperature < thresholds[i]) ){
                            triggered[i] = true;
                        }
                    }
                }
            }

            currTime = endTime;
        }
        
        cout << "Case " << tc << ":";
        for(long i=0;i<4;i++){
            cout << ' ' << (triggered[i] ? "yes":"no");
        }
        cout << '\n';
    }
}