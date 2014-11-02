#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
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

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}


/*Solution code starts here */


int main()
{
 ios_base::sync_with_stdio(0);

 int n,k,w;
 string in;

 cin>>n>>k>>w;

 cin>>in;

 int all1[100009] , aval[100009];

 fill(all1,0);
 fill(aval,0);


   in="$"+in;

   for(int i=1;i<=n;i++)
      all1[i]=all1[i-1]+(in[i]=='1');

   for(int r=1;r<=n;r++)
   {
         aval[r]=(in[r]=='1');

         if(r-k>=0)
             aval[r]+=aval[r-k];

//             cout<<aval[r]<<" . ";
   }


   for(int i=0;i<w;i++)
   {
        int l,r;

        cin>>l>>r;

        int a1=all1[r]-all1[l-1];

        int ans=0;

        //fixing odd pos
        int r1=(r-l+1)/k;//chahia
        ans+=r1-(aval[r]-aval[l-1]);//0 to 1

//        print(a1);print(r1);print(ans);

        //now genral positions shud all be zero

        int ex=a1-(aval[r]-aval[l-1]);//itna extra  at unwanted pos.

        ans+=ex;

//        print(ex) ; print(ans);

        cout<<ans<<endl;

   }



 return 0;

}
