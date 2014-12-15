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

 int life_mon,atk_mon,def_mon;
 int life_yong,atk_yang,def_yang;

 int hc,ac,dc;

 cin>>life_yong>>atk_yang>>def_yang;

 cin>>life_mon>>atk_mon>>def_mon;

 cin>>hc>>ac>>dc;

 int ans=(1<<28);

 for(int h=0;h<=10500;h++)
    for(int a=0;a<=210;a++)
     for(int d=0;d<=210;d++)
        {
            int cost=h*hc + a*ac + d*dc;

            int curr_life = life_yong + h;
            int curr_atk =  atk_yang + a;
            int curr_def =  def_yang + d;

            int dec_mon = max(0, curr_atk - def_mon );

            if( dec_mon == 0 )
                continue;

            int dec_yang = max( 0 , atk_mon - curr_def );

            if( dec_yang == 0 )
            {
                ans=min( ans , cost);
                continue;
            }

            //number of chance monyster wil survive
            int num_mon = ( life_mon +  dec_mon-1)/dec_mon;

            //number of yang will curvide

            int num_yang= ( curr_life + dec_yang -1)/dec_yang;

            if( num_mon < num_yang )
            {
               ans=min( ans , cost);
            }

        }

 cout<<ans<<endl;

 return 0;

}
