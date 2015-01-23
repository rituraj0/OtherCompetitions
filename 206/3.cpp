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

int n;

char in[45][45];

int memo[45][1<<21];
bool done[45][1<<21];

int solve( int x, int mask)
{
    if( x == 2*n - 1 )
         return 0;

    if( done[x][mask])
             return memo[x][mask];

    int ans = -(1<<28); //diff of a-b

    if( x&1 )
    {
        ans = (1<<28);
    }

    memo[x][mask]=ans;
    done[x][mask]=true;



    for(char ch = 'a' ;ch <= 'z' ;ch++)//go to this place
    {
        int new_mask=0;

        for(int j=1;j<=n;j++)
             if( mask & (1<<(j-1) ) )
                {
                    if( in[x+1][j] == ch)
                         new_mask|=(1<<(j-1));

                    if( in[x+1][j+1] == ch)
                          new_mask|=(1<<j);
                }

          if( new_mask )
          {
              int tp = solve(x+1,new_mask);

              if( x & 1)
                 ans=min(ans,tp);
              else
                  ans=max(ans,tp);
          }
    }


    for(int i=1;i<=n;i++)
         if( mask&(1<<(i-1) ) )//ek hi color ha hoga one time
            {
                 if( in[x][i]=='a')
                     ans++;
                 else if( in[x][i] =='b')
                     ans--;

                 break;
            }

     return memo[x][mask]=ans;
}


int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n;

 fill(in,0);
 fill(done,0);

 for(int i=1;i<=n;i++)
 {
     string tp;

     cin>>tp;

     for(int j=1;j<=n;j++)
     {
       in[i+j-1][j]=tp[j-1];
     }
 }

 fill(memo,-1);

 int ans = solve(1,1);

 if( n==1)
 {
     if( in[1][1]=='a')
        ans++;
     else if( in[1][1]=='b')
         ans--;
 }

 if( ans > 0)
 {
     cout<<"FIRST"<<endl;
 }
 else if( ans < 0)
 {
     cout<<"SECOND"<<endl;
 }
 else
 {
     cout<<"DRAW"<<endl;
 }

 return 0;

}
