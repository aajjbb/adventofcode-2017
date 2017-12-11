import re

def check_cond(reg, var_name, op, value):
    if not var_name in reg:
        reg[var_name] = 0

    if op == "<":
        return reg[var_name] < value
    elif op == "<=":
        return reg[var_name] <= value
    elif op == "==":
        return reg[var_name] == value
    elif op == ">":
        return reg[var_name] > value
    elif op == ">=":
        return reg[var_name] >= value
    else:
        return reg[var_name] != value

def apply_op(reg, var_name, op, value):
    if not var_name in reg:
        reg[var_name] = 0

    if op == "inc":
        reg[var_name] += value
    else:
        reg[var_name] -= value

    return reg[var_name]

if __name__ == "__main__":
    registers = {}
    largest_reg = -1e10
    
    while True:
        try:
            line = input()
        except EOFError:
            break

        matches = re.match(r"(\w+) (\w+) ([+-]?\d+) if (\w+) ([!><=]+) ([+-]?\d+)", line)

        reg_name  = matches.group(1)
        reg_op    = matches.group(2)
        reg_value = int(matches.group(3))

        cond_var   = matches.group(4)
        cond_op    = matches.group(5)
        cond_value = int(matches.group(6))

        if check_cond(registers,
                      cond_var,
                      cond_op,
                      cond_value):

            reg_value = apply_op(registers,
                                 reg_name,
                                 reg_op,
                                 reg_value)

            largest_reg = max(largest_reg, reg_value)

    print(largest_reg)
