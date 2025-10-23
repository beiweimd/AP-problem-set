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
const int M=1e4;
const ll INF=1e17;
using namespace std;
int n,m,len,l,r,h;
int belong[maxn],a[maxn];
vector<int > e[M];
int bt(int x) {return (x-1)/len+1;}
int query(){
    int ans=0;
    int lef=belong[l];
    int rig=belong[r];
    if(lef==rig){
        for(int i=l;i<=r;i++) if(a[i]<=h) ans++;
        return ans;
    }
    for(int i=l;i<=lef*len;i++) if(a[i]<=h) ans++;
    for(int i=rig*len-len+1;i<=r;i++) if(a[i]<=h) ans++;
    for(int i=lef+1;i<rig;i++){
        auto pos=upper_bound(e[i].begin(),e[i].end(),h);
        ans=ans+(pos-e[i].begin());
    }
    return ans;
}
void slove(){
    for(int i=1;i<=len;i++) e[i].clear();
    cin>>n>>m;
    len=max(10,(int)sqrt(n)+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        belong[i]=bt(i);
        e[belong[i]].push_back(a[i]);
    }
    for(int i=1;i<=n;i+=len){
        sort(e[belong[i]].begin(),e[belong[i]].end());
    }
    while(m--){
        cin>>l>>r>>h;
        l++;r++;
        cout<<query()<<"\n";
    }
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case ";
        cout<<i<<":"<<"\n";
        slove();
    }
    return (0-0);
}