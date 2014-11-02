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

 vector<string> all(10);

 all[0]="+------------------------+";
 all[1]="|#.#.#.#.#.#.#.#.#.#.#.|D|)";
 all[2]="|#.#.#.#.#.#.#.#.#.#.#.|.|";
 all[3]="|#.......................|";
 all[4]="|#.#.#.#.#.#.#.#.#.#.#.|.|)";
 all[5]="+------------------------+";

 int k;

 cin>>k;

 for(int s=0;s<k;s++)
 {

         for(int c=0;c<500;c++)
             for(int r=0;r<=5;r++)
         {
               if( c >= sz(all[r]))
                 continue;

               if( all[r][c]=='#')
                {
                 all[r][c]='O';
                  c=10000;
                  break;
                }
         }
 }

 for(int i=0;i<=5;i++)
     cout<<all[i]<<endl;

 return 0;

}
