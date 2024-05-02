#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int hour, mn, angle;
    while(true){
        scanf("%d:%d\n",&hour,&mn);
        if(hour==0 && mn==0){
            break;
        }

        hour = (hour%12) * 60 + mn;
        mn*=12;

        angle = abs(mn-hour);
        if(angle > 360){
            angle = 720 - angle;
        }
        printf("%.3f\n",angle/2.0);
    }


}