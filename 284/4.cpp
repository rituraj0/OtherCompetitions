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


double dp[5005][5005];

int main()
{
 ios_base::sync_with_stdio(0);

 int N,T;

 cin>>N>>T;

 fill( dp , 0);

 dp[0][0]=1.0;

 double pr ;
 int  maxi;

 double ans=0;

 for(int i=1;i<=N;i++)
 {
     cin>>pr>>maxi;

     pr=pr/100.0;

     double f=0;
     double last=pow( (1.0-pr),maxi-1.0);

       for(int j=i;j<=T;j++)
       {
           f = f*(1.0-pr) + dp[i-1][j-1];//f is all failures

           if( j >= maxi)
           {
               f-=dp[i-1][j-maxi]*last;
               dp[i][j]=f*pr + dp[i-1][j-maxi]*last;
           }
          else
          {
              dp[i][j]=f*pr;
          }

          ans+=dp[i][j];
       }
 }

 cout << std::fixed<<std::setprecision(10)<<ans<<endl;


 return 0;

}
