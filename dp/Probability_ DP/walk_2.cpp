// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int t,n,m,u,v;
ll dp[maxn];
ll quick_mod(ll a,ll b){
    ll s=1;
    while(b){
        if(b&1) {
            s=(s*a)%mod;
        }
        b=(b>>1);
        a*=a;
        a%=mod;
    }
    return s;
}
vector<int >e[maxn];
void slove(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        e[u].push_back(v);
    }
    dp[1]=1;
    for(int i=1;i<n;i++){
        for(auto u:e[i]){
            dp[u]+= dp[i]*quick_mod(e[i].size(),mod-2);
            dp[u]%=mod;
        }
    }
    cout<<dp[n];
    //cout<<fixed<<setprecision(10)<<dp[n];
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