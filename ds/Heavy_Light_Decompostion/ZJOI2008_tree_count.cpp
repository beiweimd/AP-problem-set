// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=1e5+100;
using namespace std;
int t,tot,n,m;
vector<int >e[maxn];
int w[maxn];
int deep[maxn],top[maxn]; // top代表每个点在重链上的 链头是哪个结点(不是dfs序)
int siz[maxn],hs[maxn],l[maxn],r[maxn],f[maxn],dfn[maxn]; //
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
            if(hs[x]==-1 or siz[hs[x]]<siz[u]){
                hs[x]=u;
            }
        } 
    }
    return ;
}
void dfs2(int  x,int fa){ // 这里的fa不再是上一个过来的 结点 而是代表目前在搜的这条重链的结点的老大 或者说链头
    l[x]=++tot; // 先加 后赋值  l[x]=tot++ //这个就是先赋值后++
    dfn[tot]=x;  // dfs序对应的是哪个结点
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
struct info{
    //int minv,mincnt;
    int mss,sum;// 代表这个区间的最大数值 和总和
};
info operator +(const info &a,const info &b){
    info p;
    p.mss=max({a.mss,b.mss}); 
    p.sum=a.sum+b.sum; // 大区间和等于两区间相加
    return p;
}
struct node{
    info val;
}; // 定义线段树结构体 属性是最小数值
node seg[maxn*4];
void updata(int x){
    seg[x].val=seg[x*2].val + seg[x*2+1].val;
}
void build(int id,int l, int r){
    if(l==r){
        seg[id].val={w[dfn[l]],w[dfn[l]]};
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    updata(id);
}
void change(int id ,int l,int r,int pos,int x){ // a[pos]=x 单点修改
    if(l==r){
        seg[id].val={x,x};return ;
    }
    int mid=(l+r)/2;
    if(pos<=mid) change(id*2,l,mid,pos,x);
    else change(id*2+1,mid+1,r,pos,x);
    //这里也要更新一下目前结点 不然回溯不回来
    updata(id);
}
info query(int id,int l ,int r,int ql,int qr ){ // [ql ,qr]是目前的待查询期间
    if(l==ql && r==qr) return seg[id].val;
    int mid=(l+r)/2;
    if(qr<=mid) return query(id*2,l,mid,ql,qr); // 如果待查的区间在目前区间的左字数
    else {
        if(ql>mid) return query(id*2+1,mid+1,r,ql,qr);
        else{  // 这种情况 说明查询区间在当前区间的交界处   [l,]
            return query(id*2,l,mid,ql,mid)+
                query(id*2+1,mid+1,r,mid+1,qr);
        }
    }
}
info query(int x,int y){
    info s;
    s.mss=-1e9;
    s.sum=0;
    while(top[x]!=top[y]){ // 如果x y不在一个重链里面
        if(deep[top[x] ]>deep[top[y]] ) {
            s=s+query(1,1,n,l[top[x]],l[x]);
            x=f[top[x]];
        }
        else {
            s=s+query(1,1,n,l[top[y]],l[y]);
            y=f[top[y]];
        }
    }
    if(deep[x]<deep[y])  s=s+query(1,1,n,l[x],l[y]);
    else s=s+query(1,1,n,l[y],l[x]);
    return s;
}
void slove(){
    cin>>n;for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        swap(u,v);
        e[u].push_back(v);
    }
    for(int i=1;i<=n;i++) cin>>w[i];
	 dfs1(1,-1,1);
     dfs2(1,1);
     build(1,1,n);
    cin>>m;for(int i=1;i<=m;i++){
        char op[10];int x,y;cin>>op>>x>>y;
        if(op[0]=='C'){
            change(1,1,n,l[x],y);
        } 
        else {
            auto ans=query(x,y);
            if(op[1]=='M' ) cout<<ans.mss<<"\n";
            else cout<<ans.sum<<"\n";
        }
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