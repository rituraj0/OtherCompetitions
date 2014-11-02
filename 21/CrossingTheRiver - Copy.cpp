#include<algorithm>
#include<iostream>
#include <sstream>
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



class CrossingTheRiver {
public:


string isItEvenPossible(int ww, int lw, vector <int> bk, int d)
 {
 
 bool dp[110][110];

 memset(dp,0,sizeof(dp));
      
    dp[0][0]=true;
      
 for(int b=0 ; b<bk.size()  ;b++)//after i th width  & current pos = b
 {
      for(int i=1; i<=ww+lw;i++)
        {
          int ov=bk[b];
          
          if( i <= ww)
            ov=ov-d;
            
            if(ov < 0)
             continue;
            
              for(int j=105;j>=0;j--)
                {
                	if(j>0) 
                     if( dp[i-1][j-1] )
                        if( ov==j)
                           dp[i][j]=true;
                           
                     if( dp[i-1][j])      
                       if(ov==j)
                         dp[i][j]=true;
                 }
        }
}

for(int i=1;i<=lw+ww;i++,cout<<endl)
 {
  cout<<i<<"  ...  ";
 for(int j=0;j<105;j++)
   if( dp[i][j])
    cout<<j<<"  ";
}

for(int  i=0;i<=105;i++)
  if( dp[lw+ww][i] )
    return  "POSSIBLE";
    
   return      "IMPOSSIBLE";                                                                                                     
            
	
}

};

#include<ctime>


double test0() {
	int p0 = 3;
	int p1 = 3;
	int t2[] = {3,4,4,5,5, 6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int p1 = 3;
	int t2[] = {3,4,4,5,6, 6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "IMPOSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 5;
	int p1 = 2;
	int t2[] = {4,4,4,4,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 4;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 5;
	int p1 = 5;
	int t2[] = {5,5,5,5,5,5, 2,3,4,4,6, 7, 3, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 5;
	int p1 = 7;
	int t2[] = {6,6,6,6,6,6,6, 6,6,6,6,6,7,8,9,10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 5;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 1;
	int p1 = 1;
	int t2[] = {5,3,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "IMPOSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
