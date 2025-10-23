// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
ll p,k;
bool check(ll x){
    ll s=0;
    ll num=0;
    while(x>0){
        s+=x;
        num+=x;
        x=num/p;
        num%=p;
    }
    if(s<k) return true;
    else return false;
}
void slove(){
	cin>>p>>k;
    if(k==0){
        cout<<0<<"\n";return ;
    }
    if(p==1){
        cout<<1<<"\n";return ;
    }
    if(p>=k) {cout<<k<<"\n";return ;}
    ll l=1,r=k;
    while(l<=r){
        ll mid=(l+r+1)/2;
        if(check(mid) ) l=mid+1; // 不合法 需要增大范围
        else r=mid-1;
    }
    cout<<l<<"\n";
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