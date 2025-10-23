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
const int maxn=6e5;
const ll INF=1e17;
using namespace std;
int n;
ll d,k,sum;
ll x[maxn],s[maxn];
ll dp[maxn];
bool check(ll o){
    ll rig=o+d;
    ll lef=max(1ll,d-o);
    ll ans=-INF;
    for(int i=1;i<=n;i++){
        dp[i]=-INF;
    }
    deque<int >q;
    int pos=0;
    for(int i=1;i<=n;i++){
        // for(int j=0;j<i;j++){
        //     // 应该维护一个范围在 [x[i]-rig,x[i]-lef] 里的最值
        //     if(x[i]-x[j]<=rig && x[i]-x[j]>=lef){
        //         dp[i]=max(dp[i],s[i]+dp[j]);
        //     }
        // }
        // 简易分析一下 [A,B] 假设A B都在范围内，那如果说A<B A肯定就没用了 所以我们维护的是一个递减的一个序列
        //这里是先加入在右边界合法的
        while (pos<i && x[pos] <= x[i] -  lef){
            if(dp[pos]!=INF){
                while(!q.empty() && dp[pos]>=dp[q.back()]) q.pop_back();
                q.push_back(pos);
            }
            pos++;
        }
        // 在删除掉左边界不合理的
        while(!q.empty() && x[q.front()]<x[i]-rig) q.pop_front();
        if (!q.empty() ) dp[i] = dp[q.front()] + s[i];
    }  
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    if(ans>=k) return false;
    return true;
}
void slove(){
    cin>>n>>d>>k;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>s[i];
        if(s[i]>0) sum+=s[i];
    }
    if(sum<k) {cout<<-1;return;}
    int l=1,r=1e9;
    while(l<=r){
        int mid=(l+r+1)/2;
        if(check(mid) ) l=mid+1;
        else r=mid-1;
    }
    cout<<l;
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