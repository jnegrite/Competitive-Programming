#include<cstdio>
#include<set>

using namespace std;

struct Segment {
    double timeFrom{};
    double timeTo{};
    int elevationFrom {};
    double changeRate {};

    Segment(int _timeFrom, int _timeTo, int _elevationFrom, int _change){
        timeFrom = _timeFrom;
        timeTo = _timeTo;
        elevationFrom = _elevationFrom;
        changeRate = static_cast<double>(_change)/(timeTo-timeFrom);
    }

    Segment(){};

    double getHeight(double time){
        return elevationFrom + changeRate * (time - timeFrom);
    }

    bool operator<(const Segment &o) const {
        return timeTo < o.timeTo;
    }
};

set<Segment> ascend {};
set<Segment> descend {};
Segment dummy {};

double computeHeight(set<Segment> &st){
    Segment s {*st.lower_bound(dummy)};
    return s.getHeight(dummy.timeTo); 
}

int main(){
    int hFrom {};
    int hTo {};
    int tFrom {};
    int tTo{};

    int tAscend{};
    int tDescend{};

    int nAscend {};
    int nDescend {};
    scanf("%d %d\n",&nAscend,&nDescend);
    
    int dH;
    int dT;

    //ascend part
    for(int i=0;i<nAscend;i++){
        scanf("%d %d", &dH, &dT);
        tTo = tFrom + dT;
        ascend.emplace(Segment{tFrom, tTo, hFrom, dH});
        hFrom += dH;
        tFrom = tTo;
    }
    tAscend = tTo;

    //descend part
    tFrom=0;
    for(int i=0;i<nDescend;i++){
        scanf("%d %d", &dH, &dT);
        dH *= -1;
        tTo = tFrom + dT;
        descend.emplace(Segment{tFrom, tTo, hFrom, dH});
        hFrom += dH;
        tFrom = tTo;
    }
    tDescend = tTo;

    double low = 0.0;
    double high = min(tAscend,tDescend);

    double mid;

    while(high-low > 1e-6){
        mid = (low+high)/2.0;
        dummy.timeTo = mid;
        double h1 {computeHeight(ascend)};
        double h2 {computeHeight(descend)};
        if(h1 < h2){
            low = mid;
        } else {
            high = mid;
        }
    }
    printf("%.7lf\n",mid);
}