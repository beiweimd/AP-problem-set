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
int n,k; 
int num;
char op;
int target=2e9;
vector<int >a;
priority_queue<int >q1; // 默认的是大根堆 及大的在前面 所以这里存放的是小于a[k]的元素
priority_queue<int,vector<int>,greater<int> >q2; //这里是小跟堆 小的在前面 我们只要放置比a[k]大的就行了
void slove(){
    target=2e9;
    while(!q1.empty())q1.pop();
    while(!q2.empty())q2.pop();
    for(int i=1;i<=k;i++){
        cin>>op;
        cin>>num;
        target=min(num,target);
        q2.push(num);
    }
    q2.pop();
    n-=k;
    while(n--){
        cin>>op;
        if(op=='Q'){
            cout<<target<<"\n";continue ;
        }
        cin>>num;
        if(num<target){
            q1.push(num);
        }
        else{
            q1.push(target);
            q2.push(num);
            target=q2.top();
            q2.pop();
        }
    }
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(cin>>n>>k){
        slove();
    }
    return (0-0);
}