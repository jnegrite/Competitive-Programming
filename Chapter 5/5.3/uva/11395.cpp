#include <cstdio>
#include <cmath>

using namespace std;

long long countOdd(long long value) {
    long long sq = 1;
    long long ans = 0;

    while (sq * sq <= value) {
        ans += (1 + static_cast<long long>(log2(value / (sq * sq))));
        sq += 2;
    }
    return ans;
}

int main() {
    long long value;
    while (true) {
        scanf("%lld\n",&value);
        if (value == 0) {
            break;
        }
        printf("%lld\n",value - countOdd(value));
    }

    return 0;
}
