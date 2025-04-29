def BinarySearch(x, V):
    return 1

n = 32
offset = 10

V = [i for i in range(1, n + 1)]

for i in [i for i in range(0 - offset, n + offset)]:
    print(i)
    index = BinarySearch(i, V)
    print(index)
