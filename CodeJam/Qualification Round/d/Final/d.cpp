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









int n;







vector<double> A,B;



int dp[2][1005][1005];

bool done[1005];





void process( int t)

{

    cin>>n;



     A.resize(n);

     B.resize(n);



    for(int i=0;i<n;i++)

         cin>>A[i];



    for(int i=0;i<n;i++)

          cin>>B[i];



    sort(A.bg,A.en);

    sort(B.bg,B.en);





    //Unfair section



     for(int i=0;i<n;i++)

         for(int j=0;j<n;j++)

            if(  A[i] > B[j] )

                dp[1][i][j]=1;

             else

                 dp[1][i][j]=0;





     for(int len=2;len<=n;len++)

     {



            int curr=(len&1);

            int prev=1-curr;



                for(int i=0;i<=n-len;i++)

                  for(int j=0;j<=n-len;j++)

                  {

                    int a=i,b=i+len-1;

                    int x=j,y=j+len-1;



                    int ans=0;



                    ans=max( ans, dp[prev][a][x] ) ;

                    ans=max( ans, dp[prev][a][x+1] ) ;

                    ans=max( ans, dp[prev][a+1][x] ) ;

                    ans=max( ans, dp[prev][a+1][x+1] ) ;



                    if( A[a] > B[y] )

                         ans=max(ans, 1 +  dp[prev][a+1][x] );



                    if( A[b] > B[y])

                          ans=max( ans , 1+ dp[prev][a][x]);





                      dp[curr][i][j]=ans;

                }



     }



     //**********Fair Section*********

     //fair game



   int ans=0;



   fill(done,0);



   for(int i=n-1;i>=0;i--)

   {



           int id=-1;



             for(int j=0;j<n;j++)

                 if( !done[j])

                   if( A[i] < B[j])

                 {

                      id=j;

                      break;

                }



                if(id==-1)

                {

                      ans++;



                      for(int j=0;j<n;j++)

                          if( !done[j])

                      {

                          id=j;

                          break;

                      }

                }



                done[id]=true;

   }





    cout<<"Case #"<<t<<": "<<dp[n%2][0][0]<<" "<<ans<<endl;





}



int main()

{

  fi;fo;


   int test;





   cin>>test;



   for(int i=1;i<=test;i++)

     process(i);





 return 0;



}
