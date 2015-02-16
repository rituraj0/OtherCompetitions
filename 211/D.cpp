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

vector<ll>  price,aval;
ll shared;
int cycle ;
int stud;

bool  cool( int len )
{
     ll rem = shared;

     //take len cheapest cycle
     // and len richest cycles
     for(int i=0;i<len;i++)//try to but tis cycle
     {
         int j = len -1-i;

         if( price[i] <= rem + aval[j] )
         {
             rem-=max(0LL , price[i]-aval[j] );
         }
         else
         {
             return false;
         }
     }

    // print(rem);

     return true;
}

ll find_mini( int len )
{
    //buy len cheapest cycle

    //sum of  len cheapest cycle - toral shared memony
    ll ans=0;
    for(int i=0 ;i <len;i++)
        ans+=price[i];

    return max(0LL,ans-shared) ;
}

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>stud>>cycle>>shared;

 price.resize(cycle);
 aval.resize(stud);

 for(int i=0;i<stud;i++ )
    cin>>aval[i];

 for(int i=0;i<cycle;i++)
    cin>>price[i];


 sort( aval.begin() , aval.end() );
 reverse( aval.begin() , aval.end() );

 sort( price.begin() , price.end() );

 int len = 0 ;

 int can = min( stud , cycle);

  int  lo =0 , hi =can;

  while( lo < hi )
  {
      int mid = (lo+hi+1)/2;

      if( cool(mid))
      {
          lo=mid;
      }
      else
      {
          hi=mid-1;
      }
  }

 cout<<lo<<" "<<find_mini(lo)<<endl;

 return 0;

}
