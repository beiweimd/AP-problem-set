#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5+100;
const ll INF=1e17;
using namespace std;
int n,op,l,r,m;
int belong[maxn];
ll c;
ll tag[maxn];
ll val[maxn];
ll block[maxn];
int bt(int x){return 1+(x-1)/m;}
void updata(){
    int lef=belong[l];
    int rig=belong[r];
    if(lef==rig){
        for(int i=l;i<=r;i++) val[i]+=c,block[lef]+=c;
        return ;
    }
    for(int i=l;i<=lef*m;i++) val[i]+=c,block[lef]+=c;
    for(int i=rig*m-m+1;i<=r;i++) val[i]+=c,block[rig]+=c;
    for(int i=lef+1;i<rig;i++) tag[i]+=c;
    return ;
}
long long int query(){
    long long s = 0;
    int lef=belong[l];
    int rig=belong[r];
    if(lef==rig){
        for(int i=l;i<=r;i++) {
            s+=val[i]+tag[lef];
        }
        return s;
    }
    for(int i=l;i<=lef*m;i++) {
        s+=val[i]+tag[lef];
    }
    for(int i=rig*m-m+1;i<=r;i++) {
        s+=val[i]+tag[rig];
    }
    for(int i=lef+1;i<rig;i++){
        s+=block[i]+tag[i]*m;
    }
    return s;
}
void slove(){
    cin>>n;
    m=max(10,(int)sqrt(n));
    for(int i=1;i<=n;i++){
        cin>>val[i];
        belong[i]=bt(i);
        block[belong[i]]+=val[i];
    }
    for(int i=1;i<=n;i++){
        cin>>op>>l>>r>>c;
        if(op==1) {
            long long sum = query();
            long long modv = c + 1;
            long long ans = ((sum % modv) + modv) % modv; // 保证非负
            cout << ans << "\n";
        } else {
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