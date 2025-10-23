// Luogu P1357 花园  C++11
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;

struct Mat {
    int n;
    vector<vector<long long>> a;
    Mat() {}
    Mat(int n_, bool ident=false): n(n_), a(n_, vector<long long>(n_, 0)){
        if(ident) for(int i=0;i<n;i++) a[i][i]=1;
    }
};

Mat mul(const Mat& A, const Mat& B){
    int n = A.n;
    Mat C(n);
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            long long t = A.a[i][k];
            if(!t) continue;
            for(int j=0;j<n;j++){
                C.a[i][j] = (C.a[i][j] + t * B.a[k][j]) % MOD;
            }
        }
    }
    return C;
}

Mat mpow(Mat base, unsigned long long e){
    int n = base.n;
    Mat res(n, true);
    while(e){
        if(e & 1ULL) res = mul(res, base);
        base = mul(base, base);
        e >>= 1ULL;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long n; int m, k;
    if(!(cin >> n >> m >> k)) return 0;

    int S = 1<<m;
    vector<int> id(S, -1), states; states.reserve(S);
    auto ok = [&](int mask)->bool{ return __builtin_popcount(mask) <= k; };

    // 仅保留合法状态（窗口内 1 的个数 ≤ k）
    for(int s=0, cnt=0; s<S; s++){
        if(ok(s)){ id[s]=cnt++; states.push_back(s); }
    }
    int sz = (int)states.size();

    // 构建转移矩阵 T（从窗口 s 滑到下一窗口）
    Mat T(sz);
    for(int u=0; u<sz; u++){
        int s = states[u];
        for(int b=0; b<=1; b++){
            int t = (s >> 1) | (b << (m-1));
            if(ok(t)){
                int v = id[t];
                T.a[u][v] = (T.a[u][v] + 1) % MOD;
            }
        }
    }
    Mat P = mpow(T, n);
    long long ans = 0;
    for(int i=0;i<sz;i++){
        ans += P.a[i][i];
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans % MOD << "\n";
    return 0;
}
