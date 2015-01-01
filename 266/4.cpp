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

ll const mod =  1000000007LL;

void  add ( ll &x, ll y)
{
   x=x+y;
   x=x%mod;
}
int n,h;

int in[2010];

ll dp[2050][2050];


int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n>>h;

 for(int i=1;i<=n;i++)
    cin>>in[i];

 fill(dp,0);

 if( in[1]==h)//not any segment
  dp[1][0]=1;

 if( in[1] +1 == h)//[] wala only one lenght
    dp[1][0]=1;

 if( in[1] +1 == h)//start an new segment here
     dp[1][1]=1;

  for(int i=2;i<=n;i++)
     for(int op=0;op<2010;op++)
    {
        if( in[i] + op == h)
        {
             add( dp[i][op] , dp[i-1][op]);//no change

            if( op > 0)
              add( dp[i][op] , dp[i-1][op-1]);//start a  new

             //cant do one lenght [] , bcz already op is opened and it wil increase by 1
        }

        if( in[i] + op + 1 == h)
        {
            add( dp[i][op] , dp[i-1][op+1]*(op+1) ); //close any one of op

             add( dp[i][op] , dp[i-1][op] );//one lengtht [] segment

            if( op > 0)
             add( dp[i][op] , dp[i-1][op]*op );//first open one  before [4 and close any of prev opened ] e.g. [4]
        }

    }


    cout<<dp[n][0]<<endl;



 return 0;

}
