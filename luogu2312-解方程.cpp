//双取模，秦九韶算法

#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
#define rep(i,l,r) for(register int i=(l);i<=(r);++i)
#define repdo(i,l,r) for(register int i=(l);i>=(r);--i)
#define il inline
typedef double db;
typedef long long ll;

//---------------------------------------
const ll m1=10007,m2=998244353,msz=1e6+50;
ll n,m;
ll line[2][210],chk[m1+50],ans[msz],pm=0;
void add(ll &a,int b,ll x,ll mod){a=(a*x+b)%mod;}
ll cal(ll a,int fl,ll mod){
	ll res=0;
	repdo(i,n,0)add(res,line[fl][i],a,mod);
	return res==0;
}
int main(){
//	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	char c;int sg=1;
	rep(i,0,n){
		sg=1;
		for(c=getchar();!isdigit(c);c=getchar())if(c=='-')sg=-1;
		for(;isdigit(c);c=getchar())add(line[0][i],c-'0',10,m1),add(line[1][i],c-'0',10,m2);
		line[0][i]*=sg,line[1][i]*=sg;
	}
	rep(i,0,m1-1)chk[i]=cal(i,0,m1);
	rep(i,1,m)if(chk[i%m1]&&cal(i,1,m2))ans[++pm]=i;
	cout<<pm<<'\n';
	rep(i,1,pm)cout<<ans[i]<<'\n';
	return 0;
}














//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




