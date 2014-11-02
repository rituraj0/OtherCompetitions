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

int in[6][6];

vector<int> curr;

int solve( )
{
    queue<int> tp;

    for(int i=0;i<curr.sz;i++)
         tp.push( curr[i]);

     int a=0;

    while( tp.sz > 1)
    {
        vector<int> tp1;

          queue<int> tp2=tp;

          while( tp2.size() )
           {
               tp1.pb( tp2.front() );
               tp2.pop();
           }

        for(int i=1;i<tp1.sz;i+=2)
             a+=in[ tp1[i-1] ][ tp1[i] ] + in[ tp1[i] ][ tp1[i-1] ];

          tp.pop();
    }

    return a;
}




int main()
{
 ios_base::sync_with_stdio(0);

 for(int i=1;i<6;i++)
     for(int j=1;j<6;j++)
      cin>>in[i][j];


 for(int i=1;i<6;i++)
     curr.pb(i);

  int ans=0;

  do
  {
      int tp=solve();

      ans=max( ans , tp);

  }while( next_permutation(curr.bg,curr.en) ) ;

  cout<<ans<<endl;

 return 0;

}
