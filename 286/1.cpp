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

typedef   int us;

us  memo[30005][610];

us id[35000];//len to id
us len[1000];//id to len

vector<us> in;

us n;

us cont[30005];

us solve( us pos  , us len_id )//is pos pe , len prev
{
    if( pos >  in[n-1] )
    {
        return 0;
    }

    if( memo[pos][len_id] !=-1 )
         return memo[pos][len_id];

    memo[pos][len_id] = 0;

    us cl = len[len_id];

    us ans=0;

    if( cl -1 > 0)
    {
        ans=max( ans , solve(pos+cl-1, id[ cl -1] ) );
    }

    ans=max( ans , solve(pos+cl, id[cl] ) );

    ans=max( ans , solve(pos+cl+1, id[cl+1] ));

    ans+=cont[pos];

    return memo[pos][len_id]=ans;

}

int main()
{
 ios_base::sync_with_stdio(0);

 us d;

 cin>>n>>d;

 in.resize(n);

 fill(id,-1);

 us x=0;

 int  dist = d;
 //print(dist);

 for(int dx=-300; dx<=300; dx++)
     if( dist + dx > 0)
     {
          us tp = dist + dx;
          //print(tp);
          id[ tp] = x;
          len[x] = tp;
          x++;
     }

 fill( cont , 0);

 for(us i=0;i<n;i++)
      {
           cin>>in[i];

           cont[ in[i] ]++;
      }

 sort( in.begin() , in.end() );

 fill(memo,-1);

 cout<<solve(d,id[d])<<endl;

 return 0;

}
