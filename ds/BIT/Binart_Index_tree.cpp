// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inversion pair 逆序对
// Binary Index Tree // BIT 树状数组英文
#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const ll mod=1e9+7;
const int maxn=2e5;
using namespace std;
int t,n,q,op;
ull c[maxn];
int lowbit(int p) {return p&(-p);}
template<class T>
struct BIT{
    T c[maxn];
    void modify(int x,ull d){
        for(;x<=n;x+=lowbit(x))c[x]+=d;
        return ;
    }
    ull query(int x){
        ull s=0;
        for(;x!=0;x-=lowbit(x)) s+=c[x];
        return s;
    }
};
BIT<ull>c1,c2;  // c1是单纯得差分数组 c2 是 i*di得差分数组 
void slove(){
    cin>>n>>q;
    for(int i=1;i<=q;i++){
        cin>>op;
        if(op==1){
            int l,r; ull d;cin>>l>>r>>d;
            c1.modify(l,d);
            c1.modify(r+1,-d);
            c2.modify(l,l*d);   
            c2.modify(r+1,(r+1)*(-d));
        }
        else {
            int x;cin>>x;
            cout<<(x+1)*c1.query(x)-c2.query(x)<<"\n";
        }
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
// ll query(int x){
//     ll s=0;
//     for(;x!=0;x-=lowbit(x)) s+=c[x];
//     return s;
// }
// void slove(){
//     cin>>n>>q;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//         modify(i,a[i]);
//     }
//     for(int i=1;i<=q;i++){
//         int op,x;ll d;cin>>op>>x;
//         if(op==1){
//             cin>>d; modify(x,d-a[x]);
//             a[x]=d;
//         }
//         else cout<<query(x)<<"\n";
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