// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=1e7+10;
const ll INF=1e17;
using namespace std;
const ll p=998244353; // mod搞成常量跑的更快
ll ans,n,inv[maxn],lc=1;
ll quickmod(ll a,ll b,ll mod){
    ll s=1;
    while(b){
        if(b&1) s=s*a;
        a=a*a;a%=mod;
        b>>=1;
        s%=mod;
    }
    return s%mod;
}
void slove(){
    cin>>n; inv[1]=1ll;
    vector<int >prime;
    vector<bool>is(n+100,true);
    for(int i=2;i<=n;i++){
        if(is[i]) prime.push_back(i);
        for(auto u:prime){
            if((ll)u*i>n) break;
            is[u*i]=0;
            if(i%u==0) break;
        }
    }
    for(auto u:prime){
        //cout<<u<<floor(log2(n)/log2(u))<<endl;
        lc*=(quickmod( 1ll*u,1ll*floor(log2(n)/log2(u)) ,p )%p);
        lc%=p;
    }
    //cout<<lc<<endl;
    for(int i=2;i<=n;i++){
        inv[i]=(p-p/i)*inv[p%i]%p;
    }
    for(int i=1;i<=n;i++){
        ans=ans+((lc*inv[i])%p*(n-2*i+1)%p); // 这里注意是跑的圈数/自己的i 就说明自己跑了多少圈 那么显然是要乘上逆元的
        // 任意两个人之间打招呼的次数 是两人跑圈之差 然后算一下贡献就可以了。 
        ans%=p;
    }
    cout<<(ans+p)%p;
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