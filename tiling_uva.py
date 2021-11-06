lst = [0]*251
lst[0] = 1
lst[1] = 1
for i in range(2,251,1):
    lst[i] = lst[i-1] + 2 * lst[i-2]
    
def cin(n):
    #function that woks equally to doing cin >> n
    try:
        n[0] = int(input())
        return True
    except:
        return False

def main():
    n = [0]
    while cin(n):
        #MESSAGE: do someting with n[0] (watch out, n is list object with one element)
        print(lst[n[0]])
main()