// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
using namespace std;
const int maxn=5e6;
int t,n,k,x,idx=1,m,b,c;
int tire[maxn][3];
int a[maxn];
int flag[maxn];
int siz[maxn]; //代表经过i这个点的次数 
void insert(int p,int x){
    for(int i=29;i>=0;i--){
        int w=(x>>i)& 1;
        if(tire[p][w]==0){
            idx++;
            tire[p][w]=idx;
        }
        p=tire[p][w];
        siz[p]++;
    }
}
int query(int p,int x){
    int res=0;
    for(int i=29;i>=0;i--){
        int w=(x>>i)&1;
        if(siz[tire[p][w]]>=k){
            p=tire[p][w];
        }
        else {
            k=k-siz[tire[p][w]];
            p=tire[p][w^1];
            res=res^(1<<i);
        }
    }
    return res;
}
void slove(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        insert(1,a[i]);
    }
    for(int i=1;i<=m;i++){
        cin>>x>>k;
        cout<<query(1,x)<<"\n";
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