// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
//v.insert(v.begin() + pos, x);
//插入x到当做pos下标
//*(pos--) 错误写法 是先引用在减
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int N;
// 邻接表：G[u] = { (v, w), ... }
vector<pair<int, int> > G[maxn];
int dp[maxn][2]; //代表i的子树中最长的distance 和 次长的 distance refer to edge
int f[maxn]; //refer to the point i move up to the parent node largest distance
int point[maxn][2]; //refer the largest and second largest distance of node 
void dfs(int x,int fa){
    for(auto [u,w]:G[x]){
        if(u==fa ) continue;
        dfs(u,x);
        int temp=dp[u][0]+w; // 0 refer to largest 
        if(temp>=dp[x][0]){
            point[x][1]=point[x][0];
            point[x][0]=u;
            dp[x][1]=dp[x][0]; // 1 refer to the second largest
            dp[x][0]=temp;
        }
        else{
            if(temp>dp[x][1]){
                point[x][1]=u;
                dp[x][1]=temp;
            }
        }
    }
    return ;
}
void dfs2(int x,int fa){
    //cout<<x<<" "<<fa<<endl;
    for(auto [u,w]:G[x]){
        if(u==fa ) continue;
        if(u==point[x][0]){
            f[u]=max(f[x],dp[x][1])+w; //f 代表往上走 那么每个节点 肯定是选择先走w到父亲 然后选择父亲
            //中最大的那个子树或者是沿着父亲接着往上走 后者就是f[x]
        }
        else f[u]=max(f[x],dp[x][0])+w;
        dfs2(u,x);
    }
    return ;
}
void slove(){
    // 多测直到 EOF
    while (cin >> N){
        // 第 i 行：第 i 台电脑连接的电脑编号 和 电缆长度
        // 通常是 i = 2..N，但题面说有 N-1 行，按行读更稳
        for(int i = 1; i <= N - 1; i++){
            int v, w;
            cin >> v >> w;
            int u = i + 1; // 第 i 行描述的是电脑 (i+1)
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        dfs(1,-1);
        dfs2(1,-1);
        for(int i=1;i<=N;i++) {
            //cout<<dp[i][1]<<"\n";
            //cout<< f[i] <<endl;
            cout<<max(dp[i][0],f[i])<<"\n";
        }
        for(int i = 1; i <= N; i++){
            G[i].clear();
            dp[i][0]=dp[i][1]=0;
            point[i][0]=point[i][1]=0;
            f[i]=0;
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
