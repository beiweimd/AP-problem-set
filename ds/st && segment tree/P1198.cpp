// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
ll mod,num,tag,a[maxn],pre;
ll st[maxn][30];
int n; // st表写法
ll query(ll x){
    ll s=-1e14;
    ll len=n;
    for(int j=20;j>=0;j--){
        if((x&(1<<j))!=0 ){
            //cout<<x<<" "<<j<<endl;
            s=max(s,st[len][j]);
            len=len-(1<<j);
        }
    }
    return s;
}
void slove(){
    char s;cin>>s>>num;
    if(s=='A'){
        n++;
        num=num+pre; num%=mod;
        st[n][0]=num;
        for(int j=1;(1<<j)<=n;j++){
            st[n][j]=max(st[n][j-1],st[n-(1<<(j-1))][j-1]);
        }
    }
    else{
        pre=query(num);
        cout<<pre<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // for(int i=1;i<=2e5+1;i++){
    //     belong[i]=(i-1)/len+1; // 分块代码
    // }
    cin>>t>>mod;
    while(t--){
		slove();
    }
    return (0-0);
}
/* 这是单调栈+二分写法
ll mod,num,tag,a[maxn];
int  sk[maxn],top,n;
int belong[maxn],len=500; //分块 每个元素属于哪一块
void slove(){
    char s;cin>>s>>num;
    if(s=='A'){
        num+=tag;
        num%=mod;
        n++;
        a[n]=num;
        //cout<<num<<endl;
        while(top!=0 && num>=a[sk[top]] ) top--;
        top++;
        sk[top]=n;
    }
    else{
        num=n-num+1;
        //cout<<num<<" "<<top<<endl;
        int k=lower_bound(sk+1,sk+1+top,num)-sk;
        tag=a[sk[k]];
        cout<<tag<<endl;
    }
}
*/
// 下面这一坨 是分块的写法
// ll mod,num,tag,n; // tag是最后一次查询的答案
// int belong[maxn],len=500; //分块 每个元素属于哪一块
// ll a[maxn],block[maxn]; //分别记录所有数和 每个块的最大数
// void insert(ll x){
//     x=(x+tag)%mod;
//     n++;
//     a[n]=x;
//     block[belong[n]]=max(block[belong[n]],x);
// }
// ll query(ll x){
//     ll  lef=belong[x];
//     ll rig=belong[n];
//     ll s=-1e14;
//     if(lef==rig){
//         for(int i=x;i<=n;i++) s=max(s,a[i]);
//         return s;
//     }
//     for(int i=x;i<=min(n*1ll,(lef*len));i++) s=max(s,a[i]);
//     for(int i=rig*len-len+1;i<=n;i++) s=max(s,a[i]);
//     for(int i=lef+1;i<rig;i++) s=max(s,block[i]);
//     return s;
// }
// void slove(){
// 	char s;cin>>s>>num;
//     if(s=='A') insert(num);
//     else {
//         tag=query(n-num+1);
//         cout<<tag<<"\n";
//     }
//     return;
// }