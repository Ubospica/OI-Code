#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define rep(i,l,r) for(register int i=(l);i<=(r);++i)
#define repdo(i,l,r) for(register int i=(l);i>=(r);--i)
#define il inline
typedef long long ll;
typedef double db;

//---------------------------------------
const int nsz=1e5+50,ksz=2e5+50;
int n0,n,k,ans[nsz];
struct tnd{int x,y,z,cnt,ans;}line[nsz],tmp[nsz];
bool cmp1(tnd a,tnd b){return a.x!=b.x?a.x<b.x:a.y!=b.y?a.y<b.y:a.z<b.z;}
bool cmp2(tnd a,tnd b){return a.y!=b.y?a.y<b.y:a.z<=b.z;}
bool operator==(tnd a,tnd b){return a.x==b.x&&a.y==b.y&&a.z==b.z;}
ostream& operator<<(ostream &os,tnd a){
    os<<a.x<<' '<<a.y<<' '<<a.z<<' '<<a.cnt<<' '<<a.ans;
    return os;
}

struct tbit{
    int val[ksz],sz;
    static int lb(int a){return a&(-a);}
    void add(int p,int a){for(;p<=sz;p+=lb(p))val[p]+=a;}
    void set(int p,int a){for(;p<=sz;p+=lb(p))val[p]=a;}
    int ask(int p){int ans=0;for(;p>0;p-=lb(p))ans+=val[p];return ans;}
    int& operator[](int p){return val[p];}
}bit;

void uniq(){
    int cnt=0;
    rep(p,1,n0){
        ++cnt;
        if(!(line[p]==line[p+1]))
            line[++n]=line[p],line[n].cnt=cnt,cnt=0;
    }
}
void cdq(int l,int r){
    if(l==r)return;
    int mid=(l+r)>>1;
    cdq(l,mid),cdq(mid+1,r);
    int pl=l,pr=mid+1,pt=l-1;
	while(pl<=midpr<=r){
        if(cmp2(line[pl],line[pr])){
            bit.add(line[pl].z,line[pl].cnt);
            tmp[++pt]=line[pl++];
        }
        else{
            line[pr].ans+=bit.ask(line[pr].z);
            tmp[++pt]=line[pr++];
        }
    }

//    while(pl<=mid&&pr<=r){
//        if(cmp2(line[pl],line[pr])){
//            bit.add(line[pl].z,line[pl].cnt);
//            tmp[++pt]=line[pl++];
//        }
//        else{
//            line[pr].ans+=bit.ask(line[pr].z);
//            tmp[++pt]=line[pr++];
//        }
//    }
    while(pl<=mid)tmp[++pt]=line[pl++];
    while(pr<=r)line[pr].ans+=bit.ask(line[pr].z),tmp[++pt]=line[pr++];
    rep(i,l,mid)bit.set(line[i].z,0);
    rep(i,l,r)line[i]=tmp[i];
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n0>>k;
    bit.sz=k;
    rep(i,1,n0)cin>>line[i].x>>line[i].y>>line[i].z;
    sort(line+1,line+n0+1,cmp1);
    uniq();
    cdq(1,n);
    rep(i,1,n)ans[line[i].ans+line[i].cnt-1]+=line[i].cnt;
    rep(i,0,n0-1)cout<<ans[i]<<'\n';
//	rep(i,1,n0)cout<<line[i]<<'\n';
    return 0;
}














//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




