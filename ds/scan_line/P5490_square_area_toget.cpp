// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
//本题是一道简单的扫描线
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=3e5;
using namespace std;
int t,n,m,l,r,num,q,x,y;
ll ans;
int a[maxn];
vector<int >vx;
vector<array<int,4>>event; // 扫描线的事件
struct info{
    int minv,mincnt; // 定义最小数和出现的次数
};
info operator +(const info&a,const info &b){
    info p;
    p.minv=min(a.minv,b.minv);
    if(a.minv==b.minv){
        p.mincnt=a.mincnt+b.mincnt;
    }
    else{
        if(a.minv<b.minv) p.mincnt=a.mincnt;
        else p.mincnt=b.mincnt;
    }
    return p;
}
struct node{
    int  tag; //代表区间加标记
    info val;
}; // 定义线段树结构体 属性是最小数值
node seg[maxn*8];
void updata(int x){
    seg[x].val=seg[x*2].val + seg[x*2+1].val;
}
void settag(int id,int t){
    seg[id].val.minv= seg[id].val.minv + t;
    seg[id].tag+=t;
}
void pushup(int id){
    if(seg[id].tag!=0){
        settag(id*2,seg[id].tag);
        settag(id*2+1,seg[id].tag);
    }
    seg[id].tag=0;
}
void modify(int id,int l,int r,int ql,int qr,ll d ){
    if(l==ql && r==qr){
        settag(id,d);
        return ;
    }
    int mid=(l+r)/2;
    pushup(id);
    if(qr<=mid) modify(id*2,l,mid,ql,qr,d);
    else {
        if(ql>mid) modify(id*2+1,mid+1,r,ql,qr,d);
        else {
            modify(id*2,l,mid,ql,mid,d);
            modify(id*2+1,mid+1,r,mid+1,qr,d);
        }
    }
    updata(id);
}
void build(int id,int l, int r){
    if(l==r){
        seg[id].tag=0;
        seg[id].val={0,vx[r]-vx[r-1]};
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    updata(id);
}
void slove(){
	cin>>n;
    for(int i=1;i<=n;i++){ // 矩形面积并 平行X轴的线往Y轴上面扫 
        int x_1,x_2,y_1,y_2;
        //cin>>x_1>>x_2>>y_1>>y_2;
        cin>>x_1>>y_1>>x_2>>y_2;
        vx.push_back(x_1);
        vx.push_back(x_2);
        event.push_back({y_1,1,x_1,x_2});
        event.push_back({y_2,-1,x_1,x_2}); // 在y1时刻产生贡献 y2时刻贡献消失
    }
    sort(vx.begin(),vx.end());
    sort(event.begin(),event.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end()); // 离散化处理
    build(1,1,vx.size()-1); // 离散化后的
    int totlen=seg[1].val.mincnt;
    int prey=0; // 开始的最小值
    for(auto e:event){
        int cov=totlen;;
        if(seg[1].val.minv==0) {
            cov=totlen-seg[1].val.mincnt;
        }
        //cout<<cov<<"\n";
        ans=ans+(ll)cov*(e[0]-prey);
        prey=e[0];
        int x1=lower_bound(vx.begin(),vx.end(),e[2])-vx.begin()+1;
        int x2=lower_bound(vx.begin(),vx.end(),e[3])-vx.begin();
        //cout<<e[0]<<" "<<e[1]<<" "<<e[2]<<" "<<e[3]<<"\n";
        if(x1>x2) continue;
        modify(1,1,vx.size()-1,x1,x2,e[1]);
        //cout<<e[0]<<" "<<e[1]<<" "<<e[2]<<" "<<e[3]<<"\n";
    }
    cout<<ans;
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
/*
// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=3e5;
using namespace std;
int t,a[maxn],n,q;
struct info{
    int minv,mincnt;
};
info operator +(const info&a,const info &b){
    info p;
    p.minv=min(a.minv,b.minv);
    if(a.minv==b.minv){
        p.mincnt=a.mincnt+b.mincnt;
    }
    else{
        if(a.minv<b.minv) p.mincnt=a.mincnt;
        else p.mincnt=b.mincnt;
    }
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
        seg[id].val=info{a[l],1};
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    updata(id);
}
void change(int id ,int l,int r,int pos,int x){ // a[pos]=x 单点修改
    if(l==r){
        seg[id].val=info{x,1};return ;
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
            cout<<ans.minv<<" "<<ans.mincnt<<"\n";
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
*/