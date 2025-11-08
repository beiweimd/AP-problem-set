#include <bits/stdc++.h>

using i64 = long long;

static const i64 INF = (i64)4e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    while (std::cin >> n) {
        std::vector<i64> a(2 * n + 1), pre(2 * n + 1, 0);
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            a[i + n] = a[i];
        }
        for (int i = 1; i <= 2 * n; i++) {
            pre[i] = pre[i - 1] + a[i];
        }
        auto sum = [&](int l, int r) -> i64 {
            return pre[r] - pre[l - 1];
        };

        // dp与opt都开到2n
        std::vector<std::vector<i64>> dp(2 * n + 1, std::vector<i64>(2 * n + 1, 0));
        std::vector<std::vector<int>> opt(2 * n + 1, std::vector<int>(2 * n + 1, 0));
        for (int i = 1; i <= 2 * n; i++) {
            dp[i][i] = 0;
            opt[i][i] = i;
        }

        // Knuth优化：opt[i][j-1] <= opt[i][j] <= opt[i+1][j]
        for (int len = 1; len <= n - 1; len++) {
            for (int i = 1; i + len <= 2 * n; i++) {
                int j = i + len;
                dp[i][j] = INF;
                int L = opt[i][j - 1];
                int R = opt[i + 1][j];
                if (L < i) { L = i; }
                if (R > j - 1) { R = j - 1; }
                for (int k = L; k <= R; k++) {
                    i64 cand = dp[i][k] + dp[k + 1][j] + sum(i, j);
                    if (cand < dp[i][j]) {
                        dp[i][j] = cand;
                        opt[i][j] = k;
                    }
                }
            }
        }
        i64 ans = INF;
        for (int i = 1; i <= n; i++) {
            ans = std::min(ans, dp[i][i + n - 1]);
        }
        std::cout << ans << "\n";
    }

    return 0;
}
