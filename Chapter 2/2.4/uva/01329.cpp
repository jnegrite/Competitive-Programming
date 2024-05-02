#include<cstdio>
#include<vector>
#include<string>
#include<stack>

using namespace std;

typedef vector<long> vi;

int main(){
    long nCases;
    scanf("%ld\n",&nCases);
    while(nCases--){
        vi p{};
        char ch;
        long nNodes, from, to;
        scanf("%ld\n",&nNodes);

        for(long i=0;i<=nNodes;i++){
            p.push_back(i);
        }

        while(scanf("%c",&ch),ch!='O'){
            if(ch=='E'){
                scanf(" %ld\n",&from);
                long cnt {0};
                while(p[from] != from){
                    cnt += abs(from - p[from]) % 1000;
                    from = p[from];
                }
                printf("%ld\n",cnt);
            } else if (ch=='I'){
                scanf(" %ld %ld\n",&from,&to);
                stack<long> trail {};
                trail.push(to);
                trail.push(from);
                long prev = from;
                
                //follow trail to previous
                while(p[prev] != prev){
                    prev = p[prev];
                    trail.push(prev);    
                }

                while(!trail.empty()){
                    p[prev] = trail.top();
                    prev = trail.top();
                    trail.pop();
                }
            }
        }
    }
}