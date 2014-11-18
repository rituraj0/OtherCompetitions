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

#define pii pair<int,int>
#define maxn (100009)

vector<int> prime[maxn];

vector<pii> allfact[maxn];

ll modPow(ll a, ll x, ll p) {
    //calculates a^x mod p in logarithmic time.
    long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

vector<pii> get_cont( vector<int> A ,int in )
{
    vector<pii> ans;

    for(int i=0;i<sz(A);i++)
    {
        int cn=0;

        while( in %A[i] ==0 )
        {
            cn++;
            in=in/A[i];
         }

         ans.pb( mp(A[i],cn));
    }

    assert(in==1);

    return ans;
}

void init()
{
  bool cool[maxn];

  fill(cool,true);

  cool[0]=cool[1]=false;

  for(int i=2; i<maxn;i++)
    if( cool[i] )
    {
        prime[i].pb(i);

        for(int j=2*i;j<maxn;j+=i)
        {
            cool[j]=false;
            prime[j].pb(i);
        }
    }

  for(int i=1;i<maxn;i++)
        allfact[i] = get_cont(  prime[i] , i);
}



vector<pii> subs(  vector<pii> A, vector<pii> B)
{
    map<int,int> mapa;

    for(int i=0;i<sz(A);i++)
        mapa[ A[i].X ] = A[i].Y ;

    for(int i=0;i<sz(B);i++)//assuming that a%b ==0
         mapa[ B[i].X ] -=  B[i].Y ;

    vector< pii > ans;

    for(int i=0; i<sz(A); i++)
          if(  mapa[ A[i].X ] > 0 )
            ans.pb( mp(A[i].X ,  mapa[ A[i].X ]  ) );

    return ans;

}

vector<pii> adds(  vector<pii> A, vector<pii> B)
{
    map<int,int> mapa;

    for(int i=0;i<sz(A);i++)
        mapa[ A[i].X ] = A[i].Y ;

    for(int i=0;i<sz(B);i++)//assuming that a%b ==0
         mapa[ B[i].X ] +=  B[i].Y ;

    vector< pii > ans;

    for( map<int,int>::iterator it=mapa.begin() ; it !=mapa.end() ; it++)
        ans.pb( mp( it->first , it->second) );

    return ans;

}

void go( vector<pii> in)
{
    for(int i=0;i<sz(in);i++)
     cout<<in[i].X<<"  "<<in[i].Y<<endl;

}

ll get_value( vector<pii> A , ll mod)
{
    ll ans=1;

    for(int i=0;i<sz(A);i++)
    {
        ll tp = modPow( A[i].X , A[i].Y , mod);

        ans=(ans * tp)%mod;
    }

    return ans;
}


void solve()
{
    int  N,Q,R;

    ll M;

    cin>>N>>M>>Q;

    for(int j=1;j<=Q;j++)
    {
            cin>>R;

            vector<pii> up=
    }
}
int main()
{
 ios_base::sync_with_stdio(0);

 init();


 for(int  i=0;i<=110;i++)
 {
     cout<<" ****  "<<i<<"   "<<endl;
     go( allfact[i] );

     cout<<"\n\n";
 }

 cout<<"100/10"<<endl;

 go( subs(allfact[100] , allfact[10]) );

  cout<<endl;

  cout<<get_value( subs(allfact[100] , allfact[10] ) , 1001 )<<endl;
 cout<<"\n\n";

  cout<<"162/9"<<endl;

 go( subs(allfact[162] , allfact[9]));

   cout<<endl;

  cout<<get_value( subs(allfact[162] , allfact[9] ) , 1001 )<<endl;

 cout<<"\n\n";


  go( subs(allfact[16200] , allfact[90]));

   cout<<endl;

  cout<<get_value( subs(allfact[16200] , allfact[90] ) , 100000001 )<<endl;

 cout<<"\n\n";

    cout<<endl;

  cout<<get_value( adds(allfact[16200] , allfact[90] ) , 100000001 )<<endl;

  cout<<"\n\n";

 int test;

 while(test--)
 {
     solve();
 }




 return 0;

}
