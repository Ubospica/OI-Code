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
const int nsz=250,msz=10500*2,ninf=1e9+7;
int cs,n,m,sum;

struct te{int t,v,pr;}edge[msz];
int h[nsz],pe=1,st=240,ed=241,npo;
void adde(int f,int t,int v){edge[++pe]=(te){t,v,h[f]};h[f]=pe;}
void addsg(int f,int t,int v){adde(f,t,v);adde(t,f,0);}
int tr1(int a){return a;}//student
int tr2(int a){return a+n;}

int cur[nsz],d[nsz],gap[nsz];
void init0(){
	rep(i,1,245)h[i]=d[i]=gap[i]=0;
	pe=1,sum=0;
}
void init(){
	int qu[nsz],qh=1,qt=0;
	rep(i,1,245)cur[i]=h[i];
	qh=1,qt=0;
	qu[++qt]=ed,d[ed]=1,gap[1]=1;
	while(qh<=qt){
		int u=qu[qh++];
		for(int i=h[u],v=edge[i].t;i;i=edge[i].pr,v=edge[i].t){
			if(d[v]||edge[i^1].v==0)continue;
			d[v]=d[u]+1,++gap[d[v]];
			qu[++qt]=v;
		}
	}
}
int dfs(int p,int mi){
	if(mi==0||p==ed)return mi;//p==t
	int res=0,tmp;
	for(int &i=cur[p],v=edge[i].t;i;i=edge[i].pr,v=edge[i].t){//cur
		if(edge[i].v==0||d[v]+1!=d[p])continue;
		tmp=dfs(v,min(mi,edge[i].v));
		edge[i].v-=tmp,edge[i^1].v+=tmp,mi-=tmp,res+=tmp;
		if(mi==0)return res;
	}
	if(gap[d[p]]==1){d[st]=npo+1;return res;}
	--gap[d[p]],++d[p],++gap[d[p]];
	cur[p]=h[p];//
	return res;
}

int isap(){
	int ans=0;
	init();
	while(d[st]<=npo)ans+=dfs(st,ninf);
	return ans;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>cs;
	while(cs--){
		init0();
		cin>>n>>m;
		npo=m+n+2;
		int a,b,c;
		rep(i,1,m){
			cin>>a;
			addsg(tr2(i),ed,a);
			sum+=a;
		}
		rep(i,1,n){
			cin>>a>>b;
			addsg(st,tr1(i),a);
			rep(j,1,b){
				cin>>c;
				addsg(tr1(i),tr2(j),1);
			}
		}
		cout<<(isap()>=sum?"Yes":"No")<<'\n';
	}
	return 0;
}














//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




