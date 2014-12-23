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


string in;
ll a,b;

bool ac[1<<20],bc[1<<20];

int main()
{
 ios_base::sync_with_stdio(0);

 fill(ac,0);
 fill(bc,0);

  cin>>in;

  cin>>a>>b;

  ll prem=0;
  ll pp=1;

  for(int i=sz(in)-1;i>=0;i--)
  {
      ll mul=(10LL*pp)%b;

      if(i==sz(in)-1)
        mul=1;

      //cout<<i<<"  "<<mul<<"  ";

      pp=mul;

      ll crem= ( mul*(in[i]-'0') + prem)%b;

     // cout<<prem<<"  "<<crem<<endl;

      if( crem==0)
        if( in[i]!='0')
       {
           bc[i]=true;

          // cout<<"here we got "<<i<<endl;
       }

      prem=crem;
  }

  //cout<<"Now in A part "<<endl;


  prem = 0;

  for(int i=0;i<sz(in)-1;i++)
  {
      ll crem = ( 10LL*prem + ( in[i]-'0') )%a;

      if( crem %a == 0)
      {
          ac[i]=true;

         // cout<<"Here in second string we have got "<<i<<endl;
      }

      prem=crem%a;
  }

  for(int i=0;i<sz(in)-1;i++)
      if( ac[i] && bc[i+1] )
        {
           cout<<"YES"<<endl;

            cout<<in.substr(0,i+1)<<endl;

            cout<<in.substr(i+1)<<endl;

            return 0;
        }



        cout<<"NO"<<endl;

 return 0;

}
