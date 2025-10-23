#include <iostream>
#include<cmath>
#include<vector>
#include<map>
#include<iomanip>
#include<stack>
typedef long long ll;
typedef long double db;
const ll mod=998244353;
const int maxn=1e6;
const db pi=acos(-1);
const db eps=1e-12;
const ll inf=1e18;
using namespace std;
int a[maxn];
int vis[maxn];
void slove(){
	ll ans=1;
    int flag=0,pre=0;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[i]=0;
        if(a[i]==1) flag=1;
    }
    vis[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]) flag=0;
        if(i>(n-a[i]+1)) flag=0;
		if(a[i]<a[i-1]) {
        	vis[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
    	if(vis[i]==1) {
    		pre++;
    		continue;
    	}
		ans=ans*(n-a[i]-pre+1 );
		pre++; // 细节点 
		ans%=mod;
    }
    if(flag==0) cout<<0<<"\n";
    else cout<<(mod+ans)%mod <<"\n";
    return ;
}
/*
hack 数据
6
6 4 4 1 1 1 
6 4 * 1 * * 
这里第一个星号 只能填写5 就是填写的数不能太小  
*/ 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	int t;cin>>t;
    while(t--) slove();
    return 0;
}