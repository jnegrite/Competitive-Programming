#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int totalBudget;
int totalPower;
int nDrinks;
string s;

string drinkNames[8] {};
int drinkPower[8] {};
int drinkCost[8] {};
int counts[8] {};

int memo[8][1001][601] {};

int dp(int pos, int remBudget, int remPower){

    if(remBudget < 0 || remPower < 0){
        return 0;
    }

    if(pos==nDrinks){
        if(remBudget == 0 && remPower==0){
            return 1;
        } else {
            return 0;
        }
    }

    auto &curr {memo[pos][remBudget][remPower]};

    if(curr != -1){
        return curr;
    }

    curr = 0;
    //try not putting
    int temp {dp(pos+1,remBudget,remPower)};
    if(temp == 1){
        return curr = 1;
    }

    return curr = dp(pos,remBudget-drinkCost[pos],remPower-drinkPower[pos]);
}

int main(){
    double d;
    cin >> d;
    totalBudget = int(round(d*100));

    cin >> d;
    totalPower = int(round(d*30));

    cin >> nDrinks;
    string s;
    for(int i=0;i<nDrinks;++i){
        cin >> drinkNames[i];
        cin >> d >> s;
        if(s == "1/1"){
            drinkPower[i] = int(d * 30);
        } else if (s=="1/2"){
            drinkPower[i] = int(d * 15);
        } else if (s=="1/3"){
            drinkPower[i] = int(d * 10);
        }
        cin >> d;
        drinkCost[i] = int(d * 100);
    }

    memset(memo,-1,sizeof(memo));
    int ans {dp(0,totalBudget,totalPower)};
    if (ans == 0){
        cout << "IMPOSSIBLE\n";
    } else {
        memset(counts,0,sizeof(counts));
        int currPos {0};
        while(totalBudget > 0){
            if(currPos < nDrinks && dp(currPos+1,totalBudget,totalPower)){
                ++currPos;
            } else {
                counts[currPos]++;
                totalBudget -= drinkCost[currPos];
                totalPower -= drinkPower[currPos];
            }
        }

        for(int i=0;i<nDrinks;++i){
            if(counts[i] > 0){
                cout << drinkNames[i] << ' ' << counts[i] << '\n';
            }
        }
    }
}