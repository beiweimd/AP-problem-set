#include<bits/stdc++.h>
#define ll long long
#define map_it map<ll,ll>::iterator
using namespace std;
ll n;
map<ll,ll> top,down;

inline ll read(){
	ll x=0,tmp=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') tmp=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return tmp*x;
}

inline bool check_top(ll x,ll y){
    map_it i=top.lower_bound(x);
    if(i==top.end()) return 0;
    if(i->first==x) return y<=i->second;
    if(i==top.begin()) return 0;
    map_it j=i; j--;
    return (i->first-j->first)*(y-j->second)-(i->second-j->second)*(x-j->first)<=0;
}

inline bool check_down(ll x,ll y){
    map_it i=down.lower_bound(x);
    if(i==down.end()) return 0;
    if(i->first==x) return y>=i->second;
    if(i==down.begin()) return 0;
    map_it j=i; j--;
    return (i->first-j->first)*(y-j->second)-(i->second-j->second)*(x-j->first)>=0;
}

inline bool delete_top(map_it i){
	if(i==top.begin()) return 0;
	map_it j=i,k=i; j--; k++;
	if(k==top.end()) return 0;
	if((i->first-j->first)*(k->second-j->second)-(i->second-j->second)*(k->first-j->first)>=0){
		top.erase(i);
		return 1;
	}
	return 0;
}

inline bool delete_down(map_it i){
	if(i==down.begin()) return 0;
	map_it j=i,k=i; j--; k++;
	if(k==down.end()) return 0;
	if((i->first-j->first)*(k->second-j->second)-(i->second-j->second)*(k->first-j->first)<=0){
		down.erase(i);
		return 1;
	}
	return 0;
}

inline void insert_top(ll x,ll y){
	if(check_top(x,y)) return;
	top[x]=y;
	map_it i=top.find(x),j=i;
	if(i!=top.begin()){
		j--;
		while(delete_top(j++)) j--;
	}
	if(++j!=top.end()) while(delete_top(j--)) j++;
}

inline void insert_down(ll x,ll y){
	if(check_down(x,y)) return;
	down[x]=y;
	map_it i=down.find(x),j=i;
	if(i!=down.begin()){
		j--;
		while(delete_down(j++)) j--;
	}
	if(++j!=down.end()) while(delete_down(j--)) j++;
}

int main(){
	n=read();
	for(ll i=1; i<=n; i++){
		ll op=read(),x=read(),y=read();
		if(op==1){
			insert_top(x,y);
			insert_down(x,y);
		}
		else{
			if(check_top(x,y)&&check_down(x,y)) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}