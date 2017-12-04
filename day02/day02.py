answer = 0

while True:
    try:
        line = input()
    except EOFError:
        break

    as_list = list(map(int, line.split()))
    answer += max(as_list) - min(as_list)

print(answer)
