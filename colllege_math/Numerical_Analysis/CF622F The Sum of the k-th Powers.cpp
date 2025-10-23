#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll mod=1e9+7;
ll n,k,ans;
inline ll norm(ll x) {
    x %= MOD;
    return x < 0 ? x + MOD : x;
}
inline ll mul(ll a, ll b) {
    return (ll)((__int128)a * b % MOD);
}
ll qpow(ll a, ll e) {
    ll r = 1 % MOD;
    a = norm(a);
    while (e) {
        if (e & 1) r = mul(r, a);
        a = mul(a, a);
        e >>= 1;
    }
    return r;
}
    // 首先分析 这个东西的多项式 至多是一个k+1阶的多项式 (这里可以看一下n=0,1,2的封闭公式)
    // 我们想求1-n数字的k次方的和 只要取k个点 求出多项式即可 那么我们需要选取k+2个点
    //这里因为k比较大 并且可以选择连续整数 所以需要使用ok的时间复杂度
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;   
    ll m=k+2;
    if(n<=k){
        for(int i=1;i<=n;i++)
            ans=ans+qpow(i,k);
            ans%=mod;
        cout<<ans;
        return 0;
    }
    vector<ll>x(k+3),y(k+3);
    vector<ll>suf(k+4),pre(k+3);
    vector<ll>fac(k+3),inv(k+3);
    for(int i=1;i<=m;i++){ y[i]=(y[i-1]+qpow(i,k))%mod;}
    fac[1]=1ll;
    for(int i=2;i<=k+2;i++){ fac[i]=mul(fac[i-1],i); }
    inv[m]=qpow(fac[m],mod-2);
    for(int i=m;i>=1;i--) inv[i-1]=mul(inv[i],i);
    pre[0]=suf[k+3]=1ll;
    for(int i=1;i<=m;i++) pre[i]=mul(pre[i-1],norm(norm(n)-i));
    for(int i=m;i>=1;i--) suf[i]=mul(suf[i+1],norm(norm(n)-i));
    for(int i=1;i<=m;i++){
        ll num=mul(pre[i-1],suf[i+1]); // 因为是连续的 直接计算分子
        ll wi=mul(inv[i-1],inv[m-i]); // 计算化简后的分母
        if((m-i)&1) wi=(mod-wi)%mod; // 这里是乘上-1的m-i次方
        ll cnt=mul(y[i],mul(wi,num));
        ans=(ans+cnt)%mod;
    }
    cout<<ans;
    return 0;
}