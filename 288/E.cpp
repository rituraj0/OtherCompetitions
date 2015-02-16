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


#define maxn 1000
int lf[maxn] , rt[maxn];
int startindex[maxn];

vector<char> ans;

stack<int> st;

int main()
{
 ios_base::sync_with_stdio(0);

 int n;

 cin>>n;

 for(int i=1;i<=2*n;i++)
 {
     cin>>lf[i]>>rt[i];
 }

 int curr = 1;//going to  push this

 int paired = 0 ;

 for(int i=1;i<=2*n;i++)
 {
     if( st.empty() )
     {
         st.push(curr);
         startindex[curr]=i;
         curr++;
         ans.pb('(');
         continue;
     }

     int  topid = st.top();

     int dist = i - startindex[topid];

     if( (lf[topid] <= dist) && ( dist <= rt[topid]) )
     {
            st.pop();
            ans.pb( ')' );
            paired++;
     }
     else
     {
         st.push(curr);
         startindex[curr]=i;
         curr++;
         ans.pb('(');
     }

 }

 if( paired!=n)
 {
     cout<<"IMPOSSIBLE\n";
     return 0;
 }

 for(int i=0;i<sz(ans);i++)
    cout<<ans[i];

 cout<<endl;
 return 0;

}
