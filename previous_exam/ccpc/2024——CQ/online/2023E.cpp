// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n;
char o[30];
int a[60][60];
set<array<int,2>>ans;
void dfs(int x,int y,int ord){
    if(ord==n+1){
        auto u=array<int,2>{x-n-1,y-n-1};
        ans.insert(u);
        return ;
    }
    int dx=x,dy=y;
    if(o[ord]=='L') dx--;
    if(o[ord]=='R') dx++;
    if(o[ord]=='U') dy++;
    if(o[ord]=='D') dy--;
    if(dx==n+1 && dy==n+1){
        dfs(dx,dy,ord+1);
        return;
    }
    if(a[dx][dy]==0){
        a[dx][dy]=2;
        dfs(dx,dy,ord+1);
        a[dx][dy]=1;
        dfs(x,y,ord+1);
        a[dx][dy]=0; // 这里也要回溯 
    }
    else{
        if(a[dx][dy]==2) dfs(dx,dy,ord+1);
        else dfs(x,y,ord+1);
    }
    return ;
}
void slove(){
	cin >> n;
    for(int i=1;i<=n;i++){
        cin>>o[i];
    }
    dfs(n+1,n+1,1);
    cout<<ans.size()<<"\n";
    for(auto u:ans){
        cout<<u[0]<<" "<<u[1]<<"\n";
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