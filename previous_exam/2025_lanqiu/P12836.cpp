// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n;
ll a[maxn],ans,b[maxn];
ll check(ll x ){
    ll s=0;  
    while(x!=0){
        s++;
        x/=2;
    }
    return s;
}
void slove(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=check(a[i]+1);
    }
    ll pre=0;
    for(int i=2;i<=n;i++){
        ll num=pre+b[i-1];
        if(b[i]<num){
            ll cnt=pre+b[i-1]-b[i]+1;
            if(b[i]>b[i-1]) cnt--;
            pre=cnt;
            ans=ans+cnt;
        }
        //cout<<b[i]<<" "<<pre<<endl;
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