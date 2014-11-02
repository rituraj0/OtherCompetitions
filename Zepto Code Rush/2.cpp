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

string in[2005];
int row,col,k;


int main()
{
 ios_base::sync_with_stdio(0);

 cin>>row>>col>>k;

 for(int i=0;i<row;i++)
     cin>>in[i];

  for(int j=0;j<col;j++)
  {
       int ans=0;

        for( int i=0;i<row;i++)
        {
             //right sme , left aane wala
              if( j+i<col)
                  if( in[i][i+j]=='L' )
                    ans++;

              //left me , right jane wala
               if( j-i>=0)
                 if( in[i][j-i]=='R')
                  ans++;

               //niche me , upar aane wala
               if( i+i<row)
                 if( in[i+i][j]=='U')
                   ans++;

               //upar se , niche aaane wala
               //nahi aa pega
        }

        cout<<ans<<" ";
  }

 return 0;

}
