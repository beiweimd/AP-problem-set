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
int t,q,n,u,v,root;
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
ll w[maxn],sum;
int lef[maxn],rig[maxn];
int deep[maxn];
int f[20][maxn];
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
void dfs2(int x,int fa,int dep){
    deep[x]=dep;
    for(auto u:e[x]){
        if(u!=fa){
            f[0][u]=x; // 更新f
            dfs2(u,x,dep+1);
        }
    }
    return ;
}
int find(int l,int r){
    if(deep[l]<deep[r]) swap(l,r);
    int d=deep[l]-deep[r]-1;
    for(int j=18;j>=0;j--){
        if((d&(1<<j))!=0){
            l=f[j][l];
        }
    }
    //cout<<l<<" "<<r<<"***"<<endl;
    if(f[0][l]==r) return l;
    for(int j=18;j>=0;j--){
        if(f[j][l]!=f[j][r]){
            l=f[j][l];
            r=f[j][r];
        }
    }
    return l;
}
void slove(){
  cin>>n>>q;
  for(int i=1;i<n;i++){
    cin>>u>>v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
    root=1; // 开始的时候根节点是1
  dfs(1,-1); 
  dfs2(1,-1,1);
  for(int i=1;i<=n;i++){
    cin>>w[i];
    c1.modify(lef[i],w[i]);
    sum+=w[i];
  } 
  for(int j=1;j<=18;j++){
    for(int i=1;i<=n;i++){
        f[j][i]=f[ j-1]     [  f[j-1][i]    ]      ;
    }
}
  for(int i=1;i<=q;i++){
    int op,x;
    ll y;
    cin>>op>>x;
    if(op==1){
      cin>>y;
      ll diff=y-w[x];
      sum+=diff;
      c1.modify(lef[x],diff);
      w[x]=y;
    }
    else{
        if(op==2){
            if(x==root){ //是根的情况直接输出全部的和
                cout<<sum<<"\n"; 
            }
            else{ // 下面要判断 目前的根是不是在x的字树里 如果说不是的话 那么我们就正常计算答案即可
                int z=f[0][find(x,root)];
                //cout<<z<<" "<<x<<" "<<i<<endl;
                if(z!=x){ // 说明我们目前的根不在字数里
                    cout<<c1.query(rig[x])-c1.query(lef[x]-1)<<"\n";
                }
                else{

                    int pos=find(x,root);
                   cout<<sum-(c1.query(rig[pos])-c1.query(lef[pos]-1) )<<"\n";
                }
            }
        }
        else root=x;
    }
  }
//   for(int i=1;i<=n;i++){
//     cout<<lef[i]<<" "<<rig[i]<<"\n";
//   }
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