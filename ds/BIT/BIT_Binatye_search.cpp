// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
const ll mod=1e9+7;
using namespace std;
int t,n,m,q;
ll a1[550][550];
ll c[550][550];
int lowbit(int p) {return p&(-p);}
void modify(int x,int y,ll d){
    for(int a=x;a<=n;a+=lowbit(a)){
        for(int b=y;b<=m;b+=lowbit(b)){
            c[a][b]+=d;
        }
    }
    return ;
}
ll query(int x, int y){
    ll s=0;
    for(int a=x;a>0;a-=lowbit(a)){
        for(int b=y;b>0;b-=lowbit(b)){
            s+=c[a][b];
        }
    }
    return s;
}
void slove(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a1[i][j];
            modify(i,j,a1[i][j]);
        }
    }
    for(int i=1;i<=q;i++){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            ll d;cin>>d;
            modify(x,y,d-a1[x][y]);
            a1[x][y]=d;
        }
        else cout<<query(x,y)<<"\n";
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
// // ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// #include <bits/stdc++.h>
// // BIT二分 求前缀第k大 本质是倍增
// typedef long long ll;
// typedef double db;
// const ll mod=1e9+7;
// const int maxn=4e5;
// using namespace std;
// int t,n,q;
// ll c[maxn];
// ll a[maxn];
// int lowbit(int p) {return p&(-p);}
// void modify(int x,ll d){
//     for(;x<=n;x+=lowbit(x))c[x]+=d;
//     return ;
// }
// int query(ll x){
//     ll s=0;
//     int pos=0;
//     for(int j=18;j>=0;j--){
//         if(pos+(1<<j)<=n && s+c[pos+(1<<j)]<=x){
//             s+=c[pos+(1<<j)];
//             pos=pos+(1<<j);
//         }
//     }
//     return pos;
// }
// void slove(){
//     cin>>n>>q;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//         modify(i,a[i]);
//     }
//     for(int i=1;i<=q;i++){
//         int op;cin>>op;
//         if(op==2){
//             ll s;cin>>s;
//             cout<<query(s)<<"\n";
//         }
//         else{
//             int x; ll d;cin>>x>>d;
//             modify(x,d-a[x]);
//             a[x]=d;
//         }
//     }
// 	return;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     t=1;
//     while(t--){
// 		slove();
//     }
//     return 0;
// }