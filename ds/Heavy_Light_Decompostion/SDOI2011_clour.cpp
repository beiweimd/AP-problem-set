#include<bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p){return os << '(' << p.first << ", " << p.second << ')';}
template<typename C,typename D = typename enable_if <!is_same<C, string>::value,typename C::value_type>::type>
ostream &operator<<(ostream &os, const C &v){os << '{';string sep;
    for (const D &x : v)os << sep << x, sep = ", ";return os << '}';}
void dbg_out(){cerr << endl;}
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T){cerr << ' ' << H;dbg_out(T...);}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define PII pair<int,int>
#define lowbit(x) (x&(-x))
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define ll long long
const int mod = 1e9+7;
const int N = 1e5+1000;
const int dx[8]={0,0,1,-1,1,1,-1,-1};
const int dy[8]={1,-1,0,0,1,-1,1,-1};

// 注意零元
struct Info{
    int l=0,sum=0,r=0;
    int lzy=0;
};
Info operator+(const Info &l,const Info &r){
    Info res;
    res.l=l.l;res.r=r.r;
    res.sum=l.sum+r.sum+(l.r&&r.l&&l.r!=r.l);
    return res;
}
struct SegmentTree{
    int n;
    std::vector<Info> info;
    SegmentTree(){}
    SegmentTree(int n, Info _init = Info()){init(std::vector<Info>(n, _init));}
    SegmentTree(const std::vector<Info> &_init){init(_init);}
    void init(const std::vector<Info> &_init){
        n=static_cast<int>(_init.size());
        info.assign((n<<2)+1,Info());
        std::function<void(int,int,int)> build = [&](int p,int l,int r){
            if(l==r){
                info[p]=_init[l - 1];
                return;
            }
            int m=(l+r)/2;
            build(2*p,l,m);
            build(2*p+1,m+1,r);
            push_up(p,l,r);
        };
        build(1,1,n);
    }
    void push_up(int p,int l,int r){
        int m=(l+r)/2;
        push_down(p*2,l,m);
        push_down(p*2+1,m+1,r);
        info[p]=info[2*p]+info[2*p+1];
    }
    void push_down(int p,int l,int r){
        lzy_use(p,l,r);
        if(l!=r){
            lzy_union(p,p*2);
            lzy_union(p,p*2+1);
        }
        lzy_init(p,l,r);
    }
    void lzy_init(int p,int l,int r){//初始化lzy
        info[p].lzy=0;
    }
    void lzy_use(int p,int l,int r){//lzy对p节点使用
        auto &[left,sum,right,lzy]=info[p];
        left=right=lzy;
        sum=1;
    }
    void lzy_union(int fa,int ch){//fa将lzy传递给ch
        info[ch].lzy=info[fa].lzy;
    }
    void modify(int p, const Info &v){modify(1,1,n,p,v);}//单点修改
    void modify(int p,int l,int r,int x,const Info &v){
        push_down(p,l,r);
        if(l==r){
            info[p]=v;
            return;
        }
        int m = (l + r) / 2;
        if(x<=m){
            modify(2*p,l,m,x,v);
        }else{
            modify(2*p+1,m+1,r,x,v);
        }
        push_up(p,l,r);
    }
    void modify(int l,int r, int op){modify(1,1,n,l,r,op);}//区间修改
    void modify(int p,int l,int r,int x,int y,int op){
        push_down(p,l,r);
        if(x<=l&&r<=y){
            info[p].lzy=op;
            return;
        }
        int m = (l + r) / 2;
        if(x<=m){
            modify(2*p,l,m,x,y,op);
        }
        if(y>=m+1){
            modify(2*p+1,m+1,r,x,y,op);
        }
        push_up(p,l,r);
    }
    Info query(int l,int r){return query(1,1,n,l,r);}
    Info query(int p,int l,int r,int x,int y){
        push_down(p,l,r);
        if(l>y||r<x){
            return Info();
        }
        if(l>=x&&r<=y){
            return info[p];
        }
        int m=(l+r)/2;
        return query(2*p,l,m,x,y)+query(2*p+1,m+1,r,x,y);
    }
};

SegmentTree tree;

int n,m;
vector<int> g[N],a;
int dep[N],fa[N],sz[N];
int id[N],l[N],r[N],tot=0;
int hs[N],top[N];

void dfs1(int u,int f){
    dep[u]=dep[f]+1;
    fa[u]=f;
    sz[u]=1;
    hs[u]=-1;
    for(auto v:g[u]){
        if(v==f) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(hs[u]==-1||sz[v]>sz[hs[u]]) hs[u]=v;
    }
}
void dfs2(int u,int head){
    l[u]=++tot;
    id[tot]=u;
    top[u]=head;
    if(hs[u]!=-1) dfs2(hs[u],head);
    for(auto v:g[u]){
        if(v!=fa[u]&&v!=hs[u]){
            dfs2(v,v);
        }
    }
    r[u]=tot;
}

int query(int u,int v){
    Info res;
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]]){
            res=res+tree.query(l[top[u]],l[u]);
            u=fa[dep[u]];
        }else{
            res=res+tree.query(l[top[v]],l[v]);
            v=fa[dep[v]];
        }
    }
    res=res+(dep[u]<dep[v]?tree.query(l[u],l[v]):tree.query(l[v],l[u]));
    return res.sum;
}
void modify(int x,int y,int d){ // 树上 x y路径的点修改为d
    while(top[x]!=top[y]){ // 如果x y不在一个重链里面
        if(dep[top[x] ]>dep[top[y]] ) {
            tree.modify(l[top[x]],l[x],d);
            x=fa[top[x]];
        }
        else {
            tree.modify(l[top[y]],l[y],d);
            y=fa[top[y]];
        }
    }
    if(dep[x]<dep[y]) {
        tree.modify(l[x],l[y],d);
    }
    else {
        tree.modify(l[y],l[x],d);
    }
    return ;
}
//这是一份样例都没过的
void solve(){
    cin >> n >> m;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,1);
    tree=SegmentTree(n);
    for(int i=1;i<=n;i++){
        tree.modify(l[i],{a[i],1,a[i],0});
    }
    for(int i=1;i<=m;i++){
        char op;int u,v,x;
        cin >> op >> u >> v;
        if(op=='Q'){
            cout << query(u,v) << "\n";
        }else{
            cin >> x;
            modify(u,v,x);
        }
    }
}
int main(){
// #ifndef ONLINE_JUDGE
//     freopen("zin.txt","r",stdin);
//     freopen("zout.txt","w",stdout);
// #endif
    ios::sync_with_stdio(false);std::cin.tie(0);
    int _=1;
    // cin >> _;
    // while(cin >> ){
    while(_--){
        solve();
        if(_) cout << "\n";
    }
}
// // ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// #include <bits/stdc++.h>
// typedef long long ll;
// typedef long double db;
// const ll mod=1e9+7;
// const db pi=acos(-1);
// const db eps=1e-10;
// const int maxn=2e5+100;
// using namespace std;
// int t,tot,n,m;
// vector<int >e[maxn];
// int c[maxn];
// int deep[maxn],top[maxn]; // top代表每个点在重链上的 链头是哪个结点(不是dfs序)
// int siz[maxn],hs[maxn],l[maxn],r[maxn],f[maxn],dfn[maxn]; //
// //第一遍先求出每个点的深度 字树数量和 重儿子  每个点的父亲
// void dfs1(int x,int fa,int dep){
//     siz[x]=1;
//     deep[x]=dep;
//     hs[x]=-1;
//     f[x]=fa;
//     for(auto u:e[x]){
//         if(u!=fa){
//             dfs1(u,x,dep+1);
//             siz[x]+=siz[u];
//             if(hs[x]==-1 or siz[hs[x]]<siz[u]){
//                 hs[x]=u;
//             }
//         } 
//     }
//     return ;
// }
// void dfs2(int  x,int fa){ // 这里的fa不再是上一个过来的 结点 而是代表目前在搜的这条重链的结点的老大 或者说链头
//     l[x]=++tot; // 先加 后赋值  l[x]=tot++ //这个就是先赋值后++
//     dfn[tot]=x;  // dfs序对应的是哪个结点
//     top[x]=fa;
//     //这里是dfs序
//     if(hs[x]!=-1){
//         dfs2(hs[x],fa) ;  //这里先去找重链
//     }
//     for(auto u:e[x]){
//         if(u!=f[x] && u!=hs[x]){
//             dfs2(u,u); // 这个时候是一条新的重链
//         }
//     }
//     r[x]=tot;
// }
// struct info{
//     //int minv,mincnt;
//    // int mss,sum;// 代表这个区间的最大数值 和总和
//    int lefc,rigc,len;// 代表这个区间最左边和最右边的颜色 以及这个区间的颜色总段数是多少
// };
// info operator +(const info &a,const info &b){
//     return (info){a.lefc,b.rigc,a.len+b.len+(a.rigc!=b.lefc)};
// }
// struct node{
//     info val;
//     int t; // 标记
// }; // 定义线段树结构体 属性是最小数值
// node seg[maxn*4];
// void updata(int x){
//     seg[x].val=seg[x*2].val + seg[x*2+1].val;
// }
// void settag(int id,int t){
//     seg[id].val={t,t,0};
//     seg[id].t=t;
// }
// void pushdown(int id){
//     if(seg[id].t!=0){
//         settag(id*2,seg[id].t);
//         settag(id*2+1,seg[id].t);
//         seg[id].t=0;
//     }
//     return ;
// }
// void build(int id,int l, int r){
//     if(l==r){
//         seg[id].val={c[dfn[l]],c[dfn[l]],0}; // 这里是颜色
//         return ;
//     }
//     int mid=(l+r)/2;
//     build(id*2,l,mid);
//     build(id*2+1,mid+1,r);
//     updata(id);
// }
// void modify(int  id,int l,int r,int ql,int qr,int t){ // 线段树上的区间修改
//     if(l==ql && r==qr){
//         settag(id,t);return ;
//     }
//     int mid=(l+r)/2;
//     pushdown(id);
//     if(qr<=mid)  modify(id*2,l,mid,ql,qr,t); // 如果待查的区间在目前区间的左字数
//     else {
//         if(ql>mid)  modify(id*2+1,mid+1,r,ql,qr,t);
//         else{  // 这种情况 说明查询区间在当前区间的交界处   [l,]
//                 modify(id*2,l,mid,ql,mid,t);
//                 modify(id*2+1,mid+1,r,mid+1,qr,t);
//         }
//     }
//     updata(id);
// }
// info query(int id,int l ,int r,int ql,int qr ){ // [ql ,qr]是目前的待查询期间
//     if(l==ql && r==qr) return seg[id].val;
//     int mid=(l+r)/2;
//     pushdown(id);
//     if(qr<=mid) return query(id*2,l,mid,ql,qr); // 如果待查的区间在目前区间的左字数
//     else {
//         if(ql>mid) return query(id*2+1,mid+1,r,ql,qr);
//         else{  // 这种情况 说明查询区间在当前区间的交界处   [l,]
//             return query(id*2,l,mid,ql,mid)+
//                 query(id*2+1,mid+1,r,mid+1,qr);
//         }
//     }
// }
// int  query(int x,int y){ //查找树上x y之间的颜色段数
//     info ansx={0,0,-1};
//     info ansy={0,0,-1};
//     // 记录两条路径的数值 有先后的区别
//     while(top[x]!=top[y]){ // 如果x y不在一个重链里面
//         if(deep[top[x] ]>deep[top[y]] ) {
//             ansx=query(1,1,n,l[top[x]],l[x])+ansx;
//             x=f[top[x]];
//         }
//         else {
//             ansy=query(1,1,n,l[top[y]],l[y])+ansy;
//             y=f[top[y]];
//         }
//     }
//     if(deep[x]<=deep[y])  ansy=query(1,1,n,l[x],l[y])+ansy;
//     else  ansx=query(1,1,n,l[y],l[x])+ansx;
//     return ansx.len+ansy.len + (ansx.lefc!=ansy.lefc)+1;
// }
// void modify(int x,int y,int d){ // 树上 x y路径的点修改为d
//     while(top[x]!=top[y]){ // 如果x y不在一个重链里面
//         if(deep[top[x] ]>deep[top[y]] ) {
//             modify(1,1,n,l[top[x]],l[x],d);
//             x=f[top[x]];
//         }
//         else {
//             modify(1,1,n,l[top[y]],l[y],d);
//             y=f[top[y]];
//         }
//     }
//     if(deep[x]<deep[y]) {
//         modify(1,1,n,l[x],l[y],d);
//     }
//     else {
//         modify(1,1,n,l[y],l[x],d);
//     }
// }
// void slove(){
//     cin>>n>>m;
//     for(int i=1;i<=n;i++) cin>>c[i];
//     for(int i=1;i<n;i++){
//         int u,v;cin>>u>>v;
//         e[u].push_back(v);
//         swap(u,v);
//         e[u].push_back(v);
//     }
// 	 dfs1(1,-1,1);
//      dfs2(1,1);
//      build(1,1,n);
//     for(int i=1;i<=m;i++){
//         char op;int x,y;cin>>op>>x>>y;
//         if(op=='C'){
//             int d;cin>>d;
//            modify(x,y,d);
//         } 
//         else {
//             cout<<query(x,y)<<"\n";
//         }
//         //cout<<i<<endl;
//     }
//     return;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     t=1;
//     while(t--){
// 		slove();
//     }
//     return 0;
// }