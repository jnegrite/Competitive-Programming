#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

struct Constraint{
    int a{};
    int b{};
    int distance{};

    Constraint(int _a, int _b, int _distance){
        a = _a;
        b = _b;
        distance = _distance;
    }
};

int main(){
    int n, m, a, b, c;
    int permu[8] {};
    while(scanf("%d %d\n",&n,&m),n!=0 || m!=0){
        long configs {0};

        for(int i=0;i<n;i++){
            permu[i] = i;
        }

        if(m==0){
            configs = 1;
            for(int i=2;i<=n;i++){
                configs *= i;
            }
        } else {
            vector<Constraint> constraints {};
            while(m--){
                scanf("%d %d %d\n", &a, &b, &c);
                constraints.push_back(Constraint{a,b,c});
            }

            do{
                bool valid{true};

                for(int i=0;valid && i<constraints.size();i++){
                    Constraint curr = constraints[i];
                    int dist {abs(permu[curr.a] - permu[curr.b])};
                    if(curr.distance > 0 && dist > curr.distance){
                        valid = false;
                    } else if(curr.distance < 0 && dist < abs(curr.distance)){
                        valid = false;
                    }
                }
                if(valid){
                    configs++;
                }
            } while(next_permutation(permu,permu+n));
        }

        printf("%ld\n",configs);
    }
}