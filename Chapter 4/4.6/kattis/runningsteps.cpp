#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<int,long long> vals {};

void initVals(){
    vals.clear();
    vals[2] = 0;
    vals[4] = 1;
    vals[6] = 4;
    vals[8] = 1;
    vals[10] = 9;
    vals[12] = 37;
    vals[14] = 16;
    vals[16] = 101;
    vals[18] = 425;
    vals[20] = 226;
    vals[22] = 1261;
    vals[24] = 5342;
    vals[26] = 3185;
    vals[28] = 16661;
    vals[30] = 70624;
    vals[32] = 45397;
    vals[34] = 227925;
    vals[36] = 964702;
    vals[38] = 654589;
    vals[40] = 3192707;
    vals[42] = 13483514;
    vals[44] = 9533591;
    vals[46] = 45499169;
    vals[48] = 191695011;
    vals[50] = 140024274;
    vals[52] = 656975671;
    vals[54] = 2761415749;
    vals[56] = 2071251366;
    vals[58] = 9585067029;
    vals[60] = 40197719157;
    vals[62] = 30823385424;
    vals[64] = 141022545077;
    vals[66] = 590174378453;
    vals[68] = 461076613802;
    vals[70] = 2089303926185;
    vals[72] = 8726567622555;
    vals[74] = 6928035002534;
    vals[76] = 31135655962227;
    vals[78] = 129811259033521;
    vals[80] = 104507122669576;
    vals[82] = 466323616692283;
    vals[84] = 1940942711798053;
    vals[86] = 1581897746416066;
    vals[88] = 7014487515180361;
    vals[90] = 29150498233064655;
    vals[92] = 24018140388709152;
    vals[94] = 105912301155194501;
    vals[96] = 439511434241632076;
    vals[98] = 365668377576409175;
    vals[100] = 1604517292705494701;
}

int main(){
    int nCases;
    cin >> nCases;
    int tc, p;
    initVals();
    while(nCases--){
        cin >> tc >> p;
        cout << tc << ' ' << vals[p] << '\n';
    }
}