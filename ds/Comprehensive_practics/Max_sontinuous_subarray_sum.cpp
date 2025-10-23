// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int t,n;
ll a[maxn],ans;
ll c[maxn];
ll dp[maxn];// 权值dp 代表的是以i结尾的 最大的 数值
//我们使用树状数组 因为每次更新的数值肯定是只增不减的 所以可以这么搞
int lowbit(int x){return x&(-x);}
ll query(int x){
    ll s=0;
    for(;x>0;x-=lowbit(x)){
        s=max(s,dp[x]);
    }
    return s;
}
void modify(int x,ll val){
    for(;x<=2e5;x+=lowbit(x)){
        dp[x]=max(dp[x],val);
    }
    return ;
}
void slove(){
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<a[i];j++){
    //         dp[a[i]]=max(dp[a[i]],dp[j]+a[i]);
    //     }
    //     ans=max(dp[a[i]],ans);
    // } // 这里一个n^2的一个dp 我们每次需要找比a[i]小的 中的dp最大数值 并更新dp[i]
    // // 其实就是一个单点修改 前缀区间查询最大值
    for(int i=1;i<=n;i++){
        int val=query(a[i]-1);
        modify(a[i],a[i]+val );
        ans=max(ans,dp[a[i]]);
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