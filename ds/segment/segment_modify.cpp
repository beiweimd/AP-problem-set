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
    ll tag; // 
    ll val;
};
node seg[maxn*4];
void updata(int id){
    seg[id].val=max(seg[id*2].val,seg[id*2+1].val);
}
void pushup(int id){
    if(seg[id].tag==0ll) return ;
    seg[id*2].tag+=seg[id].tag;
    seg[id*2+1].tag+=seg[id].tag;
    seg[id*2].val+=seg[id].tag;
    seg[id*2+1].val+=seg[id].tag;    
    seg[id].tag=0;
}
void build(int id,int l,int r){
    if(l==r) {
        seg[id]=node{0,a[l]};return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    updata(id);
}
void modify(int id,int l,int r,int ql,int qr,ll d ){
    if(l==ql && r==qr){
        seg[id].val+=d;
        seg[id].tag+=d; // 就是对这个点的lazy标记和他的数值都加上
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
ll query(int id,int l,int r,int ql,int qr){
    if(l==ql && r==qr){
        return seg[id].val;
    }
    int mid=(l+r)/2;
    pushup(id);
    if(qr<=mid) return query(id*2,l,mid,ql,qr);
    else {
        if(ql>mid) return query(id*2+1,mid+1,r,ql,qr);
        else {
            return max(query(id*2,l,mid,ql,mid),
            query(id*2+1,mid+1,r,mid+1,qr) );
        }
    }    
}
void slove(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }build(1,1,n);
    for(int i=1;i<=q;i++){
        int op,l,r;ll d;
        cin>>op>>l>>r;
        if(op==1){
            cin>>d;
            modify(1,1,n,l,r,d);
        }
        else cout<<query(1,1,n,l,r)<<"\n";
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