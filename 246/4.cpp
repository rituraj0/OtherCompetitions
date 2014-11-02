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

int z[100009];
vector<int> cool;//is lenght ka prefix is suufix as well
ll cont[100009];// cont len >=i

void zalgo(string in)
{
  fill(z,0);
  int n=in.sz;
  z[0]=n;
  int l=0,r=0;
  for(int i=1;i<n;i++)
  {
       if( r < i)
       {
            l=r=i;
            while( (r<n) && (in[r-l]==in[r]) )
            {
                r++;
            }
            z[i]=r-l;
            r--;
            continue;
       }
       int b=r-i+1;
       int k=i-l;
       if( z[k]<b)
       {
           z[i]=z[k];
       }
       else
       {
           l=i;
            while( (r<n) && (in[r-l]==in[r]) )
            {
                r++;
            }
            z[i]=r-l;
            r--;
       }
  }
}


int main()
{
 ios_base::sync_with_stdio(0);

 string in;

 cin>>in;

 zalgo(in);

 int n=in.sz;

 fill(cont,0);

 for(int i=0;i<n;i++)
     cont[ z[i] ]++;

 for(int i=1;i<=n;i++)
         cont[i]+=cont[i-1];

 for(int i=0;i<n;i++)
     if( z[i]==n-i)
      cool.pb(n-i);

  sort( cool.bg,cool.en);

  cout<<cool.sz<<endl;

  for(int i=0;i<cool.sz;i++)
  {
        int len=cool[i];
        cout<<len<<" "<<cont[n]-cont[len-1]<<endl;
  }

 return 0;

}
