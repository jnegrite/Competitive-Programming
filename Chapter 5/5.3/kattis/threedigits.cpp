#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

using llu = long long unsigned;

llu countFactors(llu val, llu divisor){
    if(val == 0){
        return 0;
    }

    llu curr {val/divisor};

    return (curr) + countFactors(curr,divisor);
}

llu powl3(llu base, int power){
    if(power == 0){
        return 1;
    }

    if(power%2 == 0){
        llu curr {powl3(base,power/2)};
        return {(curr * curr)%1000};
    } else {
        return (base * powl3(base,power-1))%1000;
    }
}

vector<llu> f {};

int main(){
    llu val;
    //initialize the f vector
    f.assign(1000,0);
    f[0] = 1;
    for(int i=1;i<1000;++i){
        if(i%2==0 || i%5==0){
            f[i] = f[i-1];
        } else {
            f[i] = (f[i-1] * i)%1000;
        }
    }
   
    while(scanf("%llu\n",&val)!=EOF){

        llu f2 {countFactors(val,2)};
        llu f5 {countFactors(val,5)};

        //initial answer
        llu ans {powl3(2,f2-f5)};

        //initialize quueue with all 2s
        queue<llu> q {};
        for(llu i{1};i<=val;i<<=1){
            q.push(i);
        }

        while(!q.empty()){
            llu curr {q.front()};
            q.pop();

            ans *= f[(val/curr)%1000];
            ans %= 1000;

            curr *= 5;
            if(curr <= val){
                q.push(curr);
            }
        }
        
        printf((val<=6?"%Lu\n":"%03Lu\n"),ans%1000);
    }
}