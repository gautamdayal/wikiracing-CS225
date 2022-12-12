# Wikipedia Traversals - CS225 Final Project 

CS 225 final project that crawls Wikipedia to find pages linked out of a starting page, stores this information as a graph (adjacency list), and performs two different algorithms on the graph: Dijkstra's shortest path, and the strongly connected components algorithm. 

**Group members**: Gautam Dayal, Aryaman Dwivedi, Rishi Patel

## Organization

Here's an outline of how our code and written deliverables are organized in this repo
* `src/` - Contains our C++ `wikigraph` class along with methods for the two algorithms we implemented
* `scripts/` - Contains Python code to scrape wikipedia and output CSVs representing the connections between source and destination pages
* `data/` - Contains the files output by the code that's in `scripts`. This is just some example data to illustrate the format, the full data is not uploaded to the repo because of its file size
* `tests/` - Contains unit tests for different functions and the sample data used in those test cases
* `entry/` - Contains driver code to run the project
* **Written report**: `results.md` can be found in the root directory of the repository
* **Presentation Link**: [here](https://youtu.be/b0expmFxDCk)

## Running Instructions & Test Cases

### Building the Project

Our project uses the same CMake environment as the CS225 MPs and Labs. To build the project, create a directory called build (`mkdir build`), navigate to it (`cd build`) and then run cmake (`cmake ..`). You can then either run the tests executable which will show results from our unit tests or the main executable which will run the code in `main.cpp` in `entry/`. 

### More on Test Cases

The methods of interest when using our code are `ParseFromFile()`, `ShortestPath()`, and `SCC()`, each of which are methods of the `wikigraph` class. For more information on parameters of each function and what they return, read the following Documentation section. The test cases we wrote are as follows:
* 3 test cases for `ParseFromFile()`. These test the process of reading the CSV-formatted data into our `wikigraph` class. 
* 3 test cases for `ShortestPath()`. These cover cases with a very small graph with no cycles, and a more complicated example that has cycles and more nodes.
* 3 test cases for `SCC()`. These test cases run our strongly connected components algorithm. 

## Documenation

In addition to commented code, a Doxygen page for the `wikigraph` class and its methods can be found [here](https://gautamdayal.github.io/wikiracing-CS225/class_wiki_graph.html). 
