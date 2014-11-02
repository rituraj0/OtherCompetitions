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

int n;

int cn=0;

map<string,bool> mapa;

void solve( string in , int id)//done till in , we
{
    if(id==0)
    {
        if( mapa.count(in))
             cn=cn-100000;

        mapa[in]=true;
        cout<<in<<endl;
        cn++;
        return;
    }

    //swalp in[id-1] .. in[0]  & roll

    map<char,bool>  done;

    char last='$';//
    for(int i=id;i>=0;i--)
        if( done.count(in[i]) ==0 )
         {
           done[ in[i] ]=true;
           swap( in[i] , in[id]);

           solve(in,id-1);

           swap( in[i] , in[id]);
         }


}

int main()
{
  string in;
  cin>>in;
  sort(in.begin(),in.end());
  n=sz(in);

  solve(in,n-1);

  cout<<cn<<endl;

  return 0;


}
