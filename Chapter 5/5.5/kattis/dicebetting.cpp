#include <cstdio>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<long long, double> memo;

int n, s, k;

long long makeKey(int dice_left, int distinct_numbers_so_far) {
    return ((long long)dice_left << 32) | distinct_numbers_so_far;
}

double dp(int dice_left, int distinct_numbers_so_far) {
    if (dice_left == 0) {
        if (distinct_numbers_so_far >= k) {
            return 1.0;
        } else {
            return 0.0;
        }
    }
    
    if (distinct_numbers_so_far >= k) {
        return 1.0;
    }
    
    long long ky = makeKey(dice_left, distinct_numbers_so_far);
    if (memo.find(ky) != memo.end()) {
        return memo[ky];
    }
    
    if (dice_left > 500) {
        dp(dice_left - 501, distinct_numbers_so_far);
        dp(dice_left - 501, distinct_numbers_so_far + 1);
    }
    
    double ans = 0.0;
    if (distinct_numbers_so_far > 0) {
        ans += (distinct_numbers_so_far / (double)s) * dp(dice_left - 1, distinct_numbers_so_far);
    }
    if (distinct_numbers_so_far < s) {
        ans += ((s - distinct_numbers_so_far) / (double)s) * dp(dice_left - 1, distinct_numbers_so_far + 1);
    }
    
    memo[ky] = ans;
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &s, &k);
    printf("%.7f\n", dp(n, 0));
    return 0;
}
