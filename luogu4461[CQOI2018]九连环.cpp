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
//2^n/3
const int bigsz=1e5+50,blk=1e9;
int t,n;
ll tmp[bigsz],res[bigsz]{1,1},fact[bigsz]{1,2};
void mult(ll *a,ll *b){// *=
    rep(i,1,a[0])rep(j,1,b[0]){
        tmp[i+j-1]+=a[i]*b[j];
        if(tmp[i+j-1]>=blk)tmp[i+j]+=tmp[i+j-1]/blk,tmp[i+j-1]%=blk;
    }
    a[0]=a[0]+b[0]+1;
    while(a[0]&&tmp[a[0]]==0)--a[0];
    rep(i,1,a[0])a[i]=tmp[i],tmp[i]=0;
}
void div(ll *a,int b){// /=
    repdo(i,a[0],2){
        a[i-1]+=(a[i]%b)*blk;
        a[i]/=b;
    }
    a[1]/=b;
    while(a[0]&&a[a[0]]==0)--a[0];
}
void pow(int a){
    while(a){
        if(a&1)mult(res,fact);
        mult(fact,fact);
        a>>=1;
    }
}
void out(ll *a){
//	while(a[0]&&a[a[0]]==0)--a[0];
    printf("%d",a[a[0]]);
    repdo(i,a[0]-1,1){

//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！
//补零！！！！

        printf("%09d",a[i]);
    }
}
int main(){
//	freopen("a.in","r",stdin);
//  freopen("a.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0);
    cin>>t;
    while(t--){
        memset(tmp,0,sizeof(tmp));
        fact[0]=1,fact[1]=2;
        res[0]=1,res[1]=1;
        cin>>n;
        pow(n+1);
        div(res,3);

        out(res);
        cout<<'\n';
    }
    return 0;
}















//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




		cin>>n;
		pow(n+1);
		div(res,3);

		out(res);
		cout<<'\n';
	}
	return 0;
}















//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




