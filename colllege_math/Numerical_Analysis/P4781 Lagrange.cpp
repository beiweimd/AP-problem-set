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
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n,k;
ll ans;
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
void slove(){
    cin>>n>>k;
    vector<ll>x(n),y(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<n;i++){
        ll pre=1;
        for(int j=0;j<n;j++){
            if(j==i) continue;
            pre=pre*(k-x[j]);
            pre%=mod;
        }
        for(int j=0;j<n;j++){
            if(j==i) continue;
            pre=pre*qpow(x[i]-x[j],mod-2)%mod;
            pre%=mod;
        }
        ans=ans+y[i]*pre;
        ans%=mod;
    }
    cout<<(ans+mod)%mod;
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