#include <bits/stdc++.h>
typedef long long ll;
const int maxn=1e5+100;
using namespace std;
ll qz[maxn];
ll a[maxn];
ll pre_mod[maxn];
int n,k;
void slove(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        qz[i]=qz[i-1]+a[i];
        pre_mod[qz[i]%k]++;
    }
    ll ans=0;
    for(int i=0;i<k;i++){
        if(pre_mod[i])ans=ans+(ll)(pre_mod[i]*(pre_mod[i]-1) )/2;
    }
    cout<<ans+pre_mod[0];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    slove();
    return 0;
}