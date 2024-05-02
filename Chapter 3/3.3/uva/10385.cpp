#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double t {};
double speeds[20][2] {};
int nContestants {};

double getTime(double rTime, int c){
    return rTime/speeds[c][0] + (t-rTime)/speeds[c][1];
}

double getAdvantage(double rTime){
    double cTime {getTime(rTime,0)};
    double bestCompetitor {getTime(rTime,1)};

    for(int i=2;i<nContestants;i++){
        double temp {getTime(rTime,i)};
        if(temp < bestCompetitor){
            bestCompetitor = temp;
        }
    }
    return bestCompetitor - cTime;
}

int main(){
    while(cin >> t){
        t *= 1000;
        cin >> nContestants;

        for(int i=nContestants-1;i>=0;--i){
            cin >> speeds[i][0] >> speeds[i][1];
            speeds[i][0] /= 3.6;
            speeds[i][1] /= 3.6;
        }

        double low {0};
        double high {t};
        double dist, m1, m2, v1, v2;
        while(high-low > 0.001){
            dist = (high-low)/3;
            m1 = low+dist;
            m2 = high-dist;
            v1 = getAdvantage(m1);
            v2 = getAdvantage(m2);

            if(v1 > v2){
                high = m2;
            } else {
                low = m1;
            }
        }

        long seconds {round(getAdvantage(low))};
        low = round(low/10)/100;
        if(seconds >= 0){
            cout << "The cheater can win by " << seconds << " seconds with r = "
                << fixed << setprecision(2) << low << "km and k = "
                << fixed << setprecision(2) << (t/1000-low) << "km.\n";
        } else {
            cout << "The cheater cannot win.\n";
        }
    }
}