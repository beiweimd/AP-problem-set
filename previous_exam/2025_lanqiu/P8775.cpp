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
int n,x,h[maxn];
ll qz[maxn];
bool check(int len){
    for(int i=1;i+len-1<n;i++){
        if(qz[i+len-1]-qz[i-1]<2*x)  return false;
    }
    return true;
}
void slove(){
    cin>>n>>x;
    for(int i=1;i<n;i++){
        cin>>h[i];
        qz[i]=qz[i-1]+h[i];
    }
    int l=1,r=n+1;
    while(l<=r){
        int mid=(l+r+1)/2;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<<l;
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