#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,t;
ll lowbit(ll x){
	return x&(-x);
}
bool check(ll x){
	if( x==lowbit(x) && (x%3==1 && x!=2)   ) return true;
	return false;
}
void slove(){
	cin>>n;
	vector<ll> ans;
	while(!check(n)){
		ans.push_back(lowbit(n) );
		n+=lowbit(n);
	}
	cout<<ans.size()<<"\n";
	for(auto u:ans) cout<<u<<" ";
	cout<<"\n"; 
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--) slove();
	return 0;
}
