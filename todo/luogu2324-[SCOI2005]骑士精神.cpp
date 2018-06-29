//luogu wa

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
int t,line[10][10],x,y;
int res[10][10]{
	{},
	{0,1,1,1,1,1},
	{0,0,1,1,1,1},
	{0,0,0,2,1,1},
	{0,0,0,0,0,1},
	{0,0,0,0,0,0}
};
int dir[10][2]{{},{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1}};
int maxst,fl=0;
void pr(){
	rep(i,1,5){
		rep(j,1,5)
		   printf("%d ",line[i][j]);
		putchar('\n');
	}
}
int dif(){
	int tmp=0;
	rep(i,1,5)rep(j,1,5)
	   if(line[i][j]!=res[i][j])
		  ++tmp;
	return tmp;
}
void dfs(int x,int y,int st,int la){
	int tmp=dif();
	if(tmp==0){
		fl=1;
		return;
	}
	if(tmp+st>maxst+1||st>=maxst)
	   return;
	rep(i,1,8){
		if(i+la==9)continue;
		int xx=x+dir[i][0],yy=y+dir[i][1];
		if(xx<1||xx>5||yy<1||yy>5)continue;
		swap(line[x][y],line[xx][yy]);
		dfs(xx,yy,st+1,i);
		swap(line[x][y],line[xx][yy]);
		if(fl)return;
	}
}
int main(){
//	ios::sync_with_stdio(0),cin.tie(0);
	scanf("%d\n",&t);
	char c;
	while(t--){
		rep(i,1,5){
			rep(j,1,5){
				c=getchar();
				if(c=='*')x=i,y=j,line[i][j]=2;
				else line[i][j]=c-'0';
			}
			c=getchar();
		}
		//ida*
		rep(i,1,15){
			maxst=i,fl=0;
			dfs(x,y,0,-1);
			if(fl==1){
				printf("%d\n",i);
				break;
			}
		}
		if(fl==0){
			printf("-1\n");
		}
	}
	return 0;
}














//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




