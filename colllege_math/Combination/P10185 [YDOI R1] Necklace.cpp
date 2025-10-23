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
int n;
ll sum,a[maxn],val[maxn],ans;
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
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int j=1;j<=n;j++){
        cin>>val[j];
    }
    for(int i=1;i<=n;i++){
        ans=ans+(qpow(2,sum-a[i])%mod*(qpow(val[i]+1,a[i])-1)%mod)%mod;
        ans%=mod;
    }
    cout<<ans%mod;
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