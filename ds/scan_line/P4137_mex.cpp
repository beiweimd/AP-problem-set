// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=3e5;
using namespace std;
int t,n,q,l,r;
int a[maxn],ans[maxn];
vector<pair<int,int> > p[maxn];
struct node{
    ll val;
}; // 定义线段树结构体 属性是最大数值
node seg[maxn*4];
void updata(int x){
    seg[x].val=min(seg[x*2].val , seg[x*2+1].val);//更新最大数值
}
void change(int id ,int l,int r,int pos,int x){ // a[pos]=x 单点修改
    if(l==r){
        seg[id].val=x;return ;
    }
    int mid=(l+r)/2;
    if(pos<=mid) change(id*2,l,mid,pos,x);
    else change(id*2+1,mid+1,r,pos,x);
    updata(id);
}
int binary(int id,int l,int r,int d ){ 
    if(l==r) return l;//叶子结点代表的属性是具体的这个位置数组的pos 
    int mid=(l+r)/2;
    if(seg[id*2].val<d) return binary(id*2,l,mid,d); // 就如果说 左半部分 小的部分 最小的位置已经小于d了 那么答案显然是在左边字树
    else return binary(id*2+1,mid+1,r,d);
}
void slove(){
	cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];a[i]=min(a[i],n+1);
    }
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        p[r].push_back({l,i});
        // 记录每个右端点需要查找的l和id
    }
    for(int i=1;i<=n;i++){ //类似扫描线的做法 去移动右端点
        change(1,0,n+1,a[i],i); // 每个查询最右端是更优秀的 所以要更新pos[a[r]]的位置
        // 找到最小的pos[x]使得其在查询的l左边 改为维护pos数组和线段树上的二分
        for(auto u:p[i]){
            ans[u.second]=binary(1,0,n+1,u.first);
        }
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
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