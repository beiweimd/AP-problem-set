// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=1e6+100;
using namespace std;
int t,tot,n,m;
vector<int >e[maxn];
int deep[maxn],top[maxn]; // top代表每个点在重链上的 链头是哪个结点(不是dfs序)
int siz[maxn],hs[maxn],l[maxn],r[maxn],f[maxn],id[maxn]; // id是这个结点的dfs序
//第一遍先求出每个点的深度 字树数量和 重儿子  每个点的父亲
void dfs1(int x,int fa,int dep){
    siz[x]=1;
    deep[x]=dep;
    hs[x]=-1;
    f[x]=fa;
    for(auto u:e[x]){
        if(u!=fa){
            dfs1(u,x,dep+1);
            siz[x]+=siz[u];
            if(hs[x]==-1 or hs[x]<siz[u]){
                hs[x]=u;
            }
        } 
    }
    return ;
}
void dfs2(int  x,int fa){ // 这里的fa不再是上一个过来的 结点 而是代表目前在搜的这条重链的结点的老大 或者说链头
    l[x]=++tot; // 先加 后赋值  l[x]=tot++ //这个就是先赋值后++
    id[x]=tot;
    top[x]=fa;
    //这里是dfs序
    if(hs[x]!=-1){
        dfs2(hs[x],fa) ;  //这里先去找重链
    }
    for(auto u:e[x]){
        if(u!=f[x] && u!=hs[x]){
            dfs2(u,u); // 这个时候是一条新的重链
        }
    }
    r[x]=tot;
}
int query(int x,int y){
    while(top[x]!=top[y]){ // 如果x y不在一个重链里面
        if(deep[top[x] ]>deep[top[y]] ) x=f[top[x]];
        else y=f[top[y]]  ; // top[x]一定自己是一个轻结点 
    }
    if(deep[x]<deep[y]) return x;
    else return y;
}
void slove(){
    cin>>n;for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        swap(u,v);
        e[u].push_back(v);
    }
	 dfs1(1,-1,1);
     dfs2(1,1);
    cin>>m;for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
       cout<<query(u,v)<<"\n";
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    t=1;
    while(t--){
		slove();
    }
    return 0;
}