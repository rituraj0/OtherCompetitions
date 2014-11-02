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

 string in[3];

 in[0]="qwertyuiop";
 in[1]="asdfghjkl;";
 in[2]="zxcvbnm,./";

 string ans="";

  char d;

  cin>>d;

 string tp;

 cin>>tp;

 for(int k=0;k<sz(tp);k++)
 {
     int x=0,y=0;

     for(int i=0;i<3;i++)
         for(int j=0;j<sz( in[i] );j++ )
           if( tp[k]==in[i][j])
     {
         x=i;
         y=j;
     }

     if(d=='R')
     {
         ans+=in[x][y-1];
     }
     else
        ans+=in[x][y+1];
 }

 cout<<ans<<endl;

 return 0;

}
