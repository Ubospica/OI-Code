#include<cstdio>
#include<iostream>
#include<cstring>
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
int n,res=0;
int gcd(int a,int b){
	return a==0?b:gcd(b%a,a);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int a;
	cin>>n;
	rep(i,1,n)
	   cin>>a,res=gcd(res,a<0?-a:a);
	cout<<res<<'\n';
//	cout<<gcd(4059,1782);
	return 0;
}














//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




