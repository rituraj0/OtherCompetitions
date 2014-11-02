#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
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


ll all[1<<20];
//ll in[1<<20];

int main()
{
 ios_base::sync_with_stdio(0);

 int n;

 cin>>n;

  fill(all,0);

  ll x ;

 for(int i=1;i<=n;i++)
 {
     cin>>x;

     all[i]=all[i-1]+x;
 }

 int Q;

 cin>>Q;

 for(int q=1;q<=Q;q++)
 {
     cin>>x;

     int lo=1,hi=n;

     ll ans=-1;

     while(lo <=hi )
     {
         ll mid=(lo+hi)/2LL;

         if( (all[mid-1]+1 <= x) && (x <= all[mid] ) )
         {
             ans=mid;
             break;
         }
        else if( x <= all[mid] )
        {
            hi=mid-1;
        }
        else

        {
            lo=mid+1;
        }

     }

     cout<<ans<<endl;
 }





 return 0;

}
