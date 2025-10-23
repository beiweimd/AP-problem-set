// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
ll a,b;
ll f[1100][1100];
ll qpow(ll a,ll b ){
    ll s=1ll;
    while(b){
        if(b&1){
            s=s*a;
            s%=mod;
        }
        a=a*a;a%=mod;
        b>>=1;
    }
    return s;
}
long long pow_mod(long long a, long long b, long long p) {
    long long result = 1;
    a %= p;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % p;
        }
        a = (a * a) % p;
        b /= 2;
    }
    return result;
}

// 计算组合数 C(n, k) mod p，要求 n < p 且 k <= n
long long comb(long long n, long long k, long long p) {
    if (k > n) return 0;
    // 为了减小计算量，取k和n-k中的较小值
    if (k > n - k) k = n - k;
    
    long long numerator = 1;   // 分子：n*(n-1)*...*(n-k+1)
    long long denominator = 1; // 分母：k!
    
    for (int i = 0; i < k; i++) {
        numerator = (numerator * (n - i)) % p;
        denominator = (denominator * (i + 1)) % p;
    }
    
    // C(n,k) = 分子 * 分母^(p-2) mod p（费马小定理）
    return (numerator * pow_mod(denominator, p - 2, p)) % p;
}

// 卢卡斯算法计算 C(n, k) mod p，p是质数
long long lucas(long long n, long long k, long long p) {
    if (k == 0) return 1;
    // 递归分解：C(n,k) ≡ C(n%p, k%p) * C(n/p, k/p) mod p
    return (comb(n % p, k % p, p) * lucas(n / p, k / p, p)) % p;
}
void slove(){
	cin>>a>>b;
    if(b>a) {cout<<0;return ;}
    // f[0][0]=1;
    // f[1][0]=2;f[1][1]=1;
    // for(int i=2;i<=a;i++){
    //     f[i][0]=(f[i-1][0]*2)%mod;
    //     for(int j=1;j<=i;j++){
    //         f[i][j]=f[i-1][j]*2+f[i-1][j-1];
    //         f[i][j]%=mod;
    //     }
    // }
    // cout<<f[a][b];
    cout<<qpow(2,a-b)*lucas(a,b,mod)%mod;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
		slove();
    }
    return (0-0);
}