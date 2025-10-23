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
const int M=1e5;
using namespace std;
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
int n,m,k,ans;
map<int,int>mp1;
map<int,int>mp2;
void slove(){
    ans=0;
    cin>>n>>m>>k;
    vector<array<int,2> > v;
    //mp1.clear();
    //mp2.clear();
    for(int i=1;i<=k;i++){
        int x,y;cin>>x>>y; // 假设有两个x1 y1 x2 y2 
        //mp1[x]++;
       // mp2[y]++;
        //if(mp1[x]==2) ans++;// 如果x1==x2 不管y都会相加 同时每个点最多只有一次贡献
        //if(mp2[y]==2) ans++; //一样的 如果y1==y2 那么在这个点都会交叉 也是一次 贡献 这里假设不会出现多次x1==y1的情况
        // 记为x1<x2
        // 当且尽让y1>y2的时候有贡献 
        // 等于的情况特殊处理过了
        v.push_back({x,y});//所以我们把第一个当做pos 第二个当做val 即转化为了一个逆序对问题
    }
    sort(v.begin(),v.end(),[](const array<int,2>&x,const array<int,2>&y){
        if(x[1]!=y[1]) return x[1]>y[1];
        else  return x[0]>y[0];
    });//此时是按照val降序排序 可以保证枚举的数 前面的数都是大于自己的 那么有贡献的应该是x比较小的 
    BIT<int>c1;
    for(int i=0;i<=M;i++) c1.c[i]=0ll;
    for(int i=0;i<k;i++){
        //cout<<v[i][0]<<" ";
        ans=ans+c1.get(v[i][0]-1);
        c1.updata(v[i][0],1);
    }
    cout<<ans;
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
		cout<<"Test case "<<i<<": ";
        slove();
        cout<<"\n";
    }
    return (0-0);
}