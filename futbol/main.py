'''
NOTE: May need to use selenium or something else if the problem is that the website is dynamic
      Also could just use another website or something.
'''

import requests
from bs4 import BeautifulSoup
import numpy as np

url = "https://www.livescore.com/en/football/copa-america/"
page = requests.get(url)
# <div class="MatchRows_root__1NKae" id="match-rows__root">
soup = BeautifulSoup(page.text,'html.parser')
res = soup.find(id='match-rows__root')
for i in res:
    g = i.find('div',class_='MatchRow_footballRoot__1S4eG MatchRow_isHighlighted__397Dm')
    print(g)
# results = soup.find(id='scoreboard-page')
# elems = results.find_all('header', class_='automated-header')
# for i in elems:
#     t = i.find('h1')
#     print(t.text)

# elems = results.find_all('div',class_='carousel-day')
# for i in elems:
#     print(i)
# print(results.prettify())