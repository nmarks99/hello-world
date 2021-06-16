f = open('test.txt','w+')
f.truncate()
f.write('hello %.2f' %2.0)
f.close()