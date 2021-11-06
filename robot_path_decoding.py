test = int(input())
for _ in range(test):
    ans_x = 0
    ans_y = 0
    s = input()
    n = len(s)
    st = []
    dir = "NSEW"
    multiplier = 1
    mod = 10**9
    for i in range(n):
        if s[i] in dir:
            if s[i] == 'N':
                ans_y -= multiplier
            elif s[i] == 'S':
                ans_y += multiplier
            elif s[i] == 'E':
                ans_x += multiplier
            else:
                ans_x -= multiplier
            ans_x %= mod
            ans_y %= mod
        else:
            if ord(s[i]) >= 50 and ord(s[i]) <= 57:
                st.append(ord(s[i]) - 48)
                multiplier*= ord(s[i]) - 48
            elif s[i] == ')':
                multiplier //= st.pop()
    ans_x += 1
    ans_y += 1
    print("Case #" + str(_ + 1) + ": " + str(ans_x) + " " + str(ans_y))     