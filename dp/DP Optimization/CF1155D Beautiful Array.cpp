// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
//v.insert(v.begin() + pos, x);
//插入x到当做pos下标
//*(pos--) 错误写法 是先引用在减
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5+10;
const ll INF=1e17;
using namespace std;
ll ans,val[maxn],x;
ll f0[maxn],f1[maxn],f2[maxn];
int n;
void slove(){
	cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        f0[i]=max(0ll,f0[i-1])+val[i]; // f0代表的是最大字段和 即没有乘操作的字段和
    }
    f1[0] = -INF;
    f2[0] = -INF;
    for(int i=1;i<=n;i++){
        f1[i]=max({0ll,f1[i-1],f0[i-1]})+x*val[i];
        //这里的f1[i]代表的是val[i]经历了乘法并且还以他结尾的最大字段和，那显然val[i]需要被乘 我们能选择的只有什么都不接在前面0
        //以及前面的都没有乘法 和前面的也乘了的最大数值
    }
    for(int i=1;i<=n;i++){
        f2[i]=max({0ll,f1[i-1],f2[i-1]})+val[i];
        //这里的f2[i]指的是val[i]结尾并且前面已经乘了一个的情况
    }
    for(int i=1;i<=n;i++) ans=max(ans,max({f0[i],f1[i],f2[i]}));
    cout<<ans;
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