#include <bits/stdc++.h>
#define int long long
#define eps 0.00000001
using namespace std;

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
};
Point stk[100005];
typedef Point Vector;

Vector operator + (Vector A, Vector B) {return Vector(A.x+B.x,A.y+B.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x,A.y-B.y);}
Vector operator * (Vector A, double B) {return Vector(A.x*B,A.y*B);}
Vector operator / (Vector A, double B) {return Vector(A.x/B,A.y/B);}

int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	else if(x>0) return 1;
	else return -1;
}

double cross(Vector p,Vector q){return p.x*q.y-p.y*q.x;}
int n,d,cnt=0;
double hp,pos,pre[100005];

signed main()
{
	scanf("%lld%lld",&n,&d);
	double res=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&hp,&pos);
		pre[i]=pre[i-1]+hp;
		Point p={i*1.0*d,pre[i-1]},now={pos+i*1.0*d,pre[i]};

		while(cnt>1&&dcmp(cross(stk[cnt]-stk[cnt-1],p-stk[cnt]))<0) cnt--;
		cnt++;
		stk[cnt]=p;

		if(cnt==1){
			res+=(hp/pos);
		}else{
			int left=1,right=cnt;
			while(left+10<right)
			{
				int mid=(left+right)/2;
				int midr=(mid+right)/2;
				double k1=(now.y-stk[mid ].y)/(now.x-stk[mid ].x);
				double k2=(now.y-stk[midr].y)/(now.x-stk[midr].x);

				if(k1>k2) right=midr;
				else if(k1<k2) left=mid;
			}

			double maxd=0;
			for(int j=left;j<=right;j++)
			{
				double temp=(now.y-stk[j].y)/(now.x-stk[j].x);
				maxd=max(maxd,temp);
			}
			res+=maxd;
		}
	}
	printf("%.0lf\n",res);
	return 0;
}
// #include <bits/stdc++.h>
// typedef long long ll;
// typedef double db;
// const ll mod=1e9+7;
// const int maxn=1e6;
// using namespace std;
// int t=1,n,x;
// db d,a[maxn],ans;
// void slove(){
//     cin>>n>>d;
//     for(int i=1;i<=n;i++){
//         cin>>a[i]>>x;// x是米 a是血量
//         db tmp=a[i]/x;
//         db pre=a[i],pred=x;
//         for(int j=i-1;j>=1;j--){
//             pred+=d;
//             pre+=a[j];
//             tmp=max(tmp,pre/pred);
//         }
//         ans=ans+tmp;
//     }
//     cout<<fixed<<setprecision(0)<<ans;
// 	return;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     while(t--){
// 		slove();
//     }
//     return 0;
// }
//实数二分的写法 复杂度n^2乘一个比较大的常数
//#include <bits/stdc++.h>
//typedef long long ll;
//typedef long double db;
//const ll mod=1e9+7;
//const int maxn=1e6;
//#define eps 1e-12
//using namespace std;
//int t,n,d,pos;
//double  a[maxn],x,ans;
//double  pre[maxn];
//bool check(double  num){
//   double  s=num*x;
//    double  m=a[pos];
//    if(s<m) return false;
//    for(int i=pos-1;i>=1;i--){
//        m+=a[i];
//        s=s+num*d;
//        if(s<m) return false;
//    }
//    return true;
//}
//void slove(){
//	cin>>n>>d;
//	for(int i=1;i<=n;i++){
//        pos++;
//        cin>>a[i]>>x;
//        pre[i]=pre[i-1]+a[i];
//        double  l=0,r=1e12+1.00001;
//        while(l+eps<r){
//            db mid=(l+r)/2;
//            if(check(mid)) r=mid;
//            else l=mid;
//        }
//        //cout<<r<<endl;
//        ans=ans+r;
//	}
//	cout<<fixed<<setprecision(0)<<ans;
//	return;
//}
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    t=1;
//    while(t--){
//		slove();
//    }
//    return 0;
//}
