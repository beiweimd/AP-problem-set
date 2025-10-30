#include <bits/stdc++.h>
typedef long long ll;
const ll mod=10007;
const int maxn=3e5+100;
using namespace std;
int n,m,op,l,r,c,p;
ll val[maxn];
int belong[maxn];
int bt(int x) {return (x-1)/m+1;}
ll tag_add[maxn],tag_mul[maxn];
// 对整块维护一个y=kx+b的操作 
//散块的时候我们直接对整个块进行kx+b的操作得到数值 
void updata_add(){
    int lef=belong[l];
    int rig=belong[r];
    if(lef==rig){
        for(int i=lef*m-m+1;i<=min(lef*m,n);i++){
            val[i]=val[i]*tag_mul[lef];
            val[i]%=mod;
            val[i]=val[i]+tag_add[lef];
            val[i]%=mod;
        }
        for(int i=l;i<=r;i++){
            val[i]+=c;
            val[i]%=mod;
        }
        tag_add[lef]=0;
        tag_mul[lef]=1;
        return ;
    }
    for(int i=lef*m-m+1;i<=min(lef*m,n);i++){
            val[i]=val[i]*tag_mul[lef];
            val[i]%=mod;
            val[i]=val[i]+tag_add[lef];
            val[i]%=mod;
    }
    for(int i=rig*m-m+1;i<=min(rig*m,n);i++){
            val[i]=val[i]*tag_mul[rig];
            val[i]%=mod;
            val[i]=val[i]+tag_add[rig];
            val[i]%=mod;
    }
    tag_add[lef]=0;
    tag_mul[lef]=1;
    tag_add[rig]=0;
    tag_mul[rig]=1;
    for(int i=l;i<=lef*m;i++) val[i]+=c,val[i]%=mod;
    for(int i=rig*m-m+1;i<=r;i++) val[i]+=c,val[i]%=mod;
    for(int i=lef+1;i<rig;i++) tag_add[i]=(tag_add[i]+c)%mod;
}
void updata_mul(){
    int lef=belong[l];
    int rig=belong[r];
    if(lef==rig){
        for(int i=lef*m-m+1;i<=min(lef*m,n);i++){
            val[i]=val[i]*tag_mul[lef];
            val[i]%=mod;
            val[i]=val[i]+tag_add[lef];
            val[i]%=mod;
        }
        for(int i=l;i<=r;i++){
            val[i]*=c;
            val[i]%=mod;
        }
        tag_add[lef]=0;
        tag_mul[lef]=1;
        return ;
    }
    for(int i=lef*m-m+1;i<=min(lef*m,n);i++){
            val[i]=val[i]*tag_mul[lef];
            val[i]%=mod;
            val[i]=val[i]+tag_add[lef];
            val[i]%=mod;
    }
    for(int i=rig*m-m+1;i<=min(rig*m,n);i++){
            val[i]=val[i]*tag_mul[rig];
            val[i]%=mod;
            val[i]=val[i]+tag_add[rig];
            val[i]%=mod;
    }
    tag_add[lef]=0;
    tag_mul[lef]=1;
    tag_add[rig]=0;
    tag_mul[rig]=1;
    for(int i=l;i<=lef*m;i++) val[i]*=c,val[i]%=mod;
    for(int i=rig*m-m+1;i<=r;i++) val[i]*=c,val[i]%=mod;
    for(int i=lef+1;i<rig;i++){
        tag_add[i] = (tag_add[i] * c) % mod;
        tag_mul[i]=(c*tag_mul[i])%mod;
    }
    return ;
}
ll query(){
    return (((val[r]*tag_mul[belong[r]])%mod)+tag_add[belong[r]])%mod;
}
int main() {
    cin>>n;
    m=max(10,(int)sqrt(n));
    for(int i=1;i<=n;i++){
        cin>>val[i];
        val[i] %= mod;
        if(val[i] < 0) val[i] += mod;
        belong[i]=bt(i);
        tag_mul[i]=1ll;
    }
    for(int i=1;i<=n;i++){
        cin>>op>>l>>r>>c;op++;
        c%=mod;
        if(c<0) c+=mod;
        if(op==1){
            updata_add();
        }
        if(op==2){
            updata_mul();
        }
        if(op==3){
            cout<<((query()%mod)+mod)%mod<<"\n";
        }
    }
    return 0;
}
