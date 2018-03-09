#include <stack>
#include <iostream>
#include <string.h>

using namespace std;

int stackingSequence(int n)
//D is a matrix of (n+1)*(n+1)
{
  int *D = new int[(n+1)*(n+1)];
  memset(D, 0, sizeof(int)*(n+1)*(n+1));
  //D(0, 0) = 1
  // border D(n,0) = D(n-1,0)
  for (int i = 0; i <= n; ++i)
    D[(n+1)*i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; ++j) {
      // i row, j column
      // D(i, j) = D(i-1, j) + D(i, j-1)
      D[(n+1)*i + j] = D[(n+1)*(i-1) + j] + D[(n+1)*i + j-1];
      //cout << i << j << D[(n+1)*i + j] << endl;
    }
  }
  int tmp = D[(n+1)*(n+1)-1];
  //cout << tmp << endl;
  delete [] D;
  return tmp;
}

int main(int argc, char *argv[])
{
  // suppose 1<=n<=15
  int n;
  cin >> n;
  int n_seq = stackingSequence(n);
  cout << n_seq << endl;
  return 0;
}
