// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=4e5;
using namespace std;
int t,n;
int a[maxn];
ll c[maxn];
int lowbit(int p) {return p&(-p);}
void modify(int x,ll d){
    for(;x<=n;x+=lowbit(x))c[x]+=d;
    return ;
}
ll query(int x){
    ll s=0;
    for(;x!=0;x-=lowbit(x)) s+=c[x];
    return s;
}
ll check(){
    ll ans=0;
    for(int i=1;i<=n;i++) c[i]=0ll;
    vector<array<int,2> >p;
    for(int i=1;i<=n;i++){
        p.push_back({a[i],i});
    }
    sort(p.begin(),p.end(),[](const array<int,2> &x,const array<int,2>&y){
        return x[0]>y[0] ;// 处理V 大的先处理
    }
    );
    for(int i=0;i<n;i++){
        ll lef=query(p[i][1]);
        ll rig=query(n)-lef;
        ans=ans+lef*rig;
        modify(p[i][1],1);
    }
    return ans;
}
void slove(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<check()<<" "; // 先处理V的情况
    for(int i=1;i<=n;i++){
        a[i]=n-a[i]+1;
    }
    cout<<check()<<" "; // 翻转 处理处理U的情况
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