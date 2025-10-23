#include <cstdio>
#define print(x,y) write(x),putchar(y)

template <class T>
inline T read(const T sample) {
	T x=0; char s; bool f=0;
	while((s=getchar())>'9' or s<'0')
		f|=(s=='-');
	while(s>='0' and s<='9')
		x=(x<<1)+(x<<3)+(s^48),
		s=getchar();
	return f?-x:x;
}

template <class T>
inline void write(const T x) {
	if(x<0) {
		putchar('-'),write(-x);
		return;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
} 

#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

const int maxn=5e4+500,maxb=230;

int n,m,B,bl[maxn],K,x,y;
int st[maxb][maxb];
ll s[maxn],k[maxn],c[maxn];
// s代表的是前缀 c[i]代表的是一个整块前缀数组被加的数值   k[i]代表的是 第i个块前缀被加的线性部分

void modify(int pos,int l=0,int r=0) { // pos代表的是第几个快  
	if(l and r) { // 如果是对一个块进行操作
		st[pos][0]=0;
		ll tmp=1ll*K*(l-x+1);
		for(int i=l;i<=r;++i)
			s[i]+=tmp,tmp+=K; // 暴力修改s
	}
	else k[pos]+=K,c[pos]+=1ll*K*(1-x); //对一个区间进行操作
}

ll query(int pos,int l=0,int r=0) {
	if(l and r) { // 查询一个块里的
		ll tmp=s[l]+k[pos]*l;
		for(int i=l+1;i<=r;++i)
			tmp=max(tmp,s[i]+k[pos]*i);
		return tmp+c[pos];
	}
	if(!st[pos][0]) {
		int *tp=&st[pos][0];
		for(int i=(pos-1)*B+1;i<=pos*B;++i) {
			while((*tp)>1 and 1ll*(s[i]-s[st[pos][*tp]])*(st[pos][*tp]-st[pos][*tp-1])>1ll*(s[st[pos][*tp]]-s[st[pos][*tp-1]])*(i-st[pos][*tp]))
				--(*tp);
			st[pos][++(*tp)]=i;
		}
	}
	l=1,r=st[pos][0]-1; int mid,a,b;
	while(l<=r) {
		mid=l+r>>1;
		a=st[pos][mid];
		b=st[pos][mid+1];
		if(s[b]-s[a]>-k[pos]*(b-a))
			l=mid+1;
		else r=mid-1;
	}
	return s[st[pos][l]]+c[pos]+k[pos]*st[pos][l];
}

signed main() {
	n=read(9); B=sqrt(n);
	for(int i=1;i<=n;++i)	
		s[i]=s[i-1]+read(9),
		bl[i]=(i-1)/B+1;
	m=read(9);
	int op; ll ans;
	while(m--) {
		op=read(9),x=read(9);
		y=read(9);
		if(!op) {
			K=read(9);
			if(bl[x]^bl[y]) { // 如果x y不在一个块里
				modify(bl[x],x,bl[x]*B); // 对x开头 x结尾的那个块 修改
				modify(bl[y],(bl[y]-1)*B+1,y); //对y那个块开头 y结尾的区间 修改
				for(int i=bl[x]+1;i<bl[y];++i)	
					modify(i);
			}
			else modify(bl[x],x,y); // x y 在一个块里 
			K*=(y-x+1); // 计算 add区间的总贡献
			for(int i=y+1;i<=bl[y]*B;++i) // 这里是处理[x,y] y-y这个散块末尾的前缀 暴力修改
				s[i]+=K;
			for(int i=bl[y]+1;i<=bl[n];++i)
				c[i]+=K; // c i代表的是第i个块 里的前缀都加了多少
		}
		else {
			ans=0;
			if(bl[x]^bl[y]) {
				ans=query(bl[x],x,bl[x]*B);
				ans=max(ans,query(bl[y],(bl[y]-1)*B+1,y));
				for(int i=bl[x]+1;i<bl[y];++i)	
					ans=max(ans,query(i));
			}
			else ans=query(bl[x],x,y);
			print(ans,'\n');
		}
	}
	return 0;
}
