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
const int maxn=3e5+100;
const ll INF=1e17;
using namespace std;
int n,op,l,r,m;
int belong[maxn];
ll c;
ll tag[maxn];
ll val[maxn];
int bt(int x){return 1+(x-1)/m;}
void updata(){
    int lef=belong[l];
    int rig=belong[r];
    if(lef==rig){
        for(int i=l;i<=r;i++) val[i]+=c;
        return ;
    }
    for(int i=l;i<=lef*m;i++) val[i]+=c;
    for(int i=rig*m-m+1;i<=r;i++) val[i]+=c;
    for(int i=lef+1;i<rig;i++) tag[i]+=c;
}
void slove(){
    cin>>n;
    m=max(10,(int)sqrt(n));
    //cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        belong[i]=bt(i);
    }
    for(int i=1;i<=n;i++){
        cin>>op>>l>>r>>c;
        if(op==1) {cout<<val[r]+tag[belong[r]]<<"\n";}
        else {updata();}
    }
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