#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod = 1e9 + 7;
const db pi = acos(-1);
const db eps = 1e-10;
const int maxn = 3e5;
const ll INF = (ll)1e17;
using namespace std;
//本题说的是选择一个点集S，使得剩下未被选择的点 每个点只和一个S有边
int Ncur = 0,N;
vector<vector<int>> G;
// int dp[maxn][2];  //这也是错误的转移
// // 代表满足i及其子树符合约束并且 自己选和不选的最小选择节点
int dp[maxn][3];
// dp0代表选这个点
//dp1不选这个点 并且这个点是和孩子连接的 选了孩子 父亲没选
//dp2 同样不选这个点 而且这个点是和父亲连接的 也就是孩子都没选
//
void dfs(int x ,int fa){
    dp[x][0]=1;//如果选了自己这个点
    int mi=100100;
    for(auto u:G[x]){
        if(u==fa) continue;
        dfs(u,x);
        // dp[x][1]+=min(dp[u][0],dp[u][1]);
        // dp[x][0]+=dp[u][1]; 
        /*
        不能像上边这么搞 一个显然的错误是 如果这个搞得话 那么我们假设x这个点不选 即dp[x][0]
        他会加上所有子树都选 那么就不符合约束 所以转移是错误的
        */
        dp[x][0]+=min(dp[u][2],dp[u][0]); //这个是最直接的 就这个点选的话 那么下面可以不选 也可以选 不选的话 x就是他们的父亲节点 也就是dp2
        mi=min(mi,dp[u][0]-dp[u][1]); 
        dp[x][1]+=dp[u][1]; //这个是这样的逻辑 如果说自己不选 并且孩子中一个选了 那显然剩下的未选的孩子都是孩子
        //来承担连接 所以我们本质是找一个是dp[u][0]剩下的全是dp[u*][1] 我们加上一个dp[u][1] 找到最小的 dp[u][0]-dp[u][1]就好了
        dp[x][2]+=dp[u][1]; //这个也是 就如果父亲选了 那么孩子只能是不选 因为选的话 这个点就被多个点链接了
        //那么父亲x不选 孩子u选不了 那么只能是孩子 的 孩子承担连接
    }
    dp[x][1]+=mi;
    return ;
}
void slove() {
    // TODO: 在这里用全局的 Ncur 和 G 计算本用例的答案并输出
    // 例如：cout << answer << "\n";
    for(int i=1;i<=N;i++) dp[i][0]=dp[i][1]=dp[i][2]=0; // 注意清空
    dfs(1,-1);
    cout << min(dp[1][0],dp[1][1]);
    cout << "\n" ;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        if (!(cin >> N)) {
            return 0; // EOF
        }
        if (N == -1) {
            break; // 所有输入结束
        }
        if (N == 0) {
            continue; // 上个用例的分隔符，直接读下一个
        }

        // 读取本用例的 N-1 条边
        Ncur = N;
        G.assign(Ncur + 1, {});
        for (int i = 0; i < Ncur - 1; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        // 执行本用例
        slove();
        // 注意：按照题意，边后面通常会有一个 0 作分隔，
        // 但我们不额外读它；主循环继续读下一个 token，
        // 若是 0 则在开头被 continue 掉，若是 -1 则结束。
    }
    return (0 - 0);
}
