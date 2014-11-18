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

        cout<<diff[i]<<"  ";
  }

    cout<<endl;
  //go next

  int dn=2*n;

  int prev=dn;//started here , time stap type
  int cp=p;

  int op1=0;

  while(dn)
  {
        if( diff[cp]==0)
        {
            cp=(cp+1)%n;
        }
        else
        {
            op1+=abs(prev-dn)+diff[cp];

            cout<<prev<<"  "<<dn<<"  "<<cp<<"  "<<op1<<endl;

            prev=dn;

            diff[cp]=diff[n-1-cp]=0;

            cp=(cp+1)%n;
        }

        dn--;
  }

  cout<<"Now next"<<endl;


    //go Prev

   dn=2*n;
   prev=dn;
   cp=p;

  int op2=0;

  while(dn)
  {
        if( save[cp]==0)
        {
            cp=(cp-1+n)%n;
        }
        else
        {
            op2+=abs(prev-dn)+save[cp];

            cout<<prev<<"  "<<dn<<"  "<<cp<<"  "<<op2<<endl;

            prev=dn;

            save[cp]=save[n-1-cp]=0;

            cp=(cp-1+n)%n;
        }

        dn--;
  }

  cout<<min(op1,op2)<<endl;



 return 0;

}
