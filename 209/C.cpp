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

bool cantake = true;
ll x;

multiset<ll> st;

ll get_next()
{
    if( sz(st)==1)
    {
        cantake=false;
        return *st.begin();
    }
    if( sz(st) < x)
    {
         cantake = false;
          return *st.begin();
    }

    if( *st.begin()==0)
    {
        cantake=false;
        return 0;
    }

    ll curr= *st.begin() ; st.erase(st.begin());

    ll done = 1;

    while( (done < x) && (*st.begin()==curr) )
    {
        st.erase(st.begin());
        done++;
    }

    if( done < x)
    {
        cantake=false;
        return curr;
    }

    st.insert(1);

    return curr;

}

int main()
{
 ios_base::sync_with_stdio(0);

 int n;
 ll x,a;

 cin>>n>>x;

 for(int i=0;i<n;i++)
 {
     cin>>a;
     st.insert(a);
 }

 ll ans=0;

 while( cantake )
 {
     ans+=get_next();
 }

 cout<<ans<<endl;

 return 0;

}
