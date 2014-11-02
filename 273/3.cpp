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


int main()
{
 ios_base::sync_with_stdio(0);

 ll a,b,c;


 cin>>a>>b>>c;

 ll ans=0;
 ll lo=0,hi=(1LL<<50);

 while(lo<=hi)
 {
   ll mid=(lo+hi)/2LL;

   ll sm=min(mid*2LL,a)+min(mid*2LL,b)+min(mid*2LL,c);

   if(sm>=mid*3)
   {
       ans=mid;
       lo=mid+1;
   }
   else
   {
      hi=mid-1;
   }
 }

 cout<<ans<<endl;

 return 0;

}
