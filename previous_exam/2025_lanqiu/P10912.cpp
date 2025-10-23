#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=2e5;
using namespace std;
int du[maxn];
ll f[maxn];
ll inv[maxn];
int t,n,m,l,r,u,v;
ll ans;
ll qpow(ll a, ll b ){
	ll s=1;
	while(b){
		if(b&1) s=s*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return s;
}
void slove(){
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        du[u]++;
        du[v]++;
    }
    f[0]=1ll;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]*i;
        f[i]%=mod;
        inv[i] = qpow(f[i], mod - 2);
        inv[i]%=mod;
    }
    cin>>l>>r;
    for(int i=1;i<=n;i++){
        int num=du[i];
        for(int j=l-1;j<=min(num,r-1);j++){
            if(j==num or j==0) ans++;
            else ans=ans+f[num]*inv[j]%mod*inv[num-j]%mod;
            ans%=mod;
        }
    }
    cout<<ans;
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    t=1;
    while(t--){
		slove();
    }
    return 0;
}