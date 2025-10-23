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
const int maxn=2e5+100;
const ll INF=1e17;
using namespace std;
int n;
int k;
int val[maxn];
int dp[maxn][20];
void init(){
    for(int j=1;j<=18;j++){
        for(int i=1;i+(1<<j)<=n+1;i++){
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
    return ;
} 
int query(int  l , int r){
    if(l==r) return dp[l][0];
    int k=log2(r-l+1);
    return max( dp[l][k], dp[r-(1<<k)+1][k]);
}
void slove(){
	int sum=0ll,mx=0ll;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        sum+=val[i];
        dp[i][0]=val[i];
        mx=max(mx,val[i]);
    }
    if(sum<=k) {return (void)(cout<<-1<<"\n");}
    init();
    int r=n,l=k/mx+(k%mx==0?0:1); // 这里的l r指的是我们分了多少个组
    //cout<<l<<" "<<r<<endl; 好像没什么优化的必要
    for(int i=l;i<=n;i++){
        int cnt=0;
        int pos=1;
        int len=n/i; // 每一块的长度
        for(int j=1;j<=i;j++){
            cnt+=query(pos,pos+len-1);
            pos+=len;
        }
        if(cnt>k) {
            cout<<i<<"\n";return ;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        cin>>n>>k;
        if(n<0 && k<0) break;
		slove();
    }
    return (0-0);
}