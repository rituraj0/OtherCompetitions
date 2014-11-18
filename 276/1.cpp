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


string tost( ll in)
{
    if(in==0)
        return "0";

    string ans="";

    while(in>0)
    {
        if(in&1)
            ans+="1";
        else
            ans+="0";

        in=in/2LL;
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

ll toll( string in)
{
    ll ans=0;

    int n=sz(in);

    for(int i=0;i<n;i++)
    {
        ans=ans*2LL;

        if(in[i]=='1')
            ans+=1;
    }

    return ans;
}

ll solve( ll a, ll b)
{

    if(a == b)
    {
        return a;
    }
    string A=tost(a),B=tost(b);

    ll ans=(1e18)+10;
    ll cont=-1;

    if( __builtin_popcountll(a) > cont )
    {
        cont = __builtin_popcountll(a);
        ans = a;
    }

    int al=sz(A),bl=sz(B);

    if( al < bl)
    {
        int len=bl-1;

        if(  len > cont)
        {
            ans=(1LL<<len)-1;
            cont=len;
        }
    }

    if( al == bl)
    {
        int id=0;

        for(int i=0;i<al;i++)
             if( A[i] < B[i])
                {
                    id=i;
                    break;
                }

        // what if both are equal , habdles in begining of this function

        ll prev=0;

        for(int i=0;i<=id;i++)
        {
            prev=prev*2LL;

            if( A[i]== '1')
            {
               prev++;
            }

        }

        for(int i=id+1;i<al;i++)
        {
            prev=2*prev;
            prev++;
        }

        if( __builtin_popcountll(prev) > cont )
        {
            cont = __builtin_popcountll(prev);
            ans = prev;
        }
    }

    //Now sewrahci

   if( __builtin_popcountll(b) > cont )
    {
        cont = __builtin_popcountll(b);
        ans = b;
    }

    return ans;
}
int main()
{
 ios_base::sync_with_stdio(0);

    ll a,b;

    int test;

    cin>>test;

    while(test--)
    {
        cin>>a>>b;

        cout<<solve(a,b)<<endl;
    }

 return 0;

}
