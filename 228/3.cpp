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


int cont[200];

int next( int len)
{
      for(int i=0;i<105;i++)
           if( cont[i] > 0)
              if( i >=len )
                 return i;

        return -1;
}

int main()
{
 ios_base::sync_with_stdio(0);

 int n;

 int in[200];

 cin>>n;

 fill(cont,0);

 for(int i=0;i<n;i++)
    {
       cin>>in[i];
       cont[ in[i] ]++;
    }

   int ans=0;

   int done=0;

   while(1)
   {
        int len=0;

          while(1)
          {
              int tp=next(len);

              if(tp==-1)
                 break;

//                 cout<<tp<<"  ";

              len++;
              cont[tp]--;
              done++;
          }

          ans++;
//          cout<<"   done is "<<done<<"\n";

          if(done==n)
             break;
   }


 cout<<ans<<endl;


 return 0;

}
