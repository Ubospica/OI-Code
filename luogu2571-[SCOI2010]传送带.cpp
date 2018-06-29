//三分套三分

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
const db eps=1e-4;
double p,q,r;
struct po{db x,y;}a,b,c,d;
db pow2(db a){return a*a;}
db dis(po a,po b){
	return sqrt(pow2(a.x-b.x)+pow2(a.y-b.y));
}
db cal(db d1,db d2){
	static db x1=b.x-a.x,y1=b.y-a.y,x2=c.x-d.x,y2=c.y-d.y;
	po p1{a.x+x1*d1,a.y+y1*d1},p2{d.x+x2*d2,d.y+y2*d2};
	return dis(a,p1)/p+dis(p2,d)/q+dis(p1,p2)/r;
}
db solve2(db x){
	db l=0,r=1,res;
	while(1){
		db mid1=(l+r)/2,mid2=(mid1+r)/2;
		db v1=cal(x,mid1),v2=cal(x,mid2);
		if(abs(v1-v2)<=eps){res=v1;break;}
		if(v1<v2)r=mid2;
		else l=mid1;
	}
	return res;
}
db solve1(){
	db l=0,r=1,res;
	while(1){
		db mid1=(l+r)/2,mid2=(mid1+r)/2;
		db v1=solve2(mid1),v2=solve2(mid2);
		if(abs(v1-v2)<=eps){res=v1;break;}
		if(v1<v2)r=mid2;
		else l=mid1;
	}
	return res;
}
int main(){
//	ios::sync_with_stdio(0),cin.tie(0);
	int a,b,c,d,e,f,g,h;
	scanf("%d%d%d%d %d%d%d%d %lf%lf%lf",&a,&b,&c,&d,&e,&f,&g,&h,&p,&q,&r);
	::a=(po){a,b},::b=(po){c,d},::c=(po){e,f},::d=(po){g,h};
	printf("%.2lf",solve1());
	return 0;
}














//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




