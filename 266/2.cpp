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


int main()
{
 ios_base::sync_with_stdio(0);

 ll n,a,b;

 cin>>n>>a>>b;

 ll ans=1e18;
 ll x=-1,y=-1;

 a=min(a,b);
 b=max(a,b);

  ll lo=a*b*(6LL),hi=1e10;

  while(lo<=hi)
  {
      ll mid=(lo+hi)/2;

      bool cool=false;

         for(ll i=1;i*i<=mid;i++)
             if( mid%i==0)
             {
               ll mn=min(i,mid/i),mx=max(i,mid/i);

               if( (mn>=a)&&(mx>=b))
               {
                   cool=true;
                   ans=mid;
                   x=mn;
                   y=mx;
                   break;
               }
             }

             if(cool)
             {
                hi=mid-1;
             }
             else
             {
                 lo=mid+1;
             }
  }

cout<<ans<<endl;
cout<<x<<" "<<y<<endl;

 return 0;

}
