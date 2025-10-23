// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
const int maxn=3e5;
const int maxm=3e4;
using namespace std;
int t,n,q,l,r,x,m;
int a[maxn],bl[maxn];
vector<int >e[maxm];
int find(int x){return (x-1)/m+1;}
int query(int lef,int rig,int x){
    int s=0x3f3f3f3f-1;
    for(int i=lef;i<=min(rig,bl[lef]*m);i++){
        if(a[i]>=x) s=min(s,a[i]);
    }
    if(bl[lef]!=bl[rig]){
        for(int i=bl[rig]*m-m+1;i<=rig;i++){
            if(a[i]>=x) s=min(s,a[i]);
        }       
    }
    for(int i=bl[lef]+1;i<bl[rig];i++){
        auto pos=lower_bound(e[i].begin(),e[i].end(),x);
        if(pos!=e[i].end()){
            s=min(s,*pos);
        }
    }
    if(s==0x3f3f3f3f-1) return -1;
    else return s;
}
void slove(){
    cin>>n>>q;
    m=sqrt(n)+1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        bl[i]=find(i);
        e[bl[i]].push_back(a[i]);
    }
    for(int i=1;i<=m+1;i++){
        sort(e[i].begin(),e[i].end());
    }
    for(int i=1;i<=q;i++){
        cin>>l>>r>>x;
        //cout<<i<<"\n";
        cout<<query(l,r,x)<<"\n";
    }
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    t=1;
    while(t--){
		slove();
    }
    return 0;
}