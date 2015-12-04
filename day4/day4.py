from hashlib import md5
init = 'bgvyzdsv'
for i in range(10000000):
    h = md5((init + str(i)).encode()).hexdigest()
    if h[:6] == '000000':
        print(i)
        break