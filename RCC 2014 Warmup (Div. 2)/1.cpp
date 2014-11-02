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


int main()
{
 ios_base::sync_with_stdio(0);

 int c,d,n,m;
 int al;

 cin>>c>>d;
 cin>>n>>m;
 cin>>al;

  int mx=(1<<30);

  for(int i=0;i<=10000;i++)
     for(int j=0;j<=10000;j++)
       if( i*n+al+j >=m*n)
        mx=min(mx,c*i+d*j);

  cout<<mx<<endl;

 return 0;

}
