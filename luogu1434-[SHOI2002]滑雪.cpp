//dfs

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
int n,m,line[150][150];
int dir[5][2]{{},{1,0},{-1,0},{0,1},{0,-1}};
int res[150][150],ans=0;
void getmax(int &a,int b){if(a<b)a=b;}
int dfs(int x,int y){
	if(x<1||x>n||y<1||y>m)return 0;
	if(res[x][y])return res[x][y];
	int tmp=0,x1,y1;
	rep(i,1,4){
		x1=x+dir[i][0],y1=y+dir[i][1];
		if(line[x1][y1]>=line[x][y])continue;
		getmax(tmp,dfs(x1,y1));
	}
	res[x][y]=tmp+1;

//	printf("x=%d,y=%d\n",x,y);
//	rep(i,1,n){
//		rep(j,1,m)
//		   cout<<res[i][j]<<' ';
//		cout<<'\n';
//	}

	return res[x][y];
}
int main(){
//	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	rep(i,1,n)rep(j,1,m)cin>>line[i][j];
	rep(i,1,n)rep(j,1,m){
		if(res[i][j])continue;
		getmax(ans,dfs(i,j));
	}
	cout<<ans<<'\n';

	return 0;
}














//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




