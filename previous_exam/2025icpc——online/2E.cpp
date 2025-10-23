// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=998244353;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=10;
const ll INF=1e17;
using namespace std;
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
struct  mat{
    ll a[maxn][maxn]; 
};
mat operator*(const mat&A,const mat&B){
    mat z={};
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            for(int k=1;k<=2;k++){
                z.a[i][j]+=A.a[i][k]*B.a[k][j];
                z.a[i][j]%=mod;
            }
        }
    }
    return z;
}
mat quickmod(mat x,ll y){
    mat s={};
    for(int i=1;i<=2;i++) s.a[i][i]=1;
    while(y){
        if(y&1) s=s*x;
        x=x*x;
        y>>=1;
    }
    return s;
}
ll n,m;
void slove(){
	cin>>n>>m;
    if(n<=2){cout<<n%2<<"\n";return ;}
    if(m==0){cout<<0<<"\n";return ;}
    if(n%2==1){
        cout<<qpow((qpow(2,m)-1)%mod,n-1)%mod<<"\n";
    }
    else{
        ll ans=qpow(2,m)%mod;
        ans=ans*qpow(((qpow(2,m)-1)%mod),(n-2)/2);
        ans%=mod;
        ll qv = qpow(2, m) % mod;
        ll r  = (qv - 1 + mod) % mod;
        mat T = {};
        T.a[1][2] = 1;
        T.a[2][1] = r;
        T.a[2][2] = (r - 1 + mod) % mod;
        mat P = quickmod(T, n/2);
        ll Zt = P.a[1][1] % mod;
        ans = ans * Zt % mod;
        cout << ans % mod << "\n";
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
		slove();
    }
    return (0-0);
}