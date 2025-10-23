// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=100;
const ll INF=1e17;
using namespace std;
int n;
ll n1,mod;
struct  mat{
    ll a[maxn][maxn]; 
};
mat operator*(const mat&A,const mat&B){
    mat z={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                z.a[i][j]+=A.a[i][k]*B.a[k][j];
                z.a[i][j]%=mod;
            }
        }
    }
    return z;
}
mat quickmod(mat x,ll y){
    mat s={};
    for(int i=1;i<=n;i++) s.a[i][i]=1;
    while(y){
        if(y&1) s=s*x;
        x=x*x;
        y>>=1;
    }
    return s;
}
void slove(){
    cin>>n1>>mod;
    n = 3;

    // 转移矩阵 m 的固定部分
    mat m = {};
    m.a[1][2] = m.a[2][2] = m.a[2][3] = m.a[3][3] = 1;
    // 状态向量 vec（用 3x3 存，只用到第1列）：初始与“正确代码”一致
    mat vec = {};
    vec.a[2][1] = vec.a[3][1] = 1;
    // 这里的vec其实就是分段开始乘的时候的初始值 
    // 最初的时候是{dp[0],1,1}
    // 分段： [1..9], [10..99], [100..999], ...
    // b(1,1) = 10^d (mod mod)。用 ten 维护，不用担心 i 溢出。
    ll cur = 1;
    ll ten = 10 % mod;
    while (true){
        // 本段的 b(1,1)
        m.a[1][1] = ten;
        // 计算本段的右端点 next = min(cur*10, n1+1)
        ll next = (cur > n1/10 ? n1 + 1 : cur * 10);
        ll len  = (std::min(n1, next - 1) - cur + 1);
        if (len > 0){
            mat ans = quickmod(m, len);   // b^len
            vec = ans * vec;              // 左乘状态列向量
        }
        if (next == n1 + 1) break;        // 已覆盖到 n1
        cur = next;
        ten = (ten * 10) % mod;           // 进入下一段：b(1,1) *= 10
    }

    cout << (vec.a[1][1] % mod) << '\n';
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