#include <bits/stdc++.h>
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
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s)
 {
  int n = s.length();
  if (n == 0) return "^$";

  string ret(2*n+3,'^');

  ret[0]='^';

  for (int i = 1; i <=2*n; i++)
      if(i&1)
         ret[i]='#';
      else
          ret[i]=s[(i/2)-1];

    ret[2*n+1]='#';
    ret[2*n+2]='#';

    return ret;
}

string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)

    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;

    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }

  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  delete[] P;

  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}

string add( int n , int p)
{

    char ans[1009];
    fill(ans,0);

    if( p==1)
    {
        for(int i=0;i<n;i++)
             ans[i]='a';

        return ans;
    }

    if(p==2)
    {
        for(int i=0;i<n;i++)
              if( i&1)
                ans[i]='b';
              else
                 ans[i]='a';

              return ans;
    }

    for(int i=0;i<n;i++)
          if(i%3==0)
             ans[i]='a';
         else if( i%3==1)
                ans[i]='b';
         else
                ans[i]='c';

         return ans;

}

int main()
{
 ios_base::sync_with_stdio(0);

  int n,p;

  string in;

  cin>>n>>p;

  cin>>in;

  string ans="NO";

 for(int i=0;i<n;i++)
    for(char ch=in[i]+1;ch<='a'+p-1;ch++)
    {
     string tp=in;

     tp[i]=ch;
     string ad=add(n-1-i,p);

     tp=tp.substr(0,i+1)+ad;

     string ret=longestPalindrome(tp);

     if( (int)ret.sz>=2)
        continue;

     if(ans=="NO")
          ans=tp;
     else
         ans=min(ans,tp);
 }

 //if u r inrroduung new charte , then its

 cout<<ans<<endl;


 return 0;

}
