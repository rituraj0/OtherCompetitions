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

#define maxn 100009

vector<int> all[maxn];

map< pair<int,int> , bool > done;

int main()
{
 ios_base::sync_with_stdio(0);

 int n,x,y;

 cin>>n;

 for(int i=0;i<n;i++)
 {
     cin>>x>>y;

     pair<int,int> curr=mp(x,y);

     if(done.count(curr)==0)
       {all[y].pb(x);
         done[curr]=true;
       }
       else
       {
//           cout<<x<<"  "<<y<<endl;

       }
 }



 bool cool=true;

 for(int i=0;i<maxn;i++)
 {
       for(int j=1;j<all[i].sz;j++)
       {
            if( all[i][j-1] > all[i][j] )
                 cool=false;

            if( all[i][j-1] +1 != all[i][j] )
                 cool=false;
       }

       if(all[i].sz==1)
       {
           if(all[i][0]!=0)
             cool=false;
       }
 }

 if(!cool)
     cout<<"NO\n";
 else
     cout<<"YES\n";



 return 0;

}
