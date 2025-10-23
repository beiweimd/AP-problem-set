// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
const int M=33000;
using namespace std;
int n,ans[maxn];
struct node{
    int l,r,id;
};
vector<node>v;
int lowbit(int x) {return x&(-x);}
template <class T>
struct BIT{
    T c[maxn];
    void updata(int pos,ll diff){
        for(;pos<=M;pos+=lowbit(pos)){
            c[pos]+=diff;
        }
        return ;
    }
    ll get(int x){
        ll s=0ll;
        for(;x!=0;x-=lowbit(x)){
            s+=c[x];
        }
        return s;
    }
};
int cnt[maxn];
BIT<ll>c1;
void slove(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        y++;
        v.push_back(node{x,y,i});
    }
    sort(v.begin(),v.end(),[](const node&x,const node&y){
        if(x.l!=y.l) return x.l<y.l;
        else return x.r<y.r;
    }
    );
    for(int i=0;i<n;i++){
        ans[v[i].id]=c1.get(v[i].r);
        c1.updata(v[i].r,1);
    }
    for(int i=1;i<=n;i++) cnt[ans[i]]++;
    for(int i=0;i<n;i++) cout<<cnt[i]<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
		slove();
    }
    return (0-0);
}