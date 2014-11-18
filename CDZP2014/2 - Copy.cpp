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


int main()
{
 ios_base::sync_with_stdio(0);

 int n;
 int val;

 int in[150][150];

 cin>>n>>val;


for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>in[i][j];


 int x=1,y=n;

 while( (x <=n ) && ( y >=1))
 {
     if( in[x][y]== val)
     {
         cout<<"YES"<<endl;
         return 0;
     }
    else if( in[x][y] > val)
    {
        y--;
    }
    else
    {
        x++;
    }
 }

 cout<<"NO\n";

}
