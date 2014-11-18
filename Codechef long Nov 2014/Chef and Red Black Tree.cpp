#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
#define bg begin()
#define en end()
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

string tost( int in)
{
   string ans(32,'0');

   int id=100;

   for(int i=0;i<=31;i++)
     if( in & (1<<i))
       { ans[31-i]='1';
        id=min(id,31-i);
       }

     return ans.substr(id);
}


string parent( string a , string b)//asuuuming that a< b
{
 //find logest coomn prefix

 int id=0;

 for(int i=0;i<min( sz(a) , sz(b) ) ;i++)
     if( a[i]!=b[i])
      {
        break;
      }
      else
      {
          id++;
      }

   return a.substr(0,id);
}

inline int dist(string a, string b)//assuming that one of them is (1< b) and a is parent of b parent
{
   return ( sz(b)-sz(a));
}

inline int level( string a)
{
    return sz(a);
}

int main()
{
// for(int i=1;i<44;i++)
//    cout<<"ans is "<<tost(i)<<" \n ";

   int x,y,a,b;

   char rootcolor='b';//1 for

   int Q;

   cin>>Q;

   string op;

   while(Q--)
   {

       cin>>op;

       if(op=="Qi")
       {
           if( rootcolor=='b')
             rootcolor='r';
           else
            rootcolor='b';

           continue;
       }

        cin>>a>>b;

        x=min(a,b);
        y=max(a,b);

        string sx=tost(x);
        string sy=tost(y);

        string px=parent(sx,sy);

        int d1=dist(px,sx);
        int d2=dist(px,sy);
        int td=d1+d2+1;

        //cout<<sx<<"  "<<sy<<"  "<<px<<"  "<<d1<<"  "<<d2<<"  "<<d1+d2<<endl;

        int rc=0,bc=0;

        if( level(sx)&1)
        {
                if( rootcolor=='b')
                {
                    bc=(td+1)/2;
                    rc=td/2;
                }
               else
               {
                    bc=(td)/2;
                    rc=(td+1)/2;
               }
        }
        else
        {
              if( rootcolor=='r')
                {
                    bc=(td+1)/2;
                    rc=td/2;
                }
               else
               {
                    bc=(td)/2;
                    rc=(td+1)/2;
               }
        }

        if( op=="Qb")
            cout<<bc<<endl;
        else
            cout<<rc<<endl;

   }



 return 0;

}
