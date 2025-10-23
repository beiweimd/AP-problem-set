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
const int maxn=1e5;
const ll INF=1e17;
using namespace std;
int n,Q,a[maxn],ans,block,now;
vector<int> freq; // 维护：出现k次的值的“种数”，只统计k>=1
map<int,int>cnt;
struct node{
    int l,r,id;
};
void add(int x){
    int v = a[x];
    int c = cnt[v];          // 当前次数
    if (c > 0) freq[c]--;    // c 从 >=1 变更，旧桶减一
    cnt[v] = c + 1;          // 次数自增
    freq[c + 1]++;           // 新桶加一
    if (now < c + 1) now = c + 1; // 更新最大次数
}

void del(int x){
    int v = a[x];
    int c = cnt[v];          // 当前次数，必>=1
    freq[c]--;               // 旧桶减一
    cnt[v] = c - 1;          // 次数自减
    if (c - 1 > 0) freq[c - 1]++; // 只统计>=1的桶
    while (now > 0 && freq[now] == 0) now--; // 最大次数回退
}
void slove(){
    cin>>Q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cnt.clear();
    now = 1;
    freq.assign(n + 1, 0);
    block=(int)sqrt(n)+1;
    vector<node>q;
    vector<int >an(n+1);
    for(int i=1;i<=Q;i++){
        int ll,rr;
        cin>>ll>>rr;
        q.push_back(node{ll,rr,i});
    }
    sort(q.begin(),q.end(),[](const node &x,const node&y){
        int lef=x.l/block,rig=y.l/block;
        if(lef!=rig) return x.l<y.l;
        else{
            if( (x.l/block )%2 ){
                return x.r<y.r;
            }
            else return x.r>y.r;
        }
    }
    );
    int posl=1,posr=0;
    for(int i=0;i<Q;i++){
        int L=q[i].l,R=q[i].r;
        while(posl<L ) {posl++;del(posl-1);}
        while(posl>L ) {posl--;add(posl);}
        while(posr<R ) {posr++;add(posr);}
        while(posr>R ) {posr--;del(posr+1);}
        //cout<<now<<" "<<q[i].id<<endl;
        an[q[i].id]=now;
        //cout<<posl<<" "<<posr<<"**"<<now<<endl;
    }
    for(int i=1;i<=Q;i++){
        cout<<an[i]<<"\n";
    }
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(1){
        cin>>n;
        if(!n) break;
		slove();
    }
    return (0-0);
}