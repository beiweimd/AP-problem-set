#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e5+100;
const ll INF=1e17;
using namespace std;
int n,op,l,r,m;
int belong[maxn];
ll c;
ll tag[maxn];
ll val[maxn];
vector<ll> block[maxn];
int bt(int x){return 1+(x-1)/m;}
void updata(){
    int lef=belong[l];
    int rig=belong[r];
    if(lef==rig){
        for(int i=l;i<=r;i++) val[i]+=c;
        block[lef].clear();
        for(int i=lef*m-m+1;i<=min(lef*m,n);i++){
            block[lef].push_back(val[i]);
        }
        sort(block[lef].begin(),block[lef].end());
        return ;
    }
    for(int i=l;i<=lef*m;i++) val[i]+=c;
    for(int i=rig*m-m+1;i<=r;i++) val[i]+=c;
    block[lef].clear(); block[rig].clear();
    for(int i=lef*m-m+1;i<=lef*m;i++) block[lef].push_back(val[i]);
    for(int i=rig*m-m+1;i<=min(n,rig*m);i++)      block[rig].push_back(val[i]);
    sort(block[rig].begin(),block[rig].end());
    sort(block[lef].begin(),block[lef].end());
    for(int i=lef+1;i<rig;i++) tag[i]+=c;
    return ;
}
int query(){
    int s=0;
    int lef=belong[l];
    int rig=belong[r];
    if(lef==rig){
        for(int i=l;i<=r;i++) {
            if(val[i]+tag[lef]<c*c) s++;
        }
        return s;
    }
    for(int i=l;i<=lef*m;i++) {
        if(val[i]+tag[lef]<c*c) s++;
    }
    for(int i=rig*m-m+1;i<=r;i++) {
        if(val[i]+tag[rig]<c*c) s++;
    }
    for(int i=lef+1;i<rig;i++){
        auto pos=lower_bound(block[i].begin(),block[i].end(),c*c-tag[i]);
        s=s+pos-block[i].begin();
    }
    return s;
}
void slove(){
    cin>>n;
    m=max(10,(int)sqrt(n));
    for(int i=1;i<=n;i++){
        cin>>val[i];
        belong[i]=bt(i);
        block[belong[i]].push_back(val[i]);
    }
    for(int i=1;i<=n;i+=m){
        sort(block[belong[i]].begin(),block[belong[i]].end());
    }
    for(int i=1;i<=n;i++){
        cin>>op>>l>>r>>c;
        if(op==1) {
            cout<<query()<<"\n";
        }
        else {
            updata();
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
    while(t--){
		slove();
    }
    return (0-0);
}