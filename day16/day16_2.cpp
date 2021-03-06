#include <bits/stdc++.h>

using namespace std;

void spin(string& arg, int pos) {
  int back_pos = arg.size() - 1 - pos;

  string end = arg.substr(back_pos, pos + 1);

  arg.erase(arg.begin() + back_pos, arg.end());

  arg = end + arg;
}

void exchange(string& arg, int a, int b) {
  swap(arg[a], arg[b]);
}

void partner(string& arg, string a, string b) {
  int pa = arg.find(a);
  int pb = arg.find(b);

  swap(arg[pa], arg[pb]);
}

vector<string> split(string source, string pattern) {
  unsigned int i, base = 0;
  vector<string> ret;
  string buff;

  for(i = 0; i < source.size(); i++) {
    if(source.substr(i, pattern.size()) == pattern) {
      ret.push_back(buff);
      i += pattern.size() - 1;
      buff.clear();
    } else {
      buff += source[i];
    }
  }
  ret.push_back(buff);
  return ret;
}

int main() {
  string pr = "";
  string input;

  const int cycle = 63;
  const int round_limit = 1000000000 % cycle;

  for (char c = 'a'; c <= 'p'; c++) {
    pr += c;
  }

  cin >> input;

  vector<string> tokens = split(input, ",");

  for (int rounds = 0; rounds < round_limit; rounds++) {
    for (int i = 0; i < tokens.size(); i++) {
      string curr_token = tokens[i];
      char op = curr_token[0];

      curr_token.erase(curr_token.begin());

      vector<string> operands = split(curr_token, "/");

      if (op == 's') {
        spin(pr, stoi(operands[0]) - 1);
      } else if (op == 'x') {
        exchange(pr, stoi(operands[0]), stoi(operands[1]));
      } else {
        partner(pr, operands[0], operands[1]);
      }
    }
  }
  cout << pr << endl;

  return 0;
}
