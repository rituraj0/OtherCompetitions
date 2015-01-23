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


vector< pair<int,string> > in;
vector< string> buck[100];

vector< string  >  ans[100];

int x,a,b,c;

int random( )
{
    return x = ( x*a + b)%c;
}

int main()
{
 ios_base::sync_with_stdio(0);

 fi;fo;

 int n,m;

 cin>>n;

 cin>>x>>a>>b>>c;

  m = n/4;

 for(int i=0;i<n;i++)
 {
     string tp; int sc;

     cin>>tp>>sc;

     in.pb( mp (-sc,tp) );
 }

 sort( in.begin() , in.end() );

 int j=0;

 for(int i=0;i<4;i++)
 {
     int cn=0;

     while( cn < m)
     {
         buck[i].pb( in[j].Y );
         j++;
         cn++;
     }
 }

// for(int i=0;i<4;i++,cout<<endl)
//    for(int j=0;j<sz(buck[i]);j++)
//      cout<<buck[i][j]<<"  ";



 for(int i=0;i<m;i++)
 {
      for(int j=0;j<4;j++)
      {
          int nx = random();

          int cs = sz(buck[j]);

          nx = nx % cs;

        //  cout<<i<<"  "<<j<<" "<<cs<<"  "<<nx<<endl;

          //cout<<

          ans[i].pb( buck[j][nx]  );

          for(int k = nx; k < cs-1; k++ )
            buck[j][k]=buck[j][k+1];

           buck[j].pop_back();
      }
 }

 for(int i=0;i<m;i++)
 {
     cout<<"Group "<<(char)('A'+i)<<":"<<endl;

     for(int j=0;j<4;j++)
        cout<<ans[i][j]<<endl;
 }



 return 0;

}
