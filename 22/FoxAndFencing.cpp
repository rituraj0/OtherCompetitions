#include<algorithm>
#include<iomanip> 
#include<iostream>
#include<sstream>
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

#define pb push_back
#define mp make_pair
#define Y second
#define X first

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

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

class FoxAndFencing 
{
public:

string  WhoCanWin(int x, int y, int j, int k, int d) 
{
   if( x + j >=d )
     return  "Ciel";
   else if( x + d <= y +  k )
     return  "Liss";
   else if( (x>y)  && ( 2*y + k < x + j ) )
     return "Ciel";
   else if( (x<y) && (2*x+j < y+ k ) )
     return "Liss";
   else
     return "Draw";     
	
}

};


double test0() {
	int p0 = 1;
	int p1 = 58;
	int p2 = 1;
	int p3 = 58;
	int p4 = 2;
	FoxAndFencing * obj = new FoxAndFencing();
	clock_t start = clock();
	string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Ciel";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 2;
	int p1 = 1;
	int p2 = 1;
	int p3 = 100;
	int p4 = 50;
	FoxAndFencing * obj = new FoxAndFencing();
	clock_t start = clock();
	string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Liss";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 2;
	int p1 = 1;
	int p2 = 1;
	int p3 = 100;
	int p4 = 150;
	FoxAndFencing * obj = new FoxAndFencing();
	clock_t start = clock();
	string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Draw";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 100;
	int p1 = 100;
	int p2 = 100;
	int p3 = 100;
	int p4 = 100000000;
	FoxAndFencing * obj = new FoxAndFencing();
	clock_t start = clock();
	string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Draw";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 100;
	int p1 = 1;
	int p2 = 100;
	int p3 = 1;
	int p4 = 100000000;
	FoxAndFencing * obj = new FoxAndFencing();
	clock_t start = clock();
	string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Ciel";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 100;
	int p1 = 1;
	int p2 = 100;
	int p3 = 250;
	int p4 = 100000000;
	FoxAndFencing * obj = new FoxAndFencing();
	clock_t start = clock();
	string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Draw";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	int p0 = 100;
	int p1 = 1;
	int p2 = 100;
	int p3 = 150;
	int p4 = 100000000;
	FoxAndFencing * obj = new FoxAndFencing();
	clock_t start = clock();
	string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Ciel";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test7() {
	int p0 = 100;
	int p1 = 50;
	int p2 = 100;
	int p3 = 1;
	int p4 = 100000000;
	FoxAndFencing * obj = new FoxAndFencing();
	clock_t start = clock();
	string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Ciel";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test8() {
	int p0 = 100;
	int p1 = 150;
	int p2 = 100;
	int p3 = 1;
	int p4 = 100000000;
	FoxAndFencing * obj = new FoxAndFencing();
	clock_t start = clock();
	string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Draw";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
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
	
	time = test6();
	if (time < 0)
		errors = true;
	
	time = test7();
	if (time < 0)
		errors = true;
	
	time = test8();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
