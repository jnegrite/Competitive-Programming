#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<string>

using namespace std;

int nValues;
long values[200]{};
int p[200] {};
long L[200] {};
int L_id[200] {};
int lisEnd = 0;
int k = 0;
int valCount {};

void printSubSeq(int pos, string &output){
    ++valCount;
    output = " " + to_string(values[pos]) + output;

    if(p[pos] != -1){
        printSubSeq(p[pos], output);
    }
}

int main(){
    while(scanf("%d",&nValues),nValues > 0){
        lisEnd = 0;
        k = 0;

        for(int i=0;i<nValues;i++){
            scanf("%ld",&values[i]);
        }

        memset(p,-1,sizeof(p));

        for(int i=0;i<nValues;i++){
            int pos = lower_bound(L,L+k,values[i]) - L;
            L[pos] = values[i];
            L_id[pos] = i;
            p[i] = pos ? L_id[pos-1] : -1;

            if(pos >= k-1){
                lisEnd = i;
                if(k==pos){
                    ++k;
                }
            }
        }
        valCount = 0;
        string output {""};
        printSubSeq(lisEnd, output);
        printf("%d%s\n", valCount, output.c_str());

    }
}