// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod= 998244353;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
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
void slove(){
    int n;cin>>n;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    ll ans=((a[1]*qpow(2,n-1))%mod);
    for(int i=2;i<=n;i++){
        ans=ans+((a[i]*qpow(2,n-i))%mod);
        ans%=mod;
        ans=ans+((a[i]*qpow(2,n-i)%mod)*((qpow(3,i-1)-1+mod)%mod)%mod*qpow(2,mod-2)%mod);
        ans%=mod;
    }
    ans+=mod;
    cout<<ans%mod<<"\n";
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
/*
    sort(a.begin()+1,a.end());
    ll ans=((a[1]*qpow(2,n-1))%mod);
    for(int i=2;i<=n;i++){
        ans=ans+((a[i]*qpow(2,n-i))%mod);
        ll pre=1ll;
        for(int k=1;k<=i-1;k++){
            pre*=(i-k);
            pre%=mod;
            pre=pre*qpow(k,mod-2);
            pre%=mod;
            ans=ans+(((a[i]*qpow(2,k-1)%mod)*pre)%mod)*qpow(2,n-i)%mod;       
        }
    }
    cout<<ans%mod<<"\n";
*/