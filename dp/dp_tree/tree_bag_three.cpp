// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=6e4+100;
using namespace std;
int t,n,m,top;
int w[maxn];
int id[maxn];
int a[maxn],f[maxn];
int l[maxn],r[maxn];
int dp[1020][10500];
vector<int >e[maxn];
const int inf= (1<<29);
void dfs(int x){
    l[x]=++top;
    id[top]=x;
    for(auto u:e[x]){
        dfs(u);
    }
    r[x]=top;
    return ;
}
void slove(){
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        cin>>f[i];
        e[f[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    dfs(1);
    for(int i=1;i<=m;i++) dp[n+1][i]=-inf;
    for(int i=n;i>=1;i--){ //枚举结点
        for(int j=0;j<=m;j++){
            dp[i][j]=dp[r[id[i]]+1][j];
            if(j>=w[id[i]]){
                dp[i][j]=max(dp[i][j],dp[i+1][j-w[id[i]]]+a[id[i]]);
            }
        }
    }
    for(int i=0;i<=m;i++){
        cout<<max(dp[1][i],0)<<"\n";
    }
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