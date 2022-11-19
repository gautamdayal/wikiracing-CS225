from classes import *

def createSubgraphData(source, depth, breadth):
    q = []
    q.append(source)
    for i in range(depth * breadth):
        page = q.pop()
        to_add = page.make_csv()[page.link][:breadth]
        print(to_add)
        for item in to_add:
            q.append(WikiPage(item))

node_0 = WikiPage('/wiki/Gaiwan', "Gaiwan")
# print(node_0.make_csv())
createSubgraphData(node_0, 2, 5)
