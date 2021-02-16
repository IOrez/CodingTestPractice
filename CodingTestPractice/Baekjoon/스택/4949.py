st = []
charset = {']':'[',')':'('}

while True:
    s = input()
    if s == '.':
        break
    res = True
    for ch in s:
        if ch == '[' or ch == '(':
            st.append(ch)
        elif ch == ']' or ch == ')':
            if len(st) == 0 or st[-1] != charset[ch] :
                res = False
                break
            st.pop()
    if len(st) !=  0 :
        res = False
    st = []
    print('yes') if res else print('no')