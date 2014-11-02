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


int dp1[1005][1005],dp2[1005][1005],dp3[1005][1005],dp4[1005][1005],in[1005][1005];

int main()
{
 ios_base::sync_with_stdio(0);

 fill(dp1,0);fill(dp2,0);fill(dp3,0);fill(dp4,0);

 int n,m;

 cin>>n>>m;

 for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      cin>>in[i][j];

  /* 1 st (1,1) to (n,m) */
  //dp1 from (1,1) to (i,j_)
     for( int i=1;i<=n;i++)
         for(int j=1;j<=m;j++)
           dp1[i][j]=max( dp1[i-1][j], dp1[i][j-1]) + in[i][j];

   //dp2 form (i,j) to (n,m)
      for(int i=n;i>=1;i--)
         for(int j=m;j>=1;j--)
            dp2[i][j]=max(  dp2[i+1][j] , dp2[i][j+1]) + in[i][j];

   /* 2nd player (n,1) to (1,m) */

    //dp3 from (n,1) to (1,m)
      for(int i=n;i>=1;i--)
         for(int j=1;j<=m;j++)
          dp3[i][j]=max(  dp3[i+1][j] , dp3[i][j-1]) + in[i][j];

      //dp4 from (i,j) to (1,m)

      for(int i=1;i<=n;i++)
         for(int j=m;j>=0;j--)
           dp4[i][j]=max( dp4[i-1][j], dp4[i][j+1]) + in[i][j];


      int ans=0;

      for(int i=2;i<n;i++)
         for(int j=2;j<m;j++)
      {
           ans=max(ans, dp1[i][j-1] + dp2[i][j+1]   + dp3[i+1][j]+dp4[i-1][j] );

           ans=max(ans , dp1[i-1][j]+dp2[i+1][j]  + dp3[i][j-1]+dp4[i][j+1] );
      }


     cout<<ans<<endl;

    return 0;

}
