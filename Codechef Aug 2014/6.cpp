#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz size()
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

#define mod 1000000009

#define maxdiff 8000009
#define maxn 1000005
#define offset 4000001

int last[maxdiff];
ll sum[maxn];
int n;
int in[maxn];
int diff[maxn];

void solve()
{
      scanf("%d",&n);

      for(int i=1;i<=n;i++)
         scanf("%d",&in[i]);

      for(int i=2;i<=n;i++)
          diff[i-1]=in[i]-in[i-1];

      n--;

      for(int i=1;i<=n;i++)
         last[ diff[i]+ offset ]=-1;

       sum[0]=1;//null

       for(int i=1;i<=n;i++)
       {
            ll sub=0;

            if( last[ diff[i]+offset ]!=-1)
                  sub=sum[ last[ diff[i]+offset ] -1 ];

            ll dp=( sum[i-1] + mod + mod - sub   )%mod;

            sum[i]=( sum[i-1]+dp)%mod;

            last[ diff[i]+offset ]=i;
       }

       sum[n]=(sum[n]+mod-1+mod)%mod;

       printf("%lld\n",sum[n]);

}

int main()
{
 int test;

 scanf("%d",&test);

 fill( last ,-1);

 while(test--)
 {
     solve();
 }


 return 0;

}
