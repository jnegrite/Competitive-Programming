#include<iostream>

using namespace std;

int main(){
    int tc;
    cin >> tc;

    while(tc--){
        long limit, numPoints;
        int currDistance {};
        int totalDistance {};
        int totalWeight {};
        int currWeight {};
        int incDist {};
        cin >> limit >> numPoints;
        
        for(int i=0;i<numPoints;i++){
            cin >> currDistance >> currWeight;
            int caseNum {totalWeight + currWeight - limit};
            
            if(caseNum < 0){
                //can still fit
                totalWeight += currWeight;
            } else if (caseNum == 0){
                totalDistance += (2*currDistance);
                totalWeight = 0;
            } else {
                totalDistance += (2*currDistance);
                totalWeight = currWeight;
            }
        }

        if(totalWeight > 0){
            totalDistance += (2*currDistance);
        }
            
        cout << totalDistance << '\n';
    }
}