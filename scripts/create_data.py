from classes import *
import sys

def createSubgraphData(source, depth, breadth):
    q = []
    q.append(source)
    for i in range(depth * breadth):
        page = q.pop()
        print(page)
        with open("../data/file_list.txt", "a") as listfile:
            listfile.write(str(page).split(" ")[0].split("/")[2] + "\n")
        to_add = page.make_csv()[page.link][:breadth]
        
        for item in to_add:
            q.append(WikiPage(item, item.split("/")[2]))
num_args = len(sys.argv)
if (num_args >= 5):
    link = sys.argv[1]
    title = sys.argv[2]
    depth = int(sys.argv[3])
    breadth = int(sys.argv[4])
    node_0 = WikiPage(link, title)
    # print(node_0.make_csv())
    open("../data/file_list.txt", "w")
    createSubgraphData(node_0, depth, breadth)
else:
    print("createdata.py wiki/[page_name] [title] [depth] [breadth]")
