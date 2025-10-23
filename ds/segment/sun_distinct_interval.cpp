// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=3e5;
using namespace std;
int t,q,n,l,r1;
int lowbit(int x){return x&(-x);}
ll c[maxn];
void modify(int x,int d){
    for(;x<=n;x+=lowbit(x)) c[x]+=d;
}
ll query(int x){
    ll s=0;
    for(;x>0;x-=lowbit(x)) s+=c[x];
    return s;
}
int pos[maxn],a[maxn];
ll ans[maxn];
vector< pair<int,int > >p[maxn];
void slove(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=q;i++){
        cin>>l>>r1;
        p[r1].push_back(make_pair(l,i) ); // 代表这个点对应的 l 和id
    }
    for(int r=1;r<=n;r++){
        int pre=pos[a[r]];
        pos[a[r]]=r;
        modify(pre+1,a[r]); // 不能为0
        modify(r+1,-1*a[r]);
        for(auto u:p[r]){
            ans[u.second]=query(u.first);
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