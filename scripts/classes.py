import requests
from bs4 import BeautifulSoup
import pandas as pd

class WikiPage(object):
    def __init__(self, link, title = ''):
        self.link = link
        self.title = title

    def __str__(self):
        return f"{self.link} [{self.title}]"

    def __eq__(self, other):
        return self.link == other.link

    def makeUrl(self):
        return 'https://en.wikipedia.org' + self.link

    def crawl(self, only_link=False):
        def isValid(link, title):
            if link == None or title == None:
                return False
            else:
                return not any(['wiki' not in link, ':' in link, 'wikipedia' in link, 'Main_Page' in link, 'identifier' in link])
        reqs = requests.get(self.makeUrl())
        soup = BeautifulSoup(reqs.text, 'html.parser')
        edges = {self.link:[]}
        for child in soup.find_all('a'):
            if isValid(child.get('href'), child.get('title')):
                if only_link:
                    if child.get('href') not in edges[self.link]:
                        edges[self.link].append(child.get('href'))
                else:
                    if WikiPage(child.get('href'), child.get('title')) not in edges[self.link]:
                        edges[self.link].append(child)
        return edges

    def make_csv(self):
        dest_pages = self.crawl(only_link=True)
        out_file = open(f'../data/{self.title}.csv', 'w')
        out_frame = pd.DataFrame({'src':[self.link for link in dest_pages[self.link]], 'dest':[link for link in dest_pages[self.link]]})
        out_frame.to_csv(out_file, index=False)
        out_file.close()
        return dest_pages
