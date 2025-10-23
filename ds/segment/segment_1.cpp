// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=3e5;
using namespace std;
int t,n,q;
ll a[maxn];
struct info{
    //int minv,mincnt;
    ll mss,pre,suf,sum;// 代表这个区间的最大字段和 最大前缀和 最大后缀和 和总和
    info () { }
    info (ll x): mss(x),pre(x),suf(x),sum(x) {}// 初始化赋值
};
info operator +(const info &a,const info &b){
    info p;
    p.mss=max({a.mss,b.mss,a.suf+b.pre}); // 分治 有点类似平面最近点对那样搞
    p.pre=max({a.pre,a.sum+b.pre}); // 最大的前缀是左区间的最大 或者是左边全部加上右区间前缀
    p.suf=max({b.suf,b.sum+a.suf});// 同理
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
        seg[id].val=info(a[l]);
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    updata(id);
}
void change(int id ,int l,int r,int pos,int x){ // a[pos]=x 单点修改
    if(l==r){
        seg[id].val=info(x);return ;
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
void slove(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    } build(1,1,n);
    while(q--){
        int op,l,x,d,r;
        cin>>op;
        if(op==1){
            cin>>x>>d;
            change(1,1,n,x,d);
        }
        else{
            cin>>l>>r;
            info ans=query(1,1,n,l,r);
            cout<<ans.mss<<"\n";
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