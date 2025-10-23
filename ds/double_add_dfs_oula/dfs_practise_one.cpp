// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
typedef unsigned long long ull;
using namespace std;
int t,q,n,u,v;
int lowbit(int p) {return p&(-p);}
template<class T>
struct BIT{
    T c[maxn];
    void modify(int x,ll d){
        for(;x<=n;x+=lowbit(x))c[x]+=d;
        return ;
    }
    ll query(int x){
        ull s=0;
        for(;x!=0;x-=lowbit(x)) s+=c[x];
        return s;
    }
};
vector<int >e[maxn];
ll w[maxn];
int lef[maxn],rig[maxn];
BIT<ll>c1,c2;  //c2维护的是点到根的路径和 用差分的思路搞
// c1维护的是每个字数的和 用区间和来搞
int pos=1;
void  dfs(int x,int fa){
    lef[x]=pos;
    for(auto u:e[x]){
      if(u!=fa){
        pos++;
        dfs(u,x);
      }
    }
    rig[x]=pos;
    return ;
}
void slove(){
  cin>>n>>q;
  for(int i=1;i<n;i++){
    cin>>u>>v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1,-1); 
  for(int i=1;i<=n;i++){
    cin>>w[i];
    c1.modify(lef[i],w[i]);
    c2.modify(lef[i],w[i]);
    c2.modify(rig[i]+1,-1*w[i]);
  } 
  for(int i=1;i<=q;i++){
    int op,x;
    ll y;
    cin>>op>>x;
    if(op==1){
      cin>>y;
      ll diff=y-w[x];
      c1.modify(lef[x],diff);
      c2.modify(lef[x],diff);
      c2.modify(rig[x]+1,-1*diff);
      w[x]=y;
    }
    else{
      cout<<c1.query(rig[x])-c1.query(lef[x]-1)<<" ";
      cout<<c2.query(lef[x])<<"\n";
    }
  }
  // for(int i=1;i<=n;i++){
  //   cout<<lef[i]<<" "<<rig[i]<<"\n";
  // }
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