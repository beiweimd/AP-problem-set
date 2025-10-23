// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
using namespace std;
int t,n,k,h,r;
ll f[10][maxn]; // f[k][i] 将前i个长度的序列 分成k块的最大贡献
ll suf[maxn],a[maxn];
int to[201][maxn];
vector<int > ans ;
ll pow(ll a){return a*a;}
int top;
int q[maxn];
double cross(int j,int k){
    if(suf[j]==suf[k]) return -1e18;
    return (f[r&1^1][k]-pow(suf[k])-f[r&1^1][j]+pow(suf[j]))*1.0/(suf[j]-suf[k]);
}
void slove(){
    cin>>n>>k;for(int i=1;i<=n;i++){
        cin>>a[i];suf[i]=suf[i-1]+a[i];
    }
    // 每个点的坐标是f[i][j],suf[j]
    for( r=1;r<=k;r++){
        h=t=0;
        for(int i=1;i<=n;i++){
            // 因为斜率递增 所以没必要二分
            while(h<t && cross(q[h],q[h+1])<=suf[i]) h++;
            int l=q[h];
            f[r&1][i]=f[r&1^1][l]+suf[l]*(suf[i]-suf[l]);
            to[r][i]=l;
            while(h<t && cross(q[t-1],q[t])>=cross(q[t],i)) t--;
            q[++t]=i;
        }
    }	
    cout<<f[k&1][n]<<"\n";
    for(int i=k,u=n;i>=1;i--){
        u=to[i][u];cout<<u<<" ";
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    slove();
    return (0-0);
}