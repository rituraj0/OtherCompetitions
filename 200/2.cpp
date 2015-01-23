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


stack<char> st;

string in;
int n;

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>in;

 n = sz(in);

 for(int i=0;i<n;i++)
 {
     char curr = in[i];

     if( st.empty() || ( st.top()!=curr))
        st.push(curr);
     else
        st.pop();
 }

 if( st.empty())
    cout<<"Yes";
 else
    cout<<"No";

 return 0;

}
