#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz size()
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
    int x,y;

    cin>>x>>y;

    string ans="NO";

    int lo=(1<<30),hi=(1<<30);

//    print(lo);

    if(x==0)
    {
        lo=0,hi=0;
    }
   else if( x > 0)
   {
       if(x%2==1)
       {
           lo=-(x-1);
           hi=x+1;
       }
   }
   else
   {
      int tp=abs(x);

      if(tp%2==0)
      {
          lo=-tp;
          hi=tp;
      }
   }

   if( (lo<=y)&&(y<=hi) )
      ans="YES";


   int l=(1<<30),r=(1<<30);

   if(y==0)
   {
       l=0,r=1;
   }
   else if( y > 0)
   {
       if(y%2==0)
       {
           l=-y;
           r=y-1;
       }
   }
   else
    {
        int tp=abs(y);

        if(tp%2==0)
        {
            l=y;
            r=tp+1;
        }
    }

    if( (l<=x)&&(x<=r) )
        ans="YES";


    cout<<ans<<endl;


}

int main()
{
 ios_base::sync_with_stdio(0);

 int test;

 cin>>test;

 while(test--)
 {
     solve();
 }

 return 0;

}
