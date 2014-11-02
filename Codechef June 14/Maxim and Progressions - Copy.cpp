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

ll dp[110][250];
ll sum[110][250];
ll ab[110][250];
int n;
ll in[200009];
ll cont[110];

#define mod 1000000007

void solve()
{
     fill(cont,0);
     fill(sum,0);
     fill(dp,0);

//     fill(ab,0);

     cin>>n;

     for(int i=1;i<=n;i++)
         cin>>in[i];

         ll ans=n+1;

     for(int i=1;i<=n;i++)
     {
            int curr=in[i];

            for(int d=-99;d<=99;d++)
            {
                dp[curr][d+100]=0;

                int prev=in[i]-d;

                if( (1<=prev) && (prev<=100) )
                {
                     if( sum[prev][d+100]>0)
                       dp[curr][d+100]=sum[prev][d+100]+1;
                     else if( cont[prev] >0)
                        dp[curr][d+100]=cont[prev];
                }

                sum[curr][d+100]=(sum[curr][d+100]+ dp[curr][d+100])%mod;
                ans= ( ans + sum[curr][d+100] )%mod;
            }

//            cout<<i<<"  "<<sum[1][100]<<" "<<dp[1][100]<<endl;

            cont[curr]++;
     }



//     for(int i=1;i<=100;i++)
//          for(int j=-99;j<=99;j++)
//            ans=(ans+ab[i][100+j])%mod;

//         print(ans);

     ll all=1;

     for(int i=1;i<=n;i++)
         all=(all*2)%mod;

     all=(all-ans+mod+mod)%mod;

     cout<<all<<endl;

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
