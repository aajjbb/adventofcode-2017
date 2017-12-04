def get_division(data):
    """
    data is a list.
    returns the division between the two
    unique even divisible numbers in data
    """

    answer = 0

    for i in range(len(data)):
        for j in range(len(data)):
            if i != j and data[i] % data[j] == 0:
                answer = data[i] / data[j]
                break
    return int(answer)

answer = 0

while True:
    try:
        line = input()
    except EOFError:
        break

    as_list = list(map(int, line.split()))
    answer += get_division(as_list)

print(answer)
