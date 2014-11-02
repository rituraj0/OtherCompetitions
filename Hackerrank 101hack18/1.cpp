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

string  solve()
{
     int n;

     cin>>n;

     vector<string> in(n);

     for(int i=0;i<n;i++)
     {
          cin>>in[i];

          sort( in[i].bg,in[i].en);
     }


     //check for all rcols

     for(int j=0;j<n;j++)//for every col
     {
         for(int i=0;i<n-1;i++)
              if( in[i][j] > in[i+1][j])
                return "NO";
     }

   return "YES";
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
