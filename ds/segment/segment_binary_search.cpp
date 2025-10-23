// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=3e5;
using namespace std;
int t,n,q;
ll a[maxn];
struct node{
    ll val;
}; // 定义线段树结构体 属性是最大数值
node seg[maxn*4];
void updata(int x){
    seg[x].val=max(seg[x*2].val , seg[x*2+1].val);//更新最大数值
}
void build(int id,int l, int r){
    if(l==r){
        seg[id].val=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    updata(id);
}
void change(int id ,int l,int r,int pos,int x){ // a[pos]=x 单点修改
    if(l==r){
        seg[id].val=x;return ;
    }
    int mid=(l+r)/2;
    if(pos<=mid) change(id*2,l,mid,pos,x);
    else change(id*2+1,mid+1,r,pos,x);
    //这里也要更新一下目前结点 不然回溯不回来
    updata(id);
}
int binary(int id,int l,int r,int ql,int qr ,ll d ){
    if(l==ql && r==qr) {
        if(seg[id].val<d) return -1; // 如果区间最大数值小于d 不在递归下去
        else{
            if(l==r) return l; // 叶子节点 直接返回
            int mid=(l+r)/2; // 继续递归
            int pos=binary(id*2,l,mid,ql,mid,d); // 如果左区间找到了 直接返回
            if(pos!=-1) return pos;
            else return binary(id*2+1,mid+1,r,mid+1,qr,d); //找不到在去找右区间
        }
    }
    int mid=(l+r)/2;
    if(qr<=mid) return binary(id*2,l,mid,ql,qr,d); // 如果待查的区间在目前区间的左字数
    else {
        if(ql>mid) return binary(id*2+1,mid+1,r,ql,qr,d);
        else{  // 这种情况 说明查询区间在当前区间的交界处   [l,]
            int mid=(l+r)/2; // 继续递归
            int pos=binary(id*2,l,mid,ql,mid,d); // 如果左区间找到了 直接返回
            if(pos!=-1) return pos;
            else return binary(id*2+1,mid+1,r,mid+1,qr,d); //找不到在去找右区间
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
            cin>>l>>r>>d;
            int ans=binary(1,1,n,l,r,d);
            cout<<ans<<"\n";
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