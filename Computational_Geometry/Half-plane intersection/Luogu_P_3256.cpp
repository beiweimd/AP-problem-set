// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-18;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n;
int d[maxn];
int v[maxn];
void slove(){
    db c = 1.0;
    cin >> n;
    vector<int> ans;
    for(int i=1;i<=n;i++) cin >> d[i];
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        db r = 0, l = 1e18;
        int flag = 1;
        for(int j=1;j<=n;j++){
            if(j==i) continue;

            // 关键补丁：同起点的处理要优先
            if(d[j]==d[i]){
                if(v[j]>v[i]) l = min(l, (db)0.0); // 只能在 t=0 不落后于 j
                // if (v[j]<v[i]) r = max(r, (db)0.0); // 原本就是 0，不影响
                continue;
            }

            if(d[j]<=d[i] && v[j]<=v[i]) continue;
            if(d[j]>d[i] && v[j]>=v[i]) { flag = 0; break; } // 有辆车一直在你前面

            if(v[j]>v[i] && d[j]<d[i]){
                l = min(l, (d[i]-d[j])*c/(v[j]-v[i]));
            }
            if(v[j]<v[i] && d[i]<d[j]){
                r = max(r, (d[j]-d[i])*c/(v[i]-v[j]));
            }
        }
        // 允许 t=0：区间 [r, l] 只要非空即可
        if(l + eps >= r && flag) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(int i=0;i<(int)ans.size();i++){
        if(i) cout << ' ';
        cout << ans[i];
    }
    cout << "\n";
    return ;
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