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

#define maxn 200009

int pos[maxn][2];// opos of i th win of player j
int cont[maxn][2];//all win of j th player at point i

int in[maxn];

int n;

vector< pair<int,int> > ans;

int main()
{
 ios_base::sync_with_stdio(0);

 for(int i=0;i<maxn;i++)
 {
     pos[i][0]=pos[i][1]=maxn;
 }

 cin>>n;

  cont[0][0]=cont[0][1]=0;

 for(int i=1;i<=n;i++)
 {
     cin>>in[i];
     in[i]--;

     cont[i][0]=cont[i-1][0];
     cont[i][1]=cont[i-1][1];

     cont[i][ in[i] ]++;

     pos[ cont[i][ in[i] ] ][ in[i] ]=i;

 }

 for(int t=1;t<=n;t++)
 {
     bool mila=false;

     int tp[2]; tp[0]=tp[1]=0;//current count of points

     for(int j=0;j<=n;)
     {
         if( j == n)
            {
                mila = true;
                break;
            }

         int id0= pos[ cont[j][0] + t ][0];

         int id1= pos[ cont[j][1] + t ][1];

         j = min( id0 , id1);

         if( id0 < id1)
             tp[0]++;
         else
            tp[1]++;
     }

    if( mila )
         if( tp[ in[n] ] > tp[ 1 - in[n] ] )
            {
                ans.pb( mp( max(tp[0],tp[1]) , t ) );
            }
 }

 sort( ans.begin(),ans.end());

 cout<<sz(ans)<<endl;

 for(int i=0;i<sz(ans);i++)
    cout<<ans[i].X<<" "<<ans[i].Y<<endl;

 return 0;

}
