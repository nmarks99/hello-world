elems = results.find_all('header', class_='automated-header')
for i in elems:
    t = i.find('h1')
    print(t.text)