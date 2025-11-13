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
const ll mod = 1e9 + 7;
const db pi = acos(-1);
const db eps = 1e-10;
const int maxn = 3e2;
const ll INF = (ll)1e17;
using namespace std;

// ------- 供 slove() 使用的全局：当前用例的 N、M、价值、树（以 0 为虚根） -------
int Ncur = 0, Mcur = 0;
vector<int> val;                 // val[0] = 0
vector<vector<int>> G;           // 有向：父 -> 子（0 为虚根）
vector<int> parent_;             // 原始父亲，a=0 的并到 0
int siz[maxn]; //代表每个点子树大小
int dp[maxn][maxn];//代表i这课子树选了j门课程(一定包括自己)的最大score
void dfs(int x, int fa){
    siz[x]=1;
    for(auto u:G[x]){
        if(u==fa) continue;
        dfs(u,x);
        //我们需要分别的去枚举 状态已经是多少个 和子树选多少个
        for(int i=siz[x]-1;i>=0;i--){
            for(int j=0;j<=siz[u];j++){
                dp[x][i+j]=max(dp[x][i+j],dp[x][i]+dp[u][j]);
            }
        }
        siz[x]+=siz[u];
    }
    for(int i=siz[x];i>=1;i--){
        dp[x][i]=dp[x][i-1]+val[x];
    }
}
void slove() {
    // TODO: 在这里使用 Ncur, Mcur, val, G 计算并输出答案
    // 例如：cout << answer << "\n";
    dfs(0,-1);
    cout<<dp[0][Mcur+1]<<"\n"; 
    //这里一定是M+1 因为我们要把虚点这个点也算上去
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        int N, M;
        if (!(cin >> N >> M)) {
            return 0;               // EOF
        }
        if (N == 0 && M == 0) {
            break;                  // 结束
        }

        // 读 N 行 (a, b)
        vector<pair<int,int>> raw(N + 1);
        for (int i = 1; i <= N; i++) {
            int a, b;
            cin >> a >> b;
            raw[i] = {a, b};
        }
        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++) dp[i][j]=0;
        }
        // 构建当前用例
        Ncur = N;
        Mcur = M;
        val.assign(Ncur + 1, 0);
        parent_.assign(Ncur + 1, 0);
        G.assign(Ncur + 1, {});

        for (int i = 1; i <= Ncur; i++) {
            parent_[i] = raw[i].first;
            val[i] = raw[i].second;
        }
        // 建树（有向：父 -> 子），a=0 的挂到 0
        for (int i = 1; i <= Ncur; i++) {
            int a = parent_[i];
            if (a == 0) {
                G[0].push_back(i);
            } else {
                G[a].push_back(i);
            }
        }

        // 交给 slove 处理并输出本用例答案
        slove();
    }
    return (0 - 0);
}
