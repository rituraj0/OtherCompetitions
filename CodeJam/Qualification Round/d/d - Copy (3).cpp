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

bool done[10];

void solve( int t)
{
    int n;

    cin>>n;

    vector<double> a(n), b(n);

    for(int i=0;i<n;i++)
         cin>>a[i];

    for(int i=0;i<n;i++)
          cin>>b[i];

    sort(a.bg,a.en);
    sort(b.bg,b.en);

      cout<<"\n\n";

       for(int i=0;i<n;i++)
         cout<<a[i]<<"  ";

      cout<<"\n\n";

    for(int i=0;i<n;i++)
          cout<<b[i]<<"  ";

          cout<<"\n\n";


     int mx=0,my=0;


    //palying Deceitful War

    cout<<"\n\nDirty Game\n\";

     int x=0;


     fill(done,0);

//     cout<<"---\n";

     for(int i=n-1;i>=0;i--)//nomi chance, throws largest valaival
     {

             //if all if smmaler tahn nomi , then kom will throughsmallest one

             cout<<a[i]<<"  ";

              int id=-1;

              for(int j=0;j<n;j++)
                  if(!done[j])
                      if( b[j] > a[i] )
                       {
                        id=j;
                       }

               if(id==-1)//no larget found
               {
                     for(int j=0;j<n;j++)
                          if(!done[j])
                          {
                           done[j]=true;

                           cout<<b[j]<<endl;
                           break;
                           }
                           x++;
               }
              else
              {
                  done[id]=true;

                  cout<<b[id]<<endl;
              }
     }

     mx=max(x,mx);

     //playing fare


     fill(done,0);

     int y=0;

     for(int i=n-1;i>=0;i--)//nomi chanvce, will throw larget first
     {
        int id=-1;


        cout<<a[i]<<"  ";

         for(int j=0;j<n;j++)//kom will throw Smallest that is large enough
              if( !done[j])
                 if( b[j] > a[i] )
                  {
                        id=j;
                        done[id]=true;
                        break;
                   }

           if(id==-1)//unable to find such , so it will through smaalest
             {
               for(int j=0;j<n;j++)
                 if(!done[j])
                   {done[j]=true;
                     break;
                   }

                y++;
             }
     }

     my=max(my,y);




      printf("Case #%d: ",t);
     cout<<mx<<" "<<my<<endl;




}

int main()
{

   int test;


   cin>>test;

   for(int i=1;i<=test;i++)
     solve(i);


 return 0;

}
