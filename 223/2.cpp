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

bool done[1<<20];
int level;

vector<int> mila;
vector< pair<int, pair<int,int> > > aval[7100];

int solve( int L , int x, int y)
{
     mila.clear();

     while(L<=level)
     {
          for(int i=0;i<aval[L].sz;i++)
          {
              int val=aval[L][i].X;
              int xx=aval[L][i].Y.X;
              int yy=aval[L][i].Y.Y;

              if( (x >yy) || (y<xx) )
                 continue;

              if(! done[val] )
               { done[val]=true;
                 mila.pb(val);
               }
          }

          if(x>1)
          x=x+(32-__builtin_clz(x-1));
          y=y+(32-__builtin_clz(y) );
          L++;
     }

     int ans=mila.sz;

     for(int i=0;i<mila.sz;i++)
         done[ mila[i] ]=false;

     return ans;
}


int main()
{
 ios_base::sync_with_stdio(0);
 fill(done,0);

 int Q;

  cin>>level>>Q;

  int op,L,x,y,val;

  for(int i=1;i<=Q;i++)
  {
       cin>>op;

       if(op==1)
       {
            cin>>L>>x>>y>>val;

            aval[L].pb( mp(val,mp(x,y) ) );

       }
      else
      {
           cin>>L>>x;

           cout<<solve(L,x,x)<<endl;
      }
  }

 return 0;

}
