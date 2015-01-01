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

#define maxn 100009
int part[maxn];
int side[maxn];
int mask[maxn];
int in[maxn];

int root( int x)
{
    if( part[x] == x )
         return x;

    return part[x]=root( part[x] );
}

map< int,int> pos;
int N;
int a,b;

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>N>>a>>b;


 fill(side,0);


 for(int i=1;i<=N;i++)
 {
     cin>>in[i];
     pos[ in[i] ]=i;
     part[i]=i;
 }

 for(int i=1;i<=N;i++)
 {
      if( pos.count(a-in[i]))
      {
          int id= pos[ a-in[i] ];
          part[ root(id) ]  = root( i );

          side[ i ]=1;
      }

      if( pos.count(b-in[i]))
      {
          int id= pos[ b-in[i] ];
          part[ root(id) ]  = root( i );

          side[ i ]= side[i]|2;
      }

      mask[i]=3;
 }

 for(int i=1;i<=N;i++)
 {
     mask[ root(i) ]&=side[i];
 }

 for(int i=1;i<=N;i++)
     if( mask[i]==0)
     {
       cout<<"NO\n";
       return 0;
     }

 cout<<"YES\n";

 for(int i=1;i<=N;i++)
 {
      int pside = mask [ root(i) ];

      if(pside > 2)
        pside--;

      cout<<pside-1<<" ";
 }


 return 0;

}
