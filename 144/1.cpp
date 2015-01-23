//                                                                                                                                                                                                                                                *******Jai Mata Di *******
/*
ID  : WhiteKing
PROG:
LANG: C++
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;

#define df(i,a,b) for(typeof(b) i=a;i>=b;i--)
#define f(i,a,b) for(typeof(b) i=a;i<=b;i++)
#define fill(x,a) memset(x,a,sizeof(x))
#define Clear(x) memset(x,0,sizeof(x))
#define inf 2147000000
#define pb push_back
#define mp make_pair
#define Y second
#define X first

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<string> VS;
typedef pair<int,int> ii;
typedef vector<int> VI;


ifstream ccin(" .in");
ofstream ccout(" .out");


template <class T>
inline void read(T &i)
{
bool minus=false;
char c;
for(c=getchar();(c<'0'||c>'9')&&(c!='-');c=getchar());
if(c=='-')
{minus=true;
c='0';}
for(i=0;c>='0'&&c<='9';c=getchar())
i=(i<<3)+(i<<1) + (c-48);
if(minus)
i=(~i)+1;
}

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


bool favor[105]={false};

int n,fn;
int maxs,mins;//max sure , min sure

struct node{
       int hn;
        vector<int> hl;
        };


vector<node > in;

int findmin( node nd)
{
    vector<int> v=nd.hl;

      int l=v.size(),i;



      int hr=0;
       int nc=0;

       int nfan=n-fn; // fav toatk fav hero , nfan non-favoitarte hero

     for(i=0;i<l;i++)
       { if( favor[v[i] ] ==true )
         hr++;

          if( v[i] ==0 )
           nc++;

         }

         int ftbd=fn-hr;

            int nftbd=nfan-(l-hr-nc); //(l-hr) yaha ke nonfavor hai

         //here min case


            if( nc <=nftbd) //..sara candiadte non-fav ho gaya
              return hr;

              int bacha=nc-nftbd;

                if( bacha < ftbd)
                   return hr+bacha;
                else
                   return hr+ftbd;
}


int findmax( node nd)
{
    vector<int> v=nd.hl;


      int l=v.size(),i;



      int hr=0;
       int nc=0;

       int nfan=n-fn; // fav toatk fav hero , nfan non-favoitarte hero

     for(i=0;i<l;i++)
       { if( favor[v[i] ] ==true )
         hr++;

          if( v[i] ==0 )
           nc++;

         }

         int ftbd=fn-hr;

            int nftbd=nfan-(l-hr-nc); //(l-hr-nc) yaha ke nonfavor hai

         //here max  case



                if( nc < ftbd)
                   return hr+nc;
                else
                   return hr+ftbd;
}




int main()
{


    freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);

   memset( favor,false, sizeof(favor) );

    int i,j,x;

      cin>>n>>fn;

      for(i=1;i<=fn;i++)
       {cin>>x;
        favor[x]=true;
       }

     string s;



       int mov;
       cin>>mov;
    for(i=0;i<mov;i++)
     {
                    cin>>s;
                    int h,x;


                     cin>>h;

                      vector<int> v;

                       for(j=0;j<h;j++)
                        {cin>>x;
                          v.pb(x);
                          }

                          node a;
                          a.hn=h;
                           a.hl=v;


                      in.pb(a);
    }




    int mini[105],maxi[105];

        for(i=0;i<in.size();i++)
         {
                   int mn=findmin( in[i] );
                     int mx=findmax ( in [i] );

                     mini[i]=mn;
                       maxi[i]=mx;

         }




            for(i=0;i<in.size();i++)
             {


                           bool a1=true; // 0 means win to all se

                           for(j=0;j<in.size();j++)
                               if( j != i )
                                if( maxi[j] > mini[i]  )
                                  a1=false;

                             if( a1==true)
                              {    cout<<"0\n";

                                continue;
                              }

                              //now 1 condtonn  harne ki condition
                               a1=false;//nahi haar rah ahai

                             for(j=0;j<in.size();j++)
                               if( mini[j] >  maxi[i] )
                                   a1=true; // le isse har gaya

                                   if(a1==true)
                                    {
                                               cout<<"1\n";
                                               continue;
                                   }

                                   cout<<"2\n";
              }





                  return 0;
                  }



