#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz size()
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}


/*Solution code starts here */

ll solve (ll bc , ll aval)
{
      ll ex=aval%bc;
      ll cs=aval/bc;

      ll ans=0;

      ans+=(bc-ex)*(cs)*(cs);
      ans+=(ex)*(cs+1)*(cs+1);
      return ans;

}


string  output;

void write( int st , int len , char ch)
{
        for(int i=0;i<len;i++)
              output[st+i]=ch;
}

void draw (char ac , vector<int> a , char bc ,vector<int> b, int pos  )
{
      for(int i=0;i<a.size();i++)
      {
            write( pos , a[i] , ac );
            pos+=a[i];

            write( pos , b[i] , bc );
            pos+=b[i];
      }

}

int main()
{
 ios_base::sync_with_stdio(0);

 ll a,b;

 cin>>a>>b;

 if(a==0)
 {
     cout<<-1*b*b<<endl;

     string tp=string(b,'x');
     cout<<tp<<endl;
     return 0;
 }

 if(b==0)
 {
     cout<<a*a<<endl;
     string tp=string(a,'o');
     cout<<tp<<endl;
     return 0;
 }

  ll ans=-(1LL<<60);

  int fa=-1,fb=-1;

 for(int ac=1;ac<=a;ac++)
 {
       ll asum=(ac-1); //sab ek ek wale
           asum+=(a-(ac-1) )*(a- (ac-1) );

         for(ll bc=ac-1; bc <= ac+1; bc++ )
         {
              if( bc < 1)
                 continue;

              if( bc > b)
                 continue;

              ll bsum=solve(bc,b)   ;

              if( asum - bsum > ans)
              {
                  ans=asum-bsum;
                  fa=ac;
                  fb=bc;
              }
         }

 }


 vector<int> as,bs;

  for(int i=1;i<=fa-1;i++)
      as.pb( 1 );

    as.pb( a-(fa-1) );

    //now condtruct B

      ll ex=b%fb;
      ll cs=b/fb;


//      ans+=(bc-ex)*(cs)*(cs);
//      ans+=(ex)*(cs+1)*(cs+1);

        for(int i=0;i<fb-ex;i++)
              bs.pb(  cs  );

        for(int i=0;i<ex;i++)
              bs.pb( cs+1 );


       string tp=string( a+b , '.' );
       output=tp;


       int curr=0;

       if( as.size() > bs.size() )
        {

            write(curr,as[ as.size() -1] ,'o' );

            curr+=as[ as.size()-1];

            as.pop_back();

            draw( 'x' , bs , 'o' , as , curr);
       }
       else if( as.size() < bs.size() )
       {
            write( curr , bs[ bs.size() -1 ] , 'x' );

            curr+=bs[ bs.size() -1];
            bs.pop_back();

            draw('o' , as , 'x' , bs,curr);
       }
      else
      {
           draw('o' , as , 'x' ,bs,0);
      }



   cout<<ans<<endl;
   cout<<output<<endl;


 return 0;

}
