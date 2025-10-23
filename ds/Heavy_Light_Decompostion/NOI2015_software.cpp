// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e5+100;
using namespace std;
int t,tot,n,m;
vector<int >e[maxn];
int c[maxn];
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
    int val;//代表这个区间已经安装了多少个
   // int mss,sum;// 代表这个区间的最大数值 和总和
   //int lefc,rigc,len;// 代表这个区间最左边和最右边的颜色 以及这个区间的颜色总段数是多少
};
info operator +(const info &a,const info &b){
    return info{  a.val+b.val  };
}
struct node{
    int val;
    int sz;
    int t; // 标记
}; // 定义线段树结构体 属性是最小数值
node seg[maxn*4];
void updata(int x){
    seg[x].val=seg[x*2].val + seg[x*2+1].val;
}
void settag(int id,int t){
    seg[id].val={t*seg[id].sz};
    seg[id].t=t;
}
void pushdown(int id){
    if(seg[id].t!=-1){
        settag(id*2,seg[id].t);
        settag(id*2+1,seg[id].t);
    }
    seg[id].t=-1;
    return ;
}
void build(int id,int l, int r){
    seg[id].t=-1;
    seg[id].sz=r-l+1;
    if(l==r){
        seg[id].val={0}; // 这里是代表初始的状态全部没有被安装
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    updata(id);
}
void modify(int  id,int l,int r,int ql,int qr,int t){ // 线段树上的区间修改
    if(l==ql && r==qr){
        settag(id,t);return ;
    }
    int mid=(l+r)/2;
    pushdown(id);
    if(qr<=mid)  modify(id*2,l,mid,ql,qr,t); // 如果待查的区间在目前区间的左字数
    else {
        if(ql>mid)  modify(id*2+1,mid+1,r,ql,qr,t);
        else{  // 这种情况 说明查询区间在当前区间的交界处   [l,]
                modify(id*2,l,mid,ql,mid,t);
                modify(id*2+1,mid+1,r,mid+1,qr,t);
        }
    }
    updata(id);
}
int query(int id,int l ,int r,int ql,int qr ){ // [ql ,qr]是目前的待查询期间
    if(l==ql && r==qr) return seg[id].val;
    int mid=(l+r)/2;
    pushdown(id);
    if(qr<=mid) return query(id*2,l,mid,ql,qr); // 如果待查的区间在目前区间的左字数
    else {
        if(ql>mid) return query(id*2+1,mid+1,r,ql,qr);
        else{  // 这种情况 说明查询区间在当前区间的交界处   [l,]
            return query(id*2,l,mid,ql,mid)+
                query(id*2+1,mid+1,r,mid+1,qr);
        }
    }
}
int  query(int x){ //查找树上x y之间的颜色段数
    int s=0;
    while(f[x]!=0){        //cout<<top[x]<<" "<<x<<"*";
        x=f[top[x]];
     }
    return s;
}
void modify(int x,int d){ 
        while(f[x]!=0){
           modify(1,1,n,l[top[x]],l[x],d);
           //cout<<top[x]<<" "<<x<<"*";
           x=f[top[x]];
        }
        //cout<<endl;
       // seg[1].val={d};
    return ;
}
void slove(){
    cin>>n; // 这里坐标移动一个位置 即+1
    for(int i=2;i<=n;i++){
        int num;cin>>num;num++;
        e[i].push_back(num);
        e[num].push_back(i);
    }
	 dfs1(1,-1,1);
     dfs2(1,1);
     build(1,1,n);
     cin>>m;
    for(int i=1;i<=m;i++){
        string op;
        int x;
        cin>>op>>x;x++;
        int len=r[x]-l[x]+1;// 计算这个区间有多少个数字
        int pre_cnt=query(1,1,n,1,n);
        if(op[0]=='i') {
            modify(x,1);
        }
        else{
            
            //cout<<l[x]<<" "<<r[x]<<"**";
            modify(1,1,n,l[x],r[x],0 ) ;
            // for(int i=1;i<=n;i++){
            //      cout<<query(1,1,n,i,i).val<<" ";
            // }
            // cout<<"\n";
        }
        //cout<<pre_cnt<<"\n";
        cout<<abs(pre_cnt-query(1,1,n,1,n))<<"\n";
        
    }
   //cout<<114514<<" "<<0721<<endl;
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