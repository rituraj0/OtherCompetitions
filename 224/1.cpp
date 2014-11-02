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

int n;
vector<int> in;


int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n;

 in.resize(n);


 for(int i=0;i<n;i++)
     cin>>in[i];

    sort( in.bg,in.en);

     if(n==1)
     {
        cout<<"-1\n";
        return 0;
     }

     //n==2 wale case me 3 rakh sakte ho

     if(n==2)
     {
         int d=in[1]-in[0];

         vector<int> ans;
         ans.pb(in[0]-d);
         ans.pb(in[1]+d);

         if(d%2==0)
             ans.pb( in[0]+d/2);

               sort(ans.begin(),ans.end());
                ans.erase(unique(ans.begin(),ans.end()),ans.end());

         cout<<ans.sz<<endl;

          for(int i=0;i<ans.sz;i++)
             cout<<ans[i]<<" ";

          return 0;
     }


  vector<int> all;

  for(int i=1;i<n;i++)
     all.pb( in[i]-in[i-1] );

     vector<int> save=all;

     sort(all.begin(),all.end());
   all.erase(unique(all.begin(),all.end()),all.end());

  if( all.sz > 2)
   {
        cout<<"0\n";
        return 0;
   }

   if(all.sz==2)
   {
        if( all[0]*2!=all[1])
        {
            cout<<"0\n"; return 0;
        }

        int cn=0;

        for(int i=0;i<save.sz;i++)
             if( save[i]==all[1])
              cn++;

        if( cn > 1)
        {
                       cout<<"0\n"; return 0;
        }

        int d=all[0];

         int ans;

         for(int i=1;i<n;i++)
              if( in[i]-in[i-1] > d)
                 ans=in[i]-d;

         cout<<"1\n"<<ans<<endl;
         return 0;
   }

   int d=all[0];

   vector<int> ans;
   ans.pb( in[0]-d) ; ans.pb( in[n-1]+d);

   sort(ans.begin(),ans.end());
   ans.erase(unique(ans.begin(),ans.end()),ans.end());

    cout<<ans.sz<<endl;

    for(int i=0;i<ans.sz;i++)
       cout<<ans[i]<<" ";

    return 0;

}
