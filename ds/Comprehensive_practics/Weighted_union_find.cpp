// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=3e5;
using namespace std;
int n,q,op,l,r;
ll x,t;
int f[maxn];
ll w[maxn];//w[x]代表的是 a[x]和a[f[x]]的差值 其实就是到父亲结点的位置
int getf(int x ){
    if(f[x]==x) return x;
    else{
        int p=f[x];//本来这个点的父亲
        getf(p);//先更新父亲
        w[x]=w[x]+w[p]; // 因为现在路径压缩了
        f[x]=f[p];//路径压缩
        return f[x];
    }
}
void slove(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=q;i++){
        cin>>op>>l>>r;
        l=(l+t)%n+1;
        r=(r+t)%n+1;
        if(op==1){
            cin>>x;
            if(getf(l)==getf(r)) continue; 
            w[f[l]]=x-w[l]+w[r];
            f[f[l]]=f[r];
        }
        else{
            if(getf(l)!=getf(r)) continue; 
            else{ // 如果l r在一个连通块里面 可以被找到 这个时候fa=f[l]=f[r] w[l]=a[l]-fa w[r]=a[r]-fa a[l]-a[r]=w[l]-w[r]
                ll num=w[l]-w[r];
                cout<<num<<"\n";
                t=abs(num);
            }
        }
    }
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    slove();
    return 0;
}