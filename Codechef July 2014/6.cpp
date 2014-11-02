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

#define maxn 55
#define maxc 105

int lp[55],rp[55];
int n,k,c;

bool done[maxn][maxc];
double memo[maxn][maxc];

int nextt[maxc][maxc];

int id;

double ps=1/2.0;

double solve(int pos , int curr)
{
    if(pos==k+1) return curr;

     if( done[pos][curr]) return memo[pos][curr];

     if( (id<lp[pos])||(rp[pos]<id) ) return solve(pos+1,curr);

     double ans=0;

     done[pos][curr]=true;

     for(int i=0;i<c;i++)
     {
         int nc=nextt[curr][i];

         ans+=ps*solve(pos+1,nc);
         ans+=ps*solve(pos+1,curr);
     }

     ans=ans/((double)c);

    return memo[pos][curr]=ans;
}


void process()
{
     scanf("%d%d%d",&n,&c,&k);

     for(int i=1;i<=k;i++)
         scanf("%d%d",&lp[i],&rp[i]);

     for(int i=0;i<maxc;i++)
         for(int j=0;j<maxc;j++)
          nextt[i][j]=(i*j)%c;

     double ans=0;

     for(int i=1;i<=n;i++)
     {
         id=i;
         fill(done,0);
         ans+=solve(1,1);
     }

     printf("%0.10lf\n",ans);
}
int main()
{
   int test;

    scanf("%d",&test);

    while(test--)
    {
        process();
    }

 return 0;

}
