// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e5+100;
const ll INF=1e17;
using namespace std;
int n,m,q,ans;
vector<pair<int,ll> >e[maxn];
ll dp[maxn][40]; // 从i这个点出发经过j条边的乘积最大值
void slove(){
	cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        dp[i][0]=1ll;
    }
    for(int i=1;i<=m;i++){
        int u,v;ll d;
        cin>>u>>v>>d;
        e[u].push_back({v,d});
        dp[u][1]=max(dp[u][1],d);
    }
    for(int i=2;i<=32;i++){
        for(int x=1;x<=n;x++){
            for(auto [u,w]:e[x]){
                dp[x][i]=max(dp[x][i],dp[u][i-1]*w);
            }
        }
    }
    while(q--){
        int p,x;cin>>p>>x;
        for(int i=1;i<=32;i++){
            if(dp[p][i]>x) {
                cout<<i<<"\n";
                break;
            }
        }
    }
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