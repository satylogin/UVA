t = int(input())
for xt in range(t):
    y = input().split()
    n = int(y[0]);
    x = []
    for i in range(n):
        x.append(int(y[i+1]))
    x.sort()
    y = n // 2
    a = x[y]
    s = 0
    for i in range(n):
        s += abs(a-x[i])
    print(s)
