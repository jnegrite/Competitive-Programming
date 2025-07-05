#include <iostream>
#include <vector>
#include <string>
using namespace std;

const long long MOD = 10000000000007LL;

int main() {
    int nCases;
    cin >> nCases;
    for (int tc = 1; tc <= nCases; ++tc) {
        long long ans = 0;
        long long gridSize, minVal, maxVal;
        cin >> gridSize >> minVal >> maxVal;
        long long totalCnt = gridSize * gridSize;

        // get initial product
        long long currProd = 1;
        long long currFactor = totalCnt;
        for (long long i = 0; i < minVal; ++i) {
            currProd *= currFactor;
            currProd %= MOD;
            currFactor -= 1;
        }
        for (long long i = minVal; i <= maxVal; ++i) {
            ans += currProd % MOD;
            ans %= MOD;
            currProd *= currFactor;
            currProd %= MOD;
            currFactor -= 1;
        }
        cout << "Case " << tc << ": " << ans << '\n';
    }
}
