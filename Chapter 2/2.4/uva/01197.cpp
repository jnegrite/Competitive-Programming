#include<cstdio>
#include<vector>

using namespace std;

typedef vector<long> vi;

vi p, rk, sz;

long getParent(long i){
    return p[i] == i ? i : p[i]=getParent(p[i]);
}

int main(){
    long nStudents;
    int nGroups;

    while(scanf("%ld %d\n",&nStudents,&nGroups), nStudents!=0 || nGroups != 0){
        p.clear();
        for(long i=0;i<nStudents;i++){
            p.push_back(i);
        }
        rk.assign(nStudents,0);
        sz.assign(nStudents,1);

        while(nGroups--){
            long nMembers;
            long mem1, memCurr, p1, pCurr;
            scanf("%ld",&nMembers);
            
            //process first item
            if(nMembers > 0){
                scanf(" %ld",&mem1);
            }

            for(long i=1;i<nMembers;i++){
                p1 = getParent(mem1);
                scanf(" %ld",&memCurr);
                pCurr = getParent(memCurr);
            

                if(rk[pCurr] > rk[p1]){
                    swap(mem1,memCurr);
                    swap(p1,pCurr);
                }

                if(p1 != pCurr){
                    p[pCurr] = p[p1];
                    sz[p1] += sz[pCurr];
                }

                if(rk[p1] == rk[pCurr]){
                    rk[p1]++;
                }
            }
        }

        printf("%ld\n",sz[getParent(0)]);
    }
}