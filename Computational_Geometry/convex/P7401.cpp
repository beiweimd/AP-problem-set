// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e6;
using namespace std;
int t,n,ans,top;
db h;
struct point {
    db x,y;
};
point a[maxn];
db lef[maxn];
db rig[maxn];
db findk(point d,point e){
    return (d.y-e.y)/(d.x-e.x);
}
int st[maxn];
void init(){
    st[top=1]=1;
    for(int i=2;i<=n;i++){
        while(top>1 && findk(a[st[top]],a[st[top-1]])<findk(a[i],a[st[top]] )) top--;
        if(i%2==1) lef[i]=a[st[top] ].x-(a[i].x-a[st[top]].x )/(a[st[top]].y-a[i].y)*(h-a[st[top]].y);
        st[++top]=i;
    }
    st[top=1]=n;
    for(int i=n-1;i>=1;i--){
        while(top>1 && findk(a[st[top-1]],a[st[top]])>findk(a[st[top] ],a[i] )) top--;
        if(i%2==1) rig[i]=a[st[top] ].x+(-a[i].x+a[st[top]].x )/(a[st[top]].y-a[i].y)*(h-a[st[top]].y);
        st[++top]=i;
    }
    return ;
}
void slove(){
    cin>>n>>h;for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    if(n==3) {
        cout<<0;return ;
    }
    vector<array<db,2>  >  p;
    init();//处理凸包 求出每个山谷的左右区间
    for(int i=3;i<n;i+=2){
        p.push_back({lef[i],rig[i]});
    }
    sort(p.begin(),p.end(),[](const array<db,2>&c,const array<db,2>&b){
        if(fabs(c[1]-b[1])>eps ) return c[1]<b[1];
        else return c[0]>b[0];
    }
    );
    db pre=-1e18;
    for(auto u:p){
        if(pre<u[0]){
            pre=u[1];ans++;
        }
    }
    cout<<ans;
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
    return (0-0);
}
// // ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// #include <bits/stdc++.h>
// typedef long long ll;
// typedef long double db;
// const ll mod=1e9+7;
// const db pi=acos(-1);
// const db eps=1e-6;
// const int maxn=2e6;
// using namespace std;
// int t,n,ans;
// db h;
// struct point {
//     db x,y;
// };
// point a[maxn];
// void slove(){
//     cin>>n>>h;for(int i=1;i<=n;i++){
//         cin>>a[i].x>>a[i].y;
//     }
//     vector<array<db,2>  >  p ;
//     for(int i=3;i<n;i+=2){
//         db rig=a[i].x+(h-a[i].y)/(a[i+1].y-a[i].y)*(a[i+1].x-a[i].x);
//         db lef=a[i].x-(h-a[i].y)/(a[i-1].y-a[i].y)*(a[i].x-a[i-1].x);
//         p.push_back({lef,rig} );
//         //cout<<lef<<" "<<rig<<endl;
//     }
//     sort(p.begin(),p.end(),[](const array<db,2>&c,const array<db,2>&b){
//         if(fabs(c[1]-b[1])>eps ) return c[1]<b[1];
//         else return c[0]>b[0];
//     }
//     );
//     db pre=-1e18;
//     for(auto u:p){
//         if(pre<u[0]){
//             pre=u[1];ans++;
//         }
//     }
//     cout<<ans;
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