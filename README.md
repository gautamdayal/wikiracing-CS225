# Wikipedia Traversals - CS225 Final Project 

CS 225 final project that crawls Wikipedia to find pages linked out of a starting page, stores this information as a graph (adjacency list), and performs two different algorithms on the graph: Dijkstra's shortest path, and the strongly connected components algorithm. 

## Organization

Here's an outline of how our code and written deliverables are organized in this repo
* `src` - Contains our C++ `wikigraph` class along with methods for the two algorithms we implemented
* `scripts` - Contains Python code to scrape wikipedia and output CSVs representing the connections between source and destination pages
* `data` - Contains the files output by the code that's in `scripts`. This is just some example data to illustrate the format, the full data is not uploaded to the repo because of its file size
* `tests` - Contains unit tests for different functions and the sample data used in those test cases
* `entry` - Contains driver code to run the project
* **Written report**: `results.md` can be found in the root directory of the repository

## Running Instructions

