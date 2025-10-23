// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=1e6+100;
using namespace std;
int t,n,m;
int a[maxn],b[maxn];
void slove(){
    ll ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    if(m>=2*n-1){ // m够大的时候直接去max
        for(int i=1;i<=n;i++){
            ans=ans+max(a[i],b[i]);
        }
        cout<<ans<<"\n";
        return ;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            ans=ans+a[i];
        }
        cout<<ans<<"\n";
        return ;
    }
    
    cout<<ans<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    //t=1;
    while(t--){
		slove();
    }
    return 0;
}