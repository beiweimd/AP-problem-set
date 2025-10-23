#include<queue>
#include<iostream>
#include<cmath>
#include<stack>
#include<iomanip>
typedef unsigned long long ll;
const int maxn=1e6+100;
const ll mod=1e9+7;
const double eps=1e-6;
using namespace std;
double  n;
double f[maxn];
// 已经有了i张彩票 再买剩下n-i张彩票的期望次数
double g[maxn];
// 已经买了i张 把剩下的买完需要的期望花费
void slove(){
    cin>>n;
    // 这里还是选择倒推 因为倒推才能保证整体事件的概率是1
	// 正推是有一些结果没有到我们最终要的状态的 需要额外记录概率 比较复杂
    for(int i=n-1;i>=0;i--){
		f[i]=f[i+1]+n/(n-i);
		g[i]=i/(n-i)*f[i]+f[i+1]+g[i+1]+n/(n-i);
	}
	/*
	$$
	g_i = \frac{n-i}{n} \, (g_{i+1} + f_{i+1} + 1) \;+\; \frac{i}{n} \, (g_i + f_i + 1)
	$$  这里转移就是还是有i/n的概率获得不了新的彩票
	*/  //然后价格变动可以这么理解 :是把买这张的成本看成1块 后续所有的票都贵上一块,那么每一步都加上fi 就相当于依次贵了1-i-1块 
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	slove();
	cout<<fixed<<setprecision(2)<<g[0];
    return 0;
}
// #include<bits/stdc++.h>
// typedef long double db;
// const  int maxn=1e6;
// using namespace std;
// int n;
// long double ans=0;
// long long int suf[maxn];
// db qmod(db a,int b){
//     db s=1.0;
//     while(b){
//         if(b&1) s=s*a;
//         a=a*a;
//         b>>=1;
//     }
//     return s;
// }
// long long int pre=1;
// db p[3][maxn];
// int main(){
//     cin>>n;
//     if(n==1){cout<<1.00;return 0;}
//     db pb=1.0/n;
//     p[0][1]=1;
//     pre=1;
//     for(int i=2;i<=n*5;i++){
//         pre+=i;
//         for(int j=1;j<=min(n,i);j++){
//             if(j==n) p[1][j]=p[0][j-1]*pb*(n-j+1);
//             else p[1][j]=p[0][j]*pb*j+p[0][j-1]*pb*(n-j+1);
//             if(j>=n) ans=ans+pre*p[1][j];
//             //cout<<i<<" "<<j<<" "<<p[1][j]<<endl;
//         }
//         for(int j=1;j<=min(i,n);j++){
//             p[0][j]=p[1][j];
//         }
//     }
//     cout<<fixed<<setprecision(2)<<ans;
//     return 0;
// }