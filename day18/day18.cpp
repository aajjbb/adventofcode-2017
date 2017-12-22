#include <bits/stdc++.h>

using namespace std;

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

bool isRegister(string arg) {
  if (arg.size() == 1 && isalpha(arg[0])) {
    return true;
  } else {
    return false;
  }
}

int main() {
  string input;
  vector<long long> played;
  map<string, long long> registers;
  vector<string> operations;

  while (getline(cin, input)) {
    operations.push_back(input);
  }

  int id = 0;

  while (1) {
    vector<string> tokens = split(operations[id], " ");
    string op = tokens[0];

    assert(id >= 0 && id < operations.size());

    if (op == "snd") {
      played.push_back(registers[tokens[1]]);
    } else if (op == "set") {
      if (isRegister(tokens[2])) {
        registers[tokens[1]] = registers[tokens[2]];
      } else {
        registers[tokens[1]] = stoi(tokens[2]);
      }
    } else if (op == "add") {
      if (isRegister(tokens[2])) {
        registers[tokens[1]] += registers[tokens[2]];
      } else {
        registers[tokens[1]] += stoi(tokens[2]);
      }
    } else if (op == "mul") {
      if (isRegister(tokens[2])) {
        registers[tokens[1]] *= registers[tokens[2]];
      } else {
        registers[tokens[1]] *= stoi(tokens[2]);
      }
    } else if (op == "mod") {
      if (isRegister(tokens[2])) {
        registers[tokens[1]] %= registers[tokens[2]];
      } else {
        registers[tokens[1]] %= stoi(tokens[2]);
      }
    } else if (op == "rcv") {
      long long x = registers[tokens[1]];

      if (x != 0) {
        break;
      }
    } else {
      //jgz
      long long x = -1;
      long long y = -1;

      if (isRegister(tokens[1])) {
        x = registers[tokens[1]];
      } else {
        x = stoi(tokens[1]);
      }

      if (isRegister(tokens[2])) {
        y = registers[tokens[2]];
      } else {
        y = stoi(tokens[2]);
      }

      if (x > 0) {
        id += y;
        continue;
      }
    }

    id += 1;
  }

  cout << played.back() << endl;

  return 0;
}
