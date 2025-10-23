#include <bits/stdc++.h>

using i64 = long long;

struct BIT {
    int N = 0;
    std::vector<int> t;
    static inline int lowbit(int x) { return x & -x; }
    void init(int n) { N = n; t.assign(N + 1, 0); }
    void add(int i, int v) {
        for (; i <= N; i += lowbit(i)) t[i] += v;
    }
    int sum(int i) const {
        int r = 0;
        for (; i > 0; i -= lowbit(i)) r += t[i];
        return r;
    }
    int range(int l, int r) const { return l > r ? 0 : sum(r) - sum(l - 1); }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // 10^k 预计算：第 D 位 = (x / 10^(D-1)) % 10
    i64 pow10[11]; pow10[0] = 1;
    for (int d = 1; d <= 10; d++) pow10[d] = pow10[d - 1] * 10;

    int T;
    if (!(std::cin >> T)) return 0;
    while (T--) {
        int N, M;
        std::cin >> N >> M;

        // bits[D][P], D=1..10, P=0..9
        std::vector<std::vector<BIT>> bits(11, std::vector<BIT>(10));
        for (int D = 1; D <= 10; D++)
            for (int P = 0; P <= 9; P++)
                bits[D][P].init(N);

        std::vector<i64> a(N + 1);
        for (int i = 1; i <= N; i++) {
            std::cin >> a[i];
            for (int D = 1; D <= 10; D++) {
                int dig = int((a[i] / pow10[D - 1]) % 10);
                bits[D][dig].add(i, +1);
            }
        }

        while (M--) {
            char op; std::cin >> op;
            if (op == 'S') {
                int X; i64 Y; std::cin >> X >> Y;
                if (a[X] != Y) {
                    for (int D = 1; D <= 10; D++) {
                        int od = int((a[X] / pow10[D - 1]) % 10);
                        int nd = int((Y    / pow10[D - 1]) % 10);
                        if (od != nd) {
                            bits[D][od].add(X, -1);
                            bits[D][nd].add(X, +1);
                        }
                    }
                    a[X] = Y;
                }
            } else { // 'Q'
                int L, R, D, P;
                std::cin >> L >> R >> D >> P;  // 一定要把 P 读进来！
                std::cout << bits[D][P].range(L, R) << "\n";
            }
        }
    }
    return 0;
}
