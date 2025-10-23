#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;
const int N = 32;                   // 0..15: f(k), 16..31: g(k)

inline int F(int k){ return k; }
inline int G(int k){ return 16 + k; }

ll mod_pow(ll a, long long e){
    ll r = 1 % MOD;
    while(e){
        if(e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

struct Mat{
    ll a[N][N];
    Mat(){ memset(a, 0, sizeof(a)); }
};
Mat operator*(const Mat& A, const Mat& B){
    Mat C;
    for(int i=0;i<N;i++){
        for(int k=0;k<N;k++) if(A.a[i][k]){
            ll aik = A.a[i][k];
            for(int j=0;j<N;j++) if(B.a[k][j]){
                C.a[i][j] = (C.a[i][j] + aik * B.a[k][j]) % MOD;
            }
        }
    }
    return C;
}
Mat mpow(Mat x, long long e){
    Mat r; for(int i=0;i<N;i++) r.a[i][i]=1;
    while(e){
        if(e&1) r = r * x;
        x = x * x;
        e >>= 1;
    }
    return r;
}

// M * vec
array<ll,N> mulMatVec(const Mat& M, const array<ll,N>& v){
    array<ll,N> r{}; r.fill(0);
    for(int i=0;i<N;i++){
        ll s = 0;
        for(int j=0;j<N;j++) if(M.a[i][j]){
            s = (s + M.a[i][j] * v[j]) % MOD;
        }
        r[i] = s;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if(!(cin >> T)) return 0;
    while(T--){
        long long n; int m;
        cin >> n >> m;
        vector<int> D(m);
        for(int i=0;i<m;i++) cin >> D[i];

        // 权重：w = 1 / (5 * m)
        ll inv5 = mod_pow(5, MOD-2);
        ll invM = mod_pow(m, MOD-2);
        ll w = inv5 * invM % MOD;

        // 构造 32×32 正向转移矩阵
        Mat M;
        auto add = [&](int row, int col, ll val){
            M.a[row][col] = (M.a[row][col] + val) % MOD;
        };

        for(int k=0;k<16;k++){
            for(int x : D){
                // f -> f
                add(F((k + x) & 15), F(k), w);
                add(F((k * x) & 15), F(k), w);
                add(F(k ^ x),        F(k), w);
                add(F(k & x),        F(k), w);
                add(F(k | x),        F(k), w);

                // g -> g
                add(G((k + x) & 15), G(k), w);                      // +
                add(G((k * x) & 15), G(k), (w * x) % MOD);          // *  系数 x
                // '&'：题面 0 -> g(n+1,k&x)，与旧状态无关，这里不加
                add(G(k | x),        G(k), w);                      // |
                add(G(k ^ x),        G(k), w);                      // ^

                // f -> g（进位/额外贡献）
                add(G((k + x) & 15), F(k), (w * ((k + x) >> 4)) % MOD); // floor((k+x)/16)
                add(G((k * x) & 15), F(k), (w * ((k * x) >> 4)) % MOD); // floor(kx/16)
            }
        }

        // 初始向量 V1：f(1,x)=1/m，g(1,*)=0
        array<ll,N> V1{}; V1.fill(0);
        for(int x : D){
            V1[F(x)] = (V1[F(x)] + invM) % MOD;
        }

        // 快速幂跳到第 n 层
        array<ll,N> Vn;
        if(n==1){
            Vn = V1;
        }else{
            Mat P = mpow(M, n-1);
            Vn = mulMatVec(P, V1);
        }

        // 答案：sum_k (16*g(n,k) + k*f(n,k))
        ll ans = 0;
        for(int k=0;k<16;k++){
            ans = (ans + 16LL * Vn[G(k)] + 1LL * k * Vn[F(k)]) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
