#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using ii = pair<long, long>;

struct cmpPair {
    bool operator()(const ii &a ,const ii &b) const {
        if(a.first != b.first){
            return a.first < b.first;
        } else {
            return a.second < b.second;
        }
    }
};

long m;
vector<ii> segments {};
vector<ii> usedSegments {};
long currPos {};
long maxSpan {};

int main(){
    int nCases;
    long a, b;
    scanf("%d\n",&nCases);
    for(int tc=0;tc<nCases;++tc){
        scanf("%d\n", &m);
        
        segments.clear();
        while(scanf("%ld %ld\n",&a,&b), a!= 0 || b!=0){
            segments.push_back(ii {a,b});
        }
        sort(segments.begin(),segments.end(),cmpPair());

        usedSegments.clear();
        currPos = 0;
        maxSpan = 0;
        ii candidate {};
        for(ii segment: segments){
            if(currPos >= m){
                break;
            }

retrySegment:
            //check if can consider
            if(segment.first <= currPos){
                if(segment.second >= maxSpan){
                    maxSpan = segment.second;
                    candidate = segment;

                    if(maxSpan >= m){
                        usedSegments.push_back(candidate);
                        currPos = maxSpan;
                        break;
                    }
                }
            } else if (maxSpan > currPos){
                //check if max span was extended
                usedSegments.push_back(candidate);
                currPos = maxSpan;
                goto retrySegment;
            } else {
                break;
            }
        }

        if(tc > 0){
            printf("\n");
        }

        if(currPos < m){
            printf("0\n");
        } else {
            printf("%ld\n",usedSegments.size());
            for(ii pr:usedSegments){
                printf("%ld %ld\n", pr.first, pr.second);
            }
        }
    }
}