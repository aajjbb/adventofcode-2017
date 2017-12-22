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

struct Process {
  bool done;
  int id;
  int pointer;
  int snd;

  queue<long long> in_queue;
  map<string, long long> registers;

  Process(int _id) {
    id = _id;
    pointer = 0;
    snd = 0;
    done = false;

    registers["p"] = _id;
  }

  void eval(string operation, Process& other_process) {
    vector<string> tokens = split(operation, " ");
    string op = tokens[0];

    if (op == "snd") {
      other_process.in_queue.push(registers[tokens[1]]);
      snd += 1;
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
      if (!in_queue.empty()) {
        registers[tokens[1]] = in_queue.front();
        in_queue.pop();
      } else {
        return;
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
        pointer += y;
        return;
      }
    }
    pointer += 1;
  }
};

int main() {
  string input;
  vector<string> operations;

  Process p0(0), p1(1);

  while (getline(cin, input)) {
    operations.push_back(input);
  }

  // brute force until deadlock
  for (int i = 0; i < 10000000; i++) {
    p0.eval(operations[p0.pointer], p1);
    p1.eval(operations[p1.pointer], p0);
  }

  cout << p1.snd << endl;

  return 0;
}
