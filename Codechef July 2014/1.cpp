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
#define print(x) cout<<(#x)<<" = "<<x<<"\n";
#define fill(x,val) memset(x ,val, sizeof(x) );
/*Solution code starts here */


int main()
{
 ll test,x,y;

 cin>>test;

 while(test--)
 {
         cin>>x>>y;

         x=llabs(x); y=llabs(y);//sab move "symmetric" hai

         ll ans=0;

         if(x==y)
         {
             ans=2*x;
         }
         else if( x < y)
         {
             ans=2*x;
             y-=x;

             if(y&1)
                ans+=2*y-1;
             else
                ans+=2*y;
         }
        else if( x > y)
        {
            ans=2*y;
            x-=y;

            if(x&1)
                 ans+=2*x+1;
            else
                  ans+=2*x;
        }

        cout<<ans<<endl;
 }
 return 0;

}
