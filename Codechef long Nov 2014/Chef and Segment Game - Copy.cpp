#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
#define bg begin()
#define en end()
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */


void solve()
{
   ll K;
   double X;

   scanf("%lf%lld",&X, &K);

   if( K == 1)
   {

       printf("%.9lf\n",X/2.0);
       return;
   }

   ll lo=-1,hi=-1;

   for(int i=1;i<55;i++)
   {
       if( (1LL<<i)  > K)
       {
            hi=(1LL<<i);
            lo=(1LL<<(i-1));
            break;
       }
   }

   double seg_len=X/hi;

   ll offset= ( (K-lo)<<1 ) + 1;

   printf("%.9lf\n",  ( seg_len*(double)offset ) );

}
int main()
{

 int test;

 scanf("%d",&test);

 while(test--)
 {
    solve();

 }

 return 0;

}
