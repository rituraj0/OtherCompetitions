#include <bits/stdc++.h>
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
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

bool cool( string a, string b)
{
      for(int i=0;i<a.sz;i++)
      {
        if( ( a[i]=='?') || (b[i]=='?') )
           continue;

         if( a[i]!=b[i])
          return false;
      }

      return true;
}

int main()
{
 ios_base::sync_with_stdio(0);

 string in;

 cin>>in;

 int k;

 cin>>k;

 for(int i=0;i<k;i++)
     in+='?';

 int ans=0;

 int n=in.sz;

 for(int i=0;i<n;i++)
     for(int len=1;len<=n;len++)
        {
         if( i + 2*len -1>=n)
             continue;



          string a=in.substr(i,len);
          string b=in.substr(i+len,len);

//            cout<<i<<"  "<<len<<"  "<<a<<"  "<<b<<"  "<<cool(a,b)<<endl;

          if( cool(a,b) )
              ans=max(ans,2*len);
        }


        cout<<ans<<endl;

 return 0;

}
