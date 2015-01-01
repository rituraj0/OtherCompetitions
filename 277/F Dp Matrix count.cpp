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


ll memo[505][505];
ll mod;
int N;

ll solve( int  zero , int one )
{
    int two = N - zero - one;

    if( two == N )
    {
      //  cout<<zero<<" _ "<<one<<endl;
         return 1LL;
    }

    if( memo[zero][one] != -1)
         return memo[zero][one];

    ll ans=0;

    if( zero > 1)
    {
        ll mul=zero*(zero-1)/2LL;

        ans = (ans + solve( zero -2 , one + 2 )*mul )%mod;
    }

    if( one > 1)
    {
         ll mul = one * (one -1 )/2LL;

         ans= (ans + solve( zero , one -2 )*mul )%mod;
    }

    if( (one > 0) && (zero > 0 ))
    {
        ll mul =one *zero;

        ans = ( ans + solve(  zero -1 , one )*mul )%mod; // 011 =>101
    }

   // cout<<zero<<"  "<<one<<"  "<<ans<<endl;
    return memo[zero][one]=ans;
}

 string in[505];

int main()
{

    int m;

    cin>>N>>m>>mod;

    for(int i=0;i<m;i++)
        cin>>in[i];

    int zero=0, one =0;

    for(int i=0;i<N;i++)
    {
        int tp=0;

        for(int j=0;j<m;j++)
             if( in[j][i]=='1')
              tp++;

        if( tp == 0)
             zero++;
        else if( tp ==1)
             one++;
    }



    fill( memo , -1 );

    //cout<<zero<<"  "<<one<<endl;

    cout<<solve(zero , one )<<endl;

    return 0;

}
