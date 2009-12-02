#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

class Mixture
{ 
public: 
  double mix(vector <int> mixture, vector <string> availableMixtures);
   
  // BEGIN CUT HERE
public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 0 0 1","0 1 0 2","0 0 1 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 14.0; verify_case(0, Arg2, mix(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 0 0 1","0 1 0 2","0 0 1 3","2 2 2 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 10.0; verify_case(1, Arg2, mix(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10 9 9 9 9 9 9 9 9 10 0",
 "0 10 9 9 9 9 9 9 9 0 0",
 "0 0 10 9 9 9 9 9 9 0 0",
 "0 0 0 10 9 9 9 9 9 0 0",
 "0 0 0 0 10 9 9 9 9 0 0",
 "0 0 0 0 0 10 9 9 9 0 0",
 "0 0 0 0 0 0 10 9 9 0 0",
 "0 0 0 0 0 0 0 10 9 0 0",
 "0 0 0 0 0 0 0 0 10 1 0",
 "0 0 0 0 0 0 0 0 0 10 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(2, Arg2, mix(Arg0, Arg1)); }

  void test_case_3() {
    int Arr0[] = {7,7,8,10};
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"9 0 4 8 4",
		     "8 8 9 0 1",
		     "0 10 3 10 7",
		     "10 2 2 0 1",
		     "8 9 10 2 6",
		     "1 2 5 8 8",
		     "4 7 8 9 6",
		     "2 10 6 8 10",
		     "6 3 9 7 1",
		     "3 6 9 9 1"};
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    double Arg2 = 3.5855425945563804; verify_case(3, Arg2, mix(Arg0, Arg1));
  }

  void test_case_4() {
    int Arr0[] = {7, 6, 9, 10, 10, 4, 6};
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] =   {"2 8 1 6 10 5 5 0",
		       "1 7 4 3 6 5 7 8",
		       "10 4 6 0 1 2 2 6",
		       "3 0 9 8 6 4 8 8",
		       "5 1 5 4 1 1 8 2", 
		       "10 3 1 2 5 10 10 1",
		       "4 1 10 1 7 4 9 3",
		       "0 5 2 1 6 6 8 2",
		       "1 10 9 10 0 9 4 7",
		       "5 2 5 7 7 0 2 3"};

    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    double Arg2 = 5.161066116975455;
    verify_case(4, Arg2, mix(Arg0, Arg1));
  }
// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
   Mixture ___test; 
   ___test.run_test(-1); 
} 
// END CUT HERE 

#define INF (1.0e200)
#define EPS (1.0e-9)

bool zero(double x)
{
  return (-EPS < x && x < EPS);   
}

double resolve(vector< vector<double> > A, vector<double> b, vector<int> P)
{
  int n = A.size(); //num de equacoes
  int m = A[0].size(); //num de incognitas

  if(n < m) return INF;

  for(int i = 0; i < n; i++){
    int pv = 0;
    while(pv < m && zero(A[i][pv]))
      pv++;

    if(pv == m){
      if(!zero(b[i]))
	return INF;
      n--;
      for(int j = 0; j < m; j++)
	A[i][j] = A[n][j];
      b[i] = b[n];
      i--;
      continue;
    }
    for(int k = i+1; k < n; k++){
      double x = A[k][pv] / A[i][pv];
      for(int j = 0; j < m; j++){
	A[k][j] -= x * A[i][j];
      }
      b[k] -= x * b[i];
    }
  }

  if(n != m) return INF;
  
  vector<double> sol (m);
  vector<bool> sei (m, false);

  for(int i = n-1; i >= 0; i--){
    int j = 0;
    while(sei[j] || zero(A[i][j])){
      j++;
    }
    sol[j] = b[i];
    for(int k = 0; k < m; k++)
      if(sei[k])
	sol[j] -=  sol[k] * A[i][k];

    sol[j] /= A[i][j];
    sei[j] = true;
    if(sol[j] < EPS) return INF;
  }

  double resp = 0.0;
  for(int i = 0; i < m; i++)
    resp += sol[i] * P[i];
  return resp;
}

double Mixture::mix(vector <int> mixture, vector <string> availableMixtures)
{
  int n = mixture.size();
  int m = availableMixtures.size();

  if(n > m) return INF;

  vector<double> b;
  vector<int> P (m, 0);
  vector< vector<double> > A (n, vector<double> (m));

  for(int i = 0; i < n; i++)
    b.push_back(mixture[i]);

  for(int j = 0; j < m; j++){
    istringstream iss(availableMixtures[j]);
    for(int i = 0; i < n; i++){
      int x;
      iss >> x;
      A[i][j] = x;
    }
    iss >> P[j];
  }

  double resp = INF;
  
  for(int mask = 1; mask < (1 << m); mask++){
    vector< vector<double> > At (n);
    vector<int> Pt;

    for(int j = 0; j < m; j++){
      if((1 << j) & mask){
	Pt.push_back(P[j]);
	for(int i = 0; i < n; i++)
	  At[i].push_back(A[i][j]);
      }
    }
    double tmp = resolve(At, b, Pt);
    resp = min(resp, tmp);
  }

  if(resp > 0.5*INF)
    return -1.0;
  return resp;

}
