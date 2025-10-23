#include <iostream>
#include<cmath>
#include<vector>
#include<map>
#include<iomanip>
#include<stack>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const int maxn=1e6;
const db pi=acos(-1);
const db eps=1e-12;
const ll inf=1e18;
using namespace std;
int n,s,ans;
ll t[maxn],c[maxn],f[maxn]; // dp i代表处理 前i个任务分成若干组所需要的最小费用
ll pret[maxn],prec[maxn];
int q[maxn],tail=0;
void init(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>c[i];
        pret[i]=pret[i-1]+t[i];
        prec[i]=prec[i-1]+c[i];
    }
    // for(int i=1;i<=3;i++){
    //     f[i]=inf;
    //     for(int j=0;j<i;j++){ // 从f j转移过来 也就是j+1和i成一组来分配任务
    //         f[i]=min(f[i],
    //             f[j]+ pret[i]  * (prec[i]-prec[j])+ // 这一部分 说明不考虑启动的s的代价 完成时间是preti 那么j+1和i是一组的
    //                 s*(prec[n]-prec[j]) // 启动一组 所有后续的物品都要被影响
    //         );
    //     }
    //     while (tail && ((f[i] - f[q[tail]]) * (prec[q[tail]] - prec[q[tail - 1]]) <=
	// 		(f[q[tail]] - f[q[tail - 1]]) * (prec[i] - prec[q[tail]]))) tail--;
	//     tail++;
	//     q[tail] = i;
    // }
    for(int i=1;i<=n;i++){
        int l=0,r=tail;
        ll k=pret[i]+s; // 要找的这个直线的斜率  
        while(l<=r){
            int mid=(l+r)>>1;
            if((f[q[mid]]-f[q[mid+1]])>=k*(prec[q[mid]]-prec[q[mid+1]]) ){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        } 
        r=l;
        f[i] = f[q[r]] + s * (prec[n] - prec[q[r]]) + pret[i] * (prec[i] - prec[q[r]]);  
        while (tail && ((f[i] - f[q[tail]]) * (prec[q[tail]] - prec[q[tail - 1]]) <=
			(f[q[tail]] - f[q[tail - 1]]) * (prec[i] - prec[q[tail]]))) tail--;
	    tail++;
	    q[tail] = i;
    }
    cout<<f[n];
    return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    return 0;
}