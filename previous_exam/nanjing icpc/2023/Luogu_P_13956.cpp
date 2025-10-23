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
const int maxn=2e6+100;
const ll INF=1e17;
using namespace std;
int n,m,num;
int q[maxn];
vector<int >e[maxn];
vector<int >edge[maxn];
void slove(){
    for(int i=1;i<=m;i++) {
        e[i].clear();
    }
    for(int i=1;i<=n;i++){
        edge[i].clear();
    }
    cin>>n>>m;
    vector<int>du(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>q[i];
        for(int j=1;j<=q[i];j++){
            cin>>num;
            e[num].push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        int len=e[i].size();
        if(len<=1) continue;
        num=e[i][len-1];
        for(int j=len-2;j>=0;j--){
            edge[e[i][j]].push_back(num);
            du[num]++;
        }
    }
    int flag=0;
    queue<int >q;
    int cnt=0;
    vector<int >ans;
    for(int i=n;i>=1;i--){
        if(!du[i]) {q.push(i);cnt++;ans.push_back(i);}
    }
    if(cnt>=2) flag=1;
    while(!q.empty()){
        num=q.front();
        q.pop();
        int s=0;
        vector<int> t;
        for(auto u:edge[num]){
            du[u]--;
            if(!du[u]){
                cnt++;
                s++;
                q.push(u);
                t.push_back(u); //这里注意细节 原来是12345--n 我们交换扰乱一下
            }
        }
        sort(t.begin(),t.end(),greater<int>());
        for(auto u:t) ans.push_back(u);
        if(s>1) flag=1;
    }
    if(cnt==n && flag) {
        cout<<"Yes"<<"\n";
        for(int i=0;i<n;i++){
            cout<<ans[i];
            if(i!=n-1) cout<<" ";
        }
        cout<<"\n";
    }
    else cout<<"No"<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
		slove();
    }
    return (0-0);
}