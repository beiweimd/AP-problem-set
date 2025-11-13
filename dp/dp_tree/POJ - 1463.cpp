// 本题本质上是求最小点覆盖数  选最少的点覆盖所有边
// 最小点覆盖数+最大独立集=总顶点数 选最多的点使得任意两点不相邻 因此可以转化为上司的舞会问题
// 这是一个对偶问题 在任意二分图都满足这个性质 PS：树是一种特殊的二分图
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1505;
int f[MAXN][2],n;
// 0 代表选自己
vector<int> adj[MAXN];  // 邻接表存无向树
// 多组数据复用：清空邻接表
int g[MAXN][2]; //代表选不选自己能覆盖自己及子树的最小选择数量
void clearAdj(int n) {
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        f[i][0]=f[i][1]=0;
        g[i][0]=g[i][1]=0;
    }
}
void dfs(int x ,int fa){
    g[x][1]=1;//先把自己给选上
    for(auto u:adj[x]){
        if(u==fa ) continue;
        dfs(u,x);
        g[x][1]+=min(g[u][0],g[u][1]);
        g[x][0]+=g[u][1]; //因为u-x这条边至少要有一个点被选
    }
}
void slove(){
    dfs(0,-1);
    int ans=min(g[0][0],g[0][1]);
    cout<<ans<<"\n";
}
// void dfs(int x, int fa){
//     f[x][0]=1;
//     for(auto u:adj[x]){
//         if(u==fa) continue;
//         dfs(u,x);
//         f[x][1]+=max(f[u][1],f[u][0]);
//         f[x][0]+=f[u][1];
//     }
//     return ;
// }
//void slove1(){
    //int ans=0;
    //dfs(0,-1);
    //for(int i=0;i<n;i++) ans=max(ans,max(f[i][0],f[i][1] ) );
    //cout<<n-ans;
    //cout<<"\n";
    //return ;
//}
int main() {
    // 处理多组输入，直到读不到节点数为止
    while (scanf("%d", &n) != EOF) {
        clearAdj(n);
        // 读入n个节点的边信息
        for (int i = 0; i < n; i++) {
            int u, k;
            // 精准匹配 "节点:(边数)" 格式（如 0:(1)、3:(3)）
            scanf("%d:(%d)", &u, &k);
            // 读入k个相邻节点，构建无向边
            for (int j = 0; j < k; j++) {
                int v;
                scanf("%d", &v);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        slove();
    }
    return 0;
}