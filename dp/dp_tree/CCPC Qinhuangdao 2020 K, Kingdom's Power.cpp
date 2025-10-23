// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=1e6+100;
using namespace std;
int t,n;
vector<int >e[maxn];
int f[maxn];
int dis[maxn];// 代表点到根节点的距离
int dp[maxn][3];// 代表点i遍历完所有子树的距离 0 1代表是否回到i  或者理解为穿过？
void init(){
    for(int i=1;i<=n;i++){
        dis[i]=0;
        dp[i][0]=dp[i][1]=0;
        e[i].clear();
    }
}
void dfs(int x,int fa){
    dis[x]=dis[fa]+1;
    dp[x][0]=dis[x],dp[x][1]=dis[x];
    for(auto u:e[x]){
        //if(u==fa) continue;
        dfs(u,x);
        dp[x][0]=min(dp[x][0]+dp[u][0],
        min(dp[x][1]+dp[u][0]-dis[x],
            dp[x][0]+dp[u][1]-dis[x]+1) )
            // 对应三种情况 第三种就是说 直接搞一个新的棋子 去搜v的子树
            // 第一种就是前面已经回来了 然后我们这个子树就可以不回来
            // 第二种情况就是前面都没有回来 然后这个先是遍历完v 然后回来 那个这个东西他是 f[v][1]-dis[u] 这里加1代表回来
        ;
        dp[x][1]+=dp[u][1]-dis[x]+1; // 这个应该是好理解的 对吧 就是直接从根派下来一个点 然后每个叶子节点直接走完
    }
}
void slove(){
    init();
    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>f[i];
        e[f[i]].push_back(i);
        //e[i].push_back(f[i]);
    }
    dis[0]=-1;
    dfs(1,0);
    cout<<dp[1][0]<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        slove();
    }
    return 0;
}