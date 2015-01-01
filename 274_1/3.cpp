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

ll const mod = 1000000007LL;

ll dp[2][5005];
ll sum[2][5005];

int N,K;
int in[5005];
int lab , st;

vector<int> prev[5005];


int main()
{
 ios_base::sync_with_stdio(0);

 cin>>N>>st>>lab>>K;


 for(int i=1;i<=N;i++)
 {
     vector<int> go;

     for(int j=1;j<=N;j++)//i => j
         //if(i!=j) puhsing iintensley
           if( abs(i-j) < abs(i-lab) )
             go.pb(j);

     int m = sz(go);

     for(int j=0;j<m;j++)
         prev[ go[j] ].pb(i);

 }

/*
 for(int i=1;i<=N;i++)
 {
     cout<<" ** * "<<i<<endl;

     sort( prev[i].bg, prev[i].en);

     for(int j=0;j<sz(prev[i]);j++)
        cout<<prev[i][j]<<" ";

     cout<<endl;
 }
 */

 fill(dp,0);
 fill(sum,0);

 dp[0][st]=1;

 for(int i=1;i<=N;i++)
    sum[0][i] = dp[0][i] + sum[0][i-1];

 for(int i=1;i<=K;i++)
 {
      int curr = ( i %2 > 0);
      int last = 1 - curr;
      fill( dp[curr] , 0 );
      fill(  sum[curr] , 0 );

      for(int j=1;j<=N;j++)
       {
          sum[curr][j]=sum[curr][j-1];

          if( j==lab)
           continue;

           int m = sz( prev[j] );
           int mn = prev[j][0] , mx = prev[j][m-1];

           dp[curr][j]= ( sum[last][mx] - sum[last][mn-1] + mod + mod + mod - dp[last][j] )%mod;

           sum[curr][j] = ( sum[curr][j-1] + dp[curr][j] )%mod;
      }
 }

 int curr =( K % 2 > 0);

  cout<<sum[curr][N]<<endl;


 return 0;

}
