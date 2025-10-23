// #include <iostream>
// #include<cmath>
// #include<vector>
// #include<map>
// #include<iomanip>
// typedef long long ll;
// typedef long double db;
// const ll mod=1e9+7;
// const int maxn=5e6;
// const db pi=acos(-1);
// const db eps=1e-12;
// using namespace std;
// int t,n,m,ans;
// vector<int >a[maxn];
// int xpos[maxn];
// int ypos[maxn];
// int f[maxn];
// int lef[maxn];
// bool check(int x) {
//     for(int i=0;i<=n;i++) f[i]=0;
//     for(int i=1;i<=n;i++) {
//         lef[i]=m+1;
//     }
//         int dx=xpos[a[1][1]];
//         int dy=ypos[a[1][1]];
//         if(f[dx]<dy){
//             f[dx]=dy;
//         }
//         if(lef[dx]>dy){
//             lef[dx]=dy;
//         }
//          dx=xpos[a[n][m]];
//          dy=ypos[a[n][m]];
//         if(f[dx]<dy){
//             f[dx]=dy;
//         }
//         if(lef[dx]>dy){
//             lef[dx]=dy;
//         }
//     for(int i=0;i<=x;i++){
//          dx=xpos[i];
//          dy=ypos[i];
//         if(f[dx]<dy){
//             f[dx]=dy;
//         }
//         if(lef[dx]>dy){
//             lef[dx]=dy;
//         }
//     }
//     int pre=0;
//     for(int i=1;i<=n;i++){
//         if(f[i]==0) continue;
//         if(lef[i]<f[pre]  ) return false;
//         pre=i;    
//     }
//     return true;
// }
// void slove(){
//     for(int i=1;i<=n;i++){
//         a[i].clear();
//     }
//     cin>>n>>m;
//     for(int i=1;i<=n;i++){
//         a[i].push_back(-1);
//         for(int j=1;j<=m;j++){
//             int num;cin>>num;
//             a[i].push_back(num);
//             xpos[a[i][j]]=i;
//             ypos[a[i][j]]=j;
//         }
//     }
//     if(n==1 or m==1){
//         cout<<n*m<<"\n";
//         return ;
//     }
//     int l=0,r=min(n+m-2,n*m-1);
//     while(l<=r){
//         int mid=(l+r+1)/2;
//         if(check(mid)) l=mid+1;
//         else r=mid-1;
//     }
//     cout<<l<<endl;
//     return ;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin>>t;
//     while(t--){
//         slove();
//     }
//     return 0;
// }
// /*
#include <iostream>
#include<cmath>
#include<vector>
#include<map>
#include<iomanip>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const int maxn=5e6;
const db pi=acos(-1);
const db eps=1e-12;
using namespace std;
int t,n,m,ans;
vector<vector<int > >a;
int xpos[maxn];
int ypos[maxn];
int f[maxn];
int lef[maxn];
bool check(int x) {
	for(int i=0;i<=n;i++) f[i]=0;
	for(int i=1;i<=n;i++) {
		lef[i]=m+1;
	}
		int dx=xpos[a[1][1]];
		int dy=ypos[a[1][1]];
		if(f[dx]<dy){
			f[dx]=dy;
		}
		if(lef[dx]>dy){
			lef[dx]=dy;
		}
		 dx=xpos[a[n][m]];
		 dy=ypos[a[n][m]];
		if(f[dx]<dy){
			f[dx]=dy;
		}
		if(lef[dx]>dy){
			lef[dx]=dy;
		}
	for(int i=0;i<=x;i++){
		 dx=xpos[i];
		 dy=ypos[i];
		if(f[dx]<dy){
			f[dx]=dy;
		}
		if(lef[dx]>dy){
			lef[dx]=dy;
		}
	}
	int pre=0;
	for(int i=1;i<=n;i++){
		if(f[i]==0) continue;
		if(lef[i]<f[pre]  ) return false;
		pre=i;	
	}
	return true;
}
void slove(){
	cin>>n>>m;
	a = vector(n + 10, vector<int>(m + 10));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			xpos[a[i][j]]=i;
			ypos[a[i][j]]=j;
		}
	}
	if(n==1 or m==1){
		cout<<n*m<<"\n";
		return ;
	}
	int l=0,r=min(n+m-2,n*m-1);
	while(l<=r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<l<<endl;
	return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	cin>>t;
    while(t--){
		slove();
    }
    return 0;
}
// #include <bits/stdc++.h>
// typedef long long ll;
// typedef long double db;
// const ll mod=1e9+7;
// const db pi=acos(-1);
// const db eps=1e-12;
// using namespace std;
// int t,n;
// db ans=1e8,rx,ry;
// struct point{
//     db x,y;
// };
// struct cicycle{
//     point info;
//     db r;
// };
// point operator+(const point &a, const point &b) {
//     return {a.x + b.x, a.y + b.y};
// }
// vector<point>p;
// db dis(point a,point b){
//     return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
// }
// db sq(db s){return s*s;}
// cicycle c;
// void sim_anneal(){
//     c.info.x=c.info.y=c.r=0.0;
//     for(auto u:p){
//         c.info+u;
//         c.r=max(c.r,dis(c.info,u));
//     }
//     c.info.x/=n;
//     c.info.y/=n; // 计算初始的位置 是所有点的平均数
//     db delta=20000;
//     while(delta>eps){
//         int id=0;
//         db max_r=0.0;
//         for(int i=0;i<n;i++){
//             if(dis(c.info,p[i])>max_r){
//                 id=i;
//                 max_r=dis(c.info,p[i]);
//             }
//         }
//         c.r=min(c.r,max_r);
//         c.info.x+=(p[id].x-c.info.x)/max_r*delta;
//         c.info.y+=(p[id].y-c.info.y)/max_r*delta;
//         delta*=0.97;
//     }
// }
// void slove(){
// 	cin>>n;
//     for(int i=1;i<=n;i++){
//         db tx,ty;cin>>tx>>ty;
//         p.push_back(point{tx,ty});
//     }
//     sim_anneal();
//     cout<<fixed<<setprecision(10);
//     cout<<sqrt(c.r)<<"\n";
//     cout<<c.info.x<<" "<<c.info.y;
//     return;
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
// }//这个是模拟退火乱搞法
// // // ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// // 最小圆覆盖的n^4做法 十分暴力
// // #include <bits/stdc++.h>
// // typedef long long ll;
// // typedef long double db;
// // const ll mod=1e9+7;
// // const db pi=acos(-1);
// // const db eps=1e-11;
// // using namespace std;
// // int t,n;
// // db ans=1e8,rx,ry;
// // struct point{
// //     db x,y;
// // };
// // vector<point>p;
// // db dis(point a,point b){
// //     return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
// // }
// // db sq(db s){return s*s;}
// // void check(point a,point b,point c){
// //     if( (a.x-b.x)*(a.y-c.y)-(a.x-c.x)*(a.y-b.y)<=eps){ //判断共线的情况
// //         return ;
// //     }
// //     db c1=0.5*( dis(point{0.0,0.0},b)-dis(point{0.0,0.0},a) );
// //     db c2=0.5*( dis(point{0.0,0.0},c)-dis(point{0.0,0.0},a) );
// //     db a1=b.x-a.x;
// //     db a2=c.x-a.x;
// //     db b1=b.y-a.y;
// //     db b2=c.y-a.y;
// //     db tx=(b2*c1-b1*c2)/(b2*a1-b1*a2);
// //     db ty=(a2*c1-a1*c2)/(a2*b1-a1*b2);
// //     db t_d=dis(point{tx,ty},a);
// //     for(int i=0;i<n;i++){
// //         if(dis(p[i],{tx,ty})>t_d) return ;
// //     }
// //     if(t_d<ans ){
// //         ans=t_d;
// //         rx=tx;ry=ty;
// //     }
// //     return ;
// // }
// // void slove(){
// // 	cin>>n;
// //     for(int i=1;i<=n;i++){
// //         db tx,ty;cin>>tx>>ty;
// //         p.push_back(point{tx,ty});
// //     }
// //     for(int i=0;i<n;i++){
// //         for(int j=0;j<n;j++){
// //             for(int k=0;k<n;k++)check(p[i],p[j],p[k]);
// //         }
// //     }
// //     cout<<fixed<<setprecision(10);
// //     cout<<(db)sqrt(ans)<<"\n";
// //     cout<<rx<<" "<<ry;
// //     return;
// // }
// // int main(){
// //     ios::sync_with_stdio(0);
// //     cin.tie(0);
// //     cout.tie(0);
// //     t=1;
// //     while(t--){
// // 		slove();
// //     }
// //     return 0;
// // }
