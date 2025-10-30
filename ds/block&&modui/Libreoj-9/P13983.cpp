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
ll val[maxn];
ll tag[maxn];
int bt(int x){return 1+(x-1)/m;}
void updata(){
    int lef=belong[l];
    int rig=belong[r];
    if(lef==rig){
        if(tag[lef]!=INF){
            for(int i=lef*m-m+1;i<=min(n,lef*m);i++) val[i]=tag[lef];
        } 
        for(int i=l;i<=r;i++) {
            val[i]=c;
        }
        tag[lef]=INF;
        return ;
    }
    if(tag[lef]!=INF) for(int i=lef*m-m+1;i<=lef*m;i++) val[i]=tag[lef];
    if(tag[rig]!=INF) for(int i=rig*m-m+1;i<=min(n,rig*m);i++) val[i]=tag[rig];
    for(int i=l;i<=lef*m;i++ ) val[i]=c;
    for(int i=rig*m-m+1;i<=r;i++)  val[i]=c;
    tag[lef]=INF;
    tag[rig]=INF;
    for(int i=lef+1;i<rig;i++) tag[i]=c;
    return ;
}
long long int query(){
    long long s = 0;
    int lef=belong[l];
    int rig=belong[r];
    if(lef==rig){
        for(int i=l;i<=r;i++) {
            if((val[i]==c && tag[belong[i]]==INF) or (tag[belong[i]]==c) ) s++;
        }
        return s;
    }
    for(int i=l;i<=lef*m;i++ ) if((val[i]==c && tag[belong[i]]==INF) or (tag[belong[i]]==c) ) s++;
    for(int i=rig*m-m+1;i<=r;i++) if((val[i]==c && tag[belong[i]]==INF) or (tag[belong[i]]==c) ) s++;
    for(int i=lef+1;i<rig;i++){
        if(tag[i]==INF){
            for(int j=i*m-m+1;j<=i*m;j++){
                if(val[j]==c) s++;
            }
        }
        else{
            if(tag[i]==c) s+=m;
        }
    }
    return s;
}
void slove(){
    cin>>n;
    m=max(10,(int)sqrt(n));
    for(int i=1;i<=n;i++){
        cin>>val[i];
        belong[i]=bt(i);
        tag[belong[i]]=INF;
    }
    for(int i=1;i<=n;i++){
        cin>>l>>r>>c;
        cout<<query()<<"\n";
        updata();
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