#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
using ii = pair<double,double>;

double l, w;
long n;

struct cmpSegments {
    bool operator()(const ii &a, const ii b) const {
        if(a.first != b.first){
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    }
};

vector<ii> segments {};
long usedSegments {};
double currPos;
double maxSpan;
double p, r;
double span;
double w2;
double wHalf{};
int main(){
    while(cin >> n >> l >> w){
        wHalf = w/2.0;
        w2 = wHalf*wHalf;
        segments.clear();
        segments.reserve(n);
        for(long i=0;i<n;i++){
            cin >> p >> r;
            if(r<=wHalf){
                continue;
            }
            span = sqrt(r*r - w2);
            segments.push_back(ii {p-span, p+span});
        }
        sort(segments.begin(), segments.end(),cmpSegments());

        currPos = 0;
        maxSpan = 0;
        usedSegments = 0;
        for(auto it {segments.begin()};it!=segments.end() && currPos < l;){
            //check if cannot be placed
            if(it->first > currPos){
                if(maxSpan > currPos){
                    usedSegments++;
                    currPos = maxSpan;
                } else {
                    break;
                }
            } else {
                //for the case when it can be placed 
                if(it->second > maxSpan){
                    maxSpan = it->second;
                    if(maxSpan >= l){
                        usedSegments++;
                        currPos = maxSpan;
                    }
                }
                ++it;
            }
        }

        if(currPos < l){
            usedSegments = -1;
        }
        cout << usedSegments << '\n';
    }
}