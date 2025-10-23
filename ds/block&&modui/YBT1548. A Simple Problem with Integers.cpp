#include <bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
const int maxn=2*1e5;
using namespace std;
int t,n,m,l,r,q;
char op;
ll c;
ll a[maxn]; 
ll sum[maxn]; 
int bl[maxn];//i属于第几个块 
ll atag[maxn]; //代表第i个块整体被加了多少 
vector<ll >ve[maxn]; 
int find(int x ){
	return (x-1)/m+1;
}
void reset(int x ) {  // 对块内元素重新排序 
	ve[x].clear();
	for(int i=x*m-m+1;i<=min(n,x*m);i++){
		ve[x].push_back(a[i]);
	}
	sort(ve[x].begin(),ve[x].end());
}
void add(int l ,int r,  ll c){
	for(int i=l;i<=min(bl[l]*m,r);i++){
		a[i]+=c;
		sum[bl[i]]+=c;
	}
	//reset(bl[l]);
	if(find(l)!=find(r)){
		for(int i=(find(r)*m-m+1);i<=r;i++){
			a[i]+=c;
			sum[bl[i]]+=c;
		}
	//	reset(bl[r]);
	}
	for(int i=bl[l]+1;i<bl[r];i++){
		atag[i]+=c;
	}	
	return ;
} 
ll query(int l ,int r){
	ll s=0;
	for(int i=l;i<=min(bl[l]*m,r);i++){
		s=s+a[i]+atag[bl[i]];
	}
	if(find(l)!=find(r)){
		for(int i=(find(r)*m-m+1);i<=r;i++){
			s=s+a[i]+atag[bl[i]];
		}
	}
	for(int i=bl[l]+1;i<=bl[r]-1;i++){
			s=s+sum[i]+atag[i]*m;
	}
	return s;
}
void slove(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		if(i*i>=n){
			m=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bl[i]=find(i);
		ve[bl[i]].push_back(a[i]);
		sum[bl[i]]+=a[i];
	}
	for(int i=1;i<=q;i++){
		cin>>op>>l>>r;
		if(op=='C'){
            cin>>c;
			add(l,r,c);
		}
		else cout<<query(l,r)<<"\n";	
	}
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