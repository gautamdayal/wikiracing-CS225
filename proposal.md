## Leading Question 

Can we use a dataset (created by us) of Wikipedia pages and links between them to find the shortest path between any two wikipedia articles? We can store the graph as an adjacency matrix or a list of edges. 

## Dataset Acquisition

We will use a dataset of wikipedia pages and links between each page. This is most likely available online, but if it isn't we can create a simple Python script and use BeautifulSoup to create the dataset ourselves. Wikipedia as a source is public so the dataset would technically exist already.



## Data Format

The data will be stored as a single or multiple text files in the .csv format so that they can be read in easily by our code. 

## Data Correction

We likely will not need much data correction. However, we could exclude meta wikipedia pages etc so that our graph isn't too big.

## Data Storage

For storage, we could store the graph as an adjacency matrix so that checking whether an edge exists is a constant time operation, or O(1).

## Algorithm 

We will be using Dijkstra's shortest path algorithm to find the shortest path between two wikipedia articles. The input would be the start page and the destination page, and the output would be a sequence of edges that make up the graph traversal. This would be a O(V^2) operation where V is the number of nodes in the graph.

## Timeline
1. Acquire data from public data source.
2. C++ code to format data as an adjacency matrix
3. Create skeleton code for Graph structure
4. Write Dijsktra's algorithm implementation
5. Integrate
