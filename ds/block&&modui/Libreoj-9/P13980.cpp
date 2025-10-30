#include <bits/stdc++.h>
typedef long long ll;
const int maxn=3e5+100;
using namespace std;
int n,m,op,l,r;
ll val[maxn];
int cnt[maxn];
int belong[maxn];
ll sum[maxn];
int cnt_zero[maxn];
int bt(int x) {return (x-1)/m+1;}
void d(int pos){
    val[pos]=floor(sqrt(val[pos]));
    return ;
}
void updata(){
    int lef=belong[l];
    int rig=belong[r];
    if(lef==rig){
        for(int i=l;i<=r;i++){
            sum[lef]-=val[i];
            d(i);
            sum[lef]+=val[i];
        }
        return ;
    }
    for(int i=l;i<=lef*m;i++) {
            sum[lef]-=val[i];
            d(i);
            sum[lef]+=val[i];        
    }
    for(int i=rig*m-m+1;i<=r;i++) {
            sum[rig]-=val[i];
            d(i);
            sum[rig]+=val[i];        
    }
    for(int i=lef+1;i<rig;i++) {
        if(cnt[i]>=6) continue;
        cnt[i]++;
        for(int j=i*m-m+1;j<=i*m;j++){
            if(val[j]==0) continue;
            sum[i]-=val[j];
            d(j);
            sum[i]+=val[j];
        }
    }
    return ;
}
ll query(){
    ll s=0;
    int lef=belong[l];
    int rig=belong[r];
    if(lef==rig){
        for(int i=l;i<=r;i++) {
            s+=val[i];
        }
        return s;
    }
    for(int i=l;i<=lef*m;i++) {
        s+=val[i];
    }
    for(int i=rig*m-m+1;i<=r;i++) {
        s+=val[i];
    }
    for(int i=lef+1;i<rig;i++){
        s+=sum[i];
    }
    return s;
}
int main() {
	// your code goes here
    cin>>n;
    m=max(10,(int)sqrt(n));
    for(int i=1;i<=n;i++){
        cin>>val[i];
        belong[i]=bt(i);
        sum[belong[i]]+=val[i];
    }
    for(int i=1;i<=n;i++){
        cin>>op>>l>>r;
        if(op==1) {
            cout<<query()<<"\n";
        }
        else updata();
    }
    return 0;
}
