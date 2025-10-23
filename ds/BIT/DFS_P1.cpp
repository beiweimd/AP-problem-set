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
int n,q,p;
int val[maxn],lef[maxn],rig[maxn];
vector<int >e[maxn];
int lowbit(int x){return x&(-x);}
template <class T>
struct BIT{
    T c[maxn];
    void single_point_updata(int pos,int diff){
        for(;pos<=n;pos+=lowbit(pos)){
            c[pos]+=diff;
        }
        return ;
    }
    ll get_pre(int x){
        ll s=0ll;
        for(;x!=0;x-=lowbit(x)){
            s+=c[x];
        }
        return s;
    }
};
BIT<ll>c1,c2;
// c1维护的是子树和
// c2维护的是点到根路径的距离和
void dfs(int x,int fa){
    p++;
    lef[x]=p;
    for(auto u:e[x]){
        if(u==fa) continue;
        dfs(u,x);
    }
    rig[x] = p;
    return ;
}
void slove(){
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        cin>>val[i];
        c1.single_point_updata(lef[i], val[i]);
        c2.single_point_updata(lef[i], val[i]);
        c2.single_point_updata(rig[i]+1, -1*val[i]);
    }
    while(q--){
        int op,x,y;
        cin>>op;
        if(op==1){
            cin>>x>>y;
            int diff=y-val[x];
            c1.single_point_updata(lef[x], diff);
            c2.single_point_updata(lef[x], diff);
            c2.single_point_updata(rig[x]+1, -1*diff);
            val[x]=y;
        }
        else{
            cin>>x;
            cout<<c1.get_pre(rig[x])-c1.get_pre(lef[x]-1)<<" ";
            cout<<c2.get_pre(lef[x])<<"\n";
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