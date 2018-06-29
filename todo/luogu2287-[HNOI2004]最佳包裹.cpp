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
const db eps=1e-10;
const int nsz=150;
int n;
struct tvec{
   int x,y,z;
   db len(tvec a){return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);}
}line0[nsz]，line[nsz];
tvec operator+(tvec a,tvec b){return (tvec){a.x+b.x,a.y+b.y};}
tvec operator-(tvec a,tvec b){return (tvec){a.x-b.x,a.y-b.y};}
db dot(tvec a,tvec b){
	return a.x*b.x+a.y*b.y+a.z*b.z;
}
tvec cross(tvec a,tvec b){
	return (tvec){a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};
}

db rand01(){return (db)rand()/RAND_MAX;}
db randeps(){return (rand01()-0.5)*eps;}
tvec addnoise(tvec &p){return (tvec){p.x+randeps(),p.y+randeps(),p.z+randeps();}}

struct tfac{
	int v[3];
	tvec normal(){return cross(line[v[1]]-line[v[0]],line[v[2]]-line[v[0]]);}
	bool cansee(tvec p){return dot(p-p[v[0]],normal())>eps;}
}conv[nsz*3];
int pc=0;

void getconv(){
	conv[++pc]=(tfac){1,2,3};
	conv[++pc]=(tfac){3,2,1};
	rep(i,4,n){
		rep(j,1,pc){
			
		}
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	rep(i,1,n)cin>>line0[i].x>>line0[i].y>>line0[i].z,line[i]=addnoise(line0[i]);

	return 0;
}














//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




