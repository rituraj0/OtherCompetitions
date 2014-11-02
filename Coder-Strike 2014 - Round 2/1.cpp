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
 int n,m,mx,mn;

 cin>>n>>m>>mn>>mx;

 int a=-200,b=200;

 for(int i=0;i<m;i++)
 {
     int x;
     cin>>x;

     a=max(a,x);
     b=min(b,x);
 }

  for(int mask=0;mask<4;mask++)
  {
       if( __builtin_popcount(mask) <= n-m)
       {
                int ta=a,tb=b;

               if( mask &1 )
                  ta=max(ta,mx);

                if( mask&2)
                   tb=min(tb,mn);

                if(ta==mx && tb==mn)
                {
                    cout<<"Correct\n";
                    return 0;
                }

      }

  }

  cout<<"Incorrect\n";

 return 0;

}
