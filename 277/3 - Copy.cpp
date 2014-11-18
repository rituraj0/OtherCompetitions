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

int diff[1<<20],save[1<<20];
 string in;

int main()
{
 ios_base::sync_with_stdio(0);

 fill( diff , 63);

 int n,p;

 cin>>n>>p;

 p--;

 cin>>in;

 for(int i=0;i<n;i++)
  {
        int x=in[i]-'a';
        int y=in[n-1-i]-'a';

         if( x > y)
             swap(x,y);

        save[i]=diff[i]=min( y-x , 26-(y-x) );

        //cout<<diff[i]<<"  ";
  }

    //cout<<endl;
  //go next

  int dn=2*n;

  int tp=0;
  int cp=p;

  int op1=0;

  while(dn--)
  {
        if( diff[cp]==0)
        {
            tp++;
            cp=(cp+1)%n;
            continue;
        }
        else
        {
            op1+=tp+diff[cp];
            tp=0;
            diff[cp]=diff[n-1-cp]=0;


            //cout<<cp<<"  "<<op1<<endl;

            cp=(cp+1)%n;
        }
  }

  //cout<<"Now next"<<endl;


    //go Prev

   dn=2*n;

   tp=0;
   cp=p;

  int op2=0;

  while(dn--)
  {
        if( save[cp]==0)
        {
            tp++;
            cp=(cp-1+n)%n;
            continue;
        }
        else
        {
            op2+=tp+save[cp];
            tp=0;
            save[cp]=save[n-1-cp]=0;


            //cout<<cp<<"  "<<op2<<endl;

            cp=(cp-1+n)%n;
        }
  }

  cout<<min(op1,op2)<<endl;



 return 0;

}
