x = [0] * 1001
t = 1
while True:
    n = int(input())
    if (n == 0):
        break
    print("Case " + str(t) + ":")
    t += 1
    for i in range(n):
        x[i] = int(input())
    y = []
    for i in range(n):
        for j in range(i+1, n):
            y.append(x[i]+x[j])

    y.sort()
    a = 0
    b = 0
    j = len(y)

    m = int(input())
    for xm in range(m):
        val = int(input())
        a = 999999999
        start = 0
        end = j-1
        idx = -1
        while (start <= end):
            mid = (start + end) // 2
            if (y[mid] > val):
                idx = mid
                end = mid - 1
            elif (y[mid] < val):
                idx = mid
                start = mid + 1
            else:
                idx = mid
                break
        if (idx != 0 and abs(y[idx-1] - val) < a):
            a = abs(y[idx-1]-val)
            b = y[idx-1]
        if (abs(y[idx]-val) < a):
            a = abs(y[idx]-val)
            b = y[idx]
        if (idx != j-1 and abs(y[idx+1] - val) < a):
            b = y[idx+1]
        print("Closest sum to " + str(val) + " is " + str(b) + ".")
