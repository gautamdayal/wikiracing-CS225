# Results

## Algorithms

### Dijkstra's Algorithm:
#### Unit Tests:

In order to test the implementation of Dijkstra's Algorithm, the following graphs were used to generate the shortest path from a start point to a destination point. The path returned was then compared with the real shortest path to ensure the algorithm implementation was correct. 


Unit Test 1: Small graph with 5 nodes

<img src="https://github.com/gautamdayal/wikiracing-CS225/blob/main/tests/graphs/demofile.png" alt="demofile" width="400"/>

The following start and destination points were used on the graph above, in which all the paths returned were correct. The test can be seen as the "ShortestPathTest1" test in the test.cpp file. 

Start: "a", Destination: "c": "a" -> "c"

Start: "a", Destination: "e": "a" -> "b" -> "e"

Start: "c", Destination: "e": "c" -> "d" -> "e"


Unit Test 2: Advanced graph with 11 nodes

<img src="https://github.com/gautamdayal/wikiracing-CS225/blob/main/tests/graphs/demofile_2.png" alt="demofile2" width="400"/>

The following start and destination points were used on the graph above, in which all the paths returned were correct. The test can be seen as the "ShortestPathTest2" test in the test.cpp file. 

Start: "a", Destination: "h": "a" -> "f" -> "i" -> "h"

Start: "g", Destination: "h": "g" -> "f" -> "i" -> "h"

Start: "d", Destination: "j": "d" -> "a" -> "f" -> "i" -> "j"

Unit Test 3: Advanced graph with 7 nodes

<img src="https://github.com/gautamdayal/wikiracing-CS225/blob/main/tests/graphs/demofile_3.png" alt="demofile3" width="400"/>

The following start and destination points were used on the graph above, in which all the paths returned were correct. The test can be seen as the "ShortestPathTest3" test in the test.cpp file. 

Start: "a", Destination: "f": "a" -> "c" -> "f"

Start: "a", Destination: "g": "a" -> "d" -> "g"

Start: "b", Destination: "c": "b" -> "d" -> "c"

Start: "e", Destination: "f": "e" -> "d" -> "f"


#### Full Scale Test:

The image below shows the shortest path from the "Silicon" Wikiepdia page to the "Acid" Wikipedia page.

<img src="https://github.com/gautamdayal/wikiracing-CS225/blob/main/tests/FullScaleShortest1.png" alt="demofile3" width="400"/>

The image below shows the shortest path from the "University of Illinois Urbana-Champaign" Wikiepdia page to the "United States" Wikipedia page.

<img src="https://github.com/gautamdayal/wikiracing-CS225/blob/main/tests/FullScaleShortest2.png" alt="demofile3" width="400"/>



### Kosarju's Algorithm:
#### Unit Tests:

In order to test the implementation of Kosarju's Algorithm, the following graphs were used to generate lists of strongly connected components within the graph. The groups of strongly connected nodes was compared to the actual solution to ensure the algorithm implementation was correct.


<img src="https://github.com/gautamdayal/wikiracing-CS225/blob/main/tests/graphs/demofile_4.png" alt="demofile4" width="400"/>

The alogrithm was used on the graph above to find the strongly connected components. The test can be seen as the "SCCTest1" test in the test.cpp file.

Strongly Connected Components: [a, b, c, d], [e, g, f], [h]


<img src="https://github.com/gautamdayal/wikiracing-CS225/blob/main/tests/graphs/demofile_5.png" alt="demofile5" width="400"/>

The alogrithm was used on the graph above to find the strongly connected components. The test can be seen as the "SCCTest2" test in the test.cpp file.
 
Strongly Connected Components: [a, b, c], [d], [e]

<img src="https://github.com/gautamdayal/wikiracing-CS225/blob/main/tests/graphs/demofile_6.png" alt="demofile6" width="400"/>

The alogrithm was used on the graph above to find the strongly connected components. The test can be seen as the "SCCTest3" test in the test.cpp file.
 
Strongly Connected Components: [a, e, b], [c, d, h], [g, f]

#### Full Scale Test:




