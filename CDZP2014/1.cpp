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


//int n;
//
//set<string> all;
//
//
//string solve( int curr)
//{
//   if( curr==n)
//   {
//        return "";
//   }
//
//
//}
void solve(int test)
{
    string in;
     cin>>in;

     int n=sz(in);
     in="$"+in;

     ll dp[15];

      dp[0]=1;

     for(int i=1;i<=n;i++)
     {
         ll tp=0;

           if( in[i]!='0')
             tp=dp[i-1];


            if( i > 1)
                  if( in[i-1]=='1' || in[i-1]=='2')
                      if( in[i] <='6')
                        tp+=dp[i-2];

          dp[i]=tp;
     }

    if(test!=0)
     cout<<dp[n]<<endl;
     else
        cout<<dp[n];

}

int main()
{

 int test;

 cin>>test;

 while(test--)
 {
     solve(test);
 }

 return 0;

}
