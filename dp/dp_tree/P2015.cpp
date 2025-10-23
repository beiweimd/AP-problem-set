// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e3+100;
using namespace std;
int t,n,m;
int siz[maxn];
int dp[maxn][maxn];
vector<pair<int,int > >e[maxn];
void dfs(int x,int fa){
    siz[x]=1;
    for(auto u:e[x]){
        if(u.first==fa) continue;
        dfs(u.first,x);
        for(int i=siz[x]-1;i>=0;i--){ // 枚举当前这个点选择了多少边
            for(int j=0;j<=siz[u.first]-1;j++){
                dp[x][i+j+1]=max(dp[x][i+j+1],u.second+dp[x][i]+dp[u.first][j]);
            }
        }
        siz[x]+=siz[u.first];
    }
    return ;
}
void slove(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        swap(u,v);
        e[u].push_back({v,w});
    }
    dfs(1,-1);
    cout<<dp[1][m];
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