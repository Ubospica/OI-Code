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
ll m,f,n;
struct tnode{ll s,p;}line[250];
bool cmp(tnode l,tnode r){return l.s!=r.s?l.s<r.s:l.p>r.p;}
void print(){
    cout<<"n="<<n<<'\n';
    rep(i,1,n)cout<<line[i].s<<' '<<line[i].p<<'\n';
}
void uniq(){
    int p=0;
    rep(i,1,n){
        while(p&&line[p].p>=line[i].p)--p;
        line[++p]=line[i];
    }
    n=p;
}
ll fun(ll x){
    ll mon=m-x*f,res=0;
    if(mon<0)return -1;
    rep(i,1,n){
        if(line[i].s<res)continue;
        ll tmp=(line[i].s-res);
        if(tmp>(db)mon/(line[i].p*x)){
            return res*x+(mon/line[i].p);
        }
        mon-=tmp*line[i].p*x;
        res+=line[i].s-res;
    }
    return res*x;
}
void getmax(ll &a,ll b){if(a<b)a=b;}
ll tri(){//max val
    ll l=1,r=m/f,tmp,mid1,mid2,v1,v2,ans=0;
    while(l<=r){
        tmp=(r-l+1)/3,mid1=l+tmp,mid2=r-tmp;
        v1=fun(mid1),v2=fun(mid2);
        getmax(ans,max(v1,v2));
        if(v1<v2)l=mid1+1;
        else r=mid2-1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>m>>f>>n;
    rep(i,1,n)cin>>line[i].p>>line[i].s,++line[i].s;
    sort(line+1,line+n+1,cmp);
    uniq();
//	print();
    cout<<tri()<<'\n';
    return 0;
}














//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




