'''
NOTE: May need to use selenium or something else if the problem is that the website is dynamic
      Also could just use another website or something.
'''

import requests
from bs4 import BeautifulSoup
import numpy as np

url = "https://www.espn.com/soccer/scoreboard"
page = requests.get(url)
soup = BeautifulSoup(page.content,'html.parser')
results = soup.find(id='scoreboard-page')
elems = results.find_all('header', class_='automated-header')
for i in elems:
    t = i.find('h1')
    print(t.text)

# elems = results.find_all('div',class_='carousel-day')
# for i in elems:
#     print(i)
# print(results.prettify())