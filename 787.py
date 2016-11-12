arr = [0 for i in range(103)]

while True:
        try:
                x = input().split(" ")
                l = len(x);
                for i in range(l):
                        arr[i] = int(x[i])

                ans = -99999999
                for i in range(l-1):
                        cur = 1
                        for j in range(i, l-1):
                                cur *= arr[j]
                                if (cur > ans):
                                     ans = cur
                print(ans)
        except EOFError:
                break
