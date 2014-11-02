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

map< pair<int,int> , pair<int,int> > mapa;

int main()
{
 ios_base::sync_with_stdio(0);
 int n,Q;

 cin>>n>>Q;

 int id,att,val,pr;

 for(int i=1;i<=n;i++)
    {
         cin>>id>>att>>val>>pr;

         if( mapa.count( mp(id,att) )==0 )
            mapa[ mp(id,att) ]=mp(val,pr);
         else
         {
             if( mapa[ mp(id,att)].Y <= pr)
                 mapa[ mp(id,att) ]=mp(val,pr);
         }
    }

    int a,b;

  for(int i=1;i<=Q;i++)
  {
      cin>>a>>b;
      cout<<mapa[ mp(a,b)].X<<endl;
  }



 return 0;

}
