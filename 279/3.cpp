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

#define maxn  100009

string in[maxn];

string solve( string curr , string prev)
{
    int cs=sz(curr) , ps=sz(prev);

    if( cs < ps )
         return "*";

    if( cs > ps )
    {
         for(int i=1;i<cs;i++)
             if( curr[i]=='?')
                curr[i]='0';

         if( curr[0]=='?')
             curr[0]='1';

         return curr;
    }

    for(int pos = cs; pos >=0; pos--)//increare value of curr[pos] by prev[pos] + 1
    {
         string temp=curr;

         if( (pos < cs) && (prev[pos] =='9') )
            continue;

         if( (pos < cs) && (temp[pos]=='?') )
            temp[pos]=prev[pos] + 1;

         for(int i=pos+1;i<cs;i++)
             if( temp[i]=='?')
               temp[i]='0';

         bool ans=true;

         for(int i=0;i<pos;i++)
             if( temp[i]=='?')
                temp[i]=prev[i];
             else if( temp [i] != prev[i])
                 ans=false;

         if(!ans)
            continue;

         if( temp > prev )
            return temp;
    }


    return "*";
}

int main()
{
 ios_base::sync_with_stdio(0);

 int n;

 cin>>n;

 in[0]="0";

 for(int i=1;i<=n;i++)
    cin>>in[i];

  for(int i=1;i<=n;i++)
  {
      string curr=solve( in[i],in[i-1]);

      if( curr =="*")
      {
          cout<<"NO"<<endl;
          return 0;
      }

      in[i]=curr;
  }

  cout<<"YES"<<endl;

  for(int i=1;i<=n;i++)
    cout<<in[i]<<endl;

 return 0;

}
