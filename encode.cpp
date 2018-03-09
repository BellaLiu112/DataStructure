#include <string>
#include <iostream>

using namespace std;

void encode(const string& input, string& output)
{
  int l = (int)input.size();
  for (int i = 0; i < l; ++i) {
    if ((input[i] > 64 && input[i] < 90) || (input[i] > 96 && input[i] < 122)) {
      output.push_back(input[i]+1);
    } else if (input[i] == 90){
      output.push_back(65);
    } else if (input[i] == 122){
      output.push_back(97);
    } else{
      output.push_back(input[i]);
    }
  }
}

int main(int argc, char * argv[])
{
  int n;
  cin >> n;
  string in, out;
  while (n--) {
    in.clear();
    out.clear();
    while(1) {
      char c = cin.get();
      if (c == '\n') {
        break;
      }
      in.push_back(c);
    }
    encode(in, out);
    cout << out << endl;
  }

  return 0;
}
