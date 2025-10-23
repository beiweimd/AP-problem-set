// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
/*
拓展域并查集（也叫“扩展域 DSU”）= 用“复制元素的多个状态位”把多种关系转为普通并查集的合并与冲突判断。适合“同/敌”“三分类”“模 k 等价”等离散状态约束；时间复杂度近乎 O(α(N))。
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n,k; //在罪犯里面 我们开了一个双倍的并查集 其实代表的是i自己关押在哪里 以及i的敌人关押在哪里 矛盾即i的敌人是自己 
// 这里我们需要考虑三种情况 即 同类 吃和被吃
int f[maxn],ans;
// f[1-n]代表i的同类 f[2n]代表i吃谁 f[3n]代表i被谁吃
int getf(int v){
    if(f[v]==v)
        return v;    
    else {
        f[v]=getf(f[v]);
        return f[v];
    }
} 
void merge(int v,int u){
    int t1,t2;
    t1=getf(v);
    t2=getf(u);
    if(t1!=t2){
        f[t2]=f[t1];    //这里要让两人的祖先相同，合并祖先。
    }
    return ;
}
void slove(){
  int op,X,Y;
  cin>>n>>k;
  for(int i=1;i<=n*3;i++) f[i]=i;
  while(k--){
    cin>>op>>X>>Y;
    if (X < 1 || X > n || Y < 1 || Y > n || (op == 2 && X == Y)) { ans++; continue; }
    if(op==2){
       if (getf(X)==getf(Y) || getf(X)==getf(Y+n)) { ans++; continue; }
      merge(X,Y+2*n);
      merge(X+n,Y);
      merge(X+2*n,Y+n);
    }
    else{ // 如果是同类别
      if( getf(X)==getf(Y+n) or  getf(X)==getf(2*n+Y)) {ans++;continue;}
      merge(X,Y);
      merge(X+n,Y+n);
      merge(X+2*n,Y+2*n);
    }
  }
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