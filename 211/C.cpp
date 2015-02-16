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


vector<char> ans;

string in;

int main()
{
 ios_base::sync_with_stdio(0);

 int prev_cont=0;
 char prev='\0';

 cin>>in;

int  n = sz(in);

int i=0;

 while(i<n)
 {
      int j=i;

      while( (j<n) && (in[i]==in[j]))
        j++;

      int cc = j-i;

      cc=min(cc,2);//max 2 of same char

      if( prev_cont==2)
      {
          cc=1;
      }

      for(int m=0;m<cc;m++)
        ans.pb(in[i]);

      prev= in[i];
      prev_cont=cc;
      i=j;
 }

 for(int i=0;i<sz(ans);i++)
    cout<<ans[i];

 return 0;

}
