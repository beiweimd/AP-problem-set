// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=1<<20;
const ll INF=1e17;
using namespace std;
// f[i][j] 代表路径为i中最后一次是以j的方案数
int n,m,u,v;
ll f[maxn][30];
int g[30][30];
ll ans;
void slove(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        u--;v--;
        g[u][v]=g[v][u]=1;
    }
    for(int i=0;i<n;i++){
        f[1<<i][i]=1;
    }
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++){// 这里是枚举所有的f ij
            if(f[i][j]==0) continue;
            for(int k=0;k<n;k++){
                if(g[j][k]==0) continue;
                if((i&-i)>1<<k ) continue; // 这里是为了保证最小的点是i
                if((1<<k)&(i)){ // 说明前面的路径中有了k
                    if(1<<k==(i&-i)) ans+=f[i][j];
                }
                else f[i|1<<k][k]+=f[i][j];
            }
        }
    }
    cout<<(ans-m)/2;
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