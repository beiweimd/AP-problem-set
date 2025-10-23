// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const int maxn=6e5;
const db pi=acos(-1);
const db eps=1e-10;
using namespace std;
int t,n,m,tot;
ll ans;
vector<int >e[maxn];
int p[maxn*2],deep[maxn*2];
pair<int,int> f[20][maxn*2];
unsigned int A, B, C;
inline unsigned int rng61() {
    A ^= A << 16;
    A ^= A >> 5;
    A ^= A << 1;
    unsigned int t = A;
    A = B;
    B = C;
    C ^= t ^ A;
    return C;
}
void dfs(int u,int fa ){
    p[u]=++tot;
    deep[u]=deep[fa]+1;
    f[0][tot]={deep[u],u};
    for(auto x:e[u]){
        if(x==fa) continue;
        dfs(x,u);
        f[0][++tot]={deep[u],u};
    }
    return ;
}
void slove(){
    cin>>n>>m>>A>>B>>C;
    //输入树边
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
      }
      dfs(1,0);// 先找出欧拉序
      for(int j=1;j<=20;j++){
        for(int i=1;i+(1<<j)-1<=tot;i++){
            f[j][i]=min(f[j-1][i],f[j-1][i+(1<<(j-1))]);
        }
      }
      
    for (int i = 1; i <= m; i++) {
         int u = p[rng61() % n + 1], v =p[ rng61() % n + 1];
        if(u>v) swap(u,v);
        int len=31-__builtin_clz(v-u+1);
        int d=min(f[len][u],f[len][v-(1<<len)+1] ).second;
        ans^=1ll*i*d;
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