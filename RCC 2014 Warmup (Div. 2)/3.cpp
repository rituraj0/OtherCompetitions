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

bool done[1005][1005];


int main()
{
 ios_base::sync_with_stdio(0);

int n,k;
cin>>n>>k;

int req=n*k;
int aval=( n*(n-1) )/2;

if( aval < req)
{
    cout<<"-1\n";
    return 0;
}

 fill(done,0);

 cout<<n*k<<endl;

 for(int i=1;i<=n;i++)
 {
      int cn=0;

      for(int j=1;j<=n;j++)
          if( (i!=j) && (!done[i][j] )  && (cn<k) )
        {
           cn++;
            done[i][j]=done[j][i]=true;

            cout<<i<<" "<<j<<endl;
        }
 }

 return 0;

}
