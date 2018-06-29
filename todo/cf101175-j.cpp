#include<cstdio>
#include<iostream>
#include<cmath>
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
const int nsz=2e5+50;
int t,n,line[nsz],dif[nsz];
int pr=0;
void chg(int &p1,int &p2){
	
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	rep(cz,1,t){
		cin>>n;
		rep(i,1,n)cin>>line[i],dif[i]=line[i]-line[i-1];
		int pr=0,res=1;
		rep(i,1,n){
			while(dif[pr]>=0&&pr<=n)++pr;
			if(pr==n+1){res=0;break;}

		}
	}
	return 0;
}














//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




