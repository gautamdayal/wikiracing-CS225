#include <catch2/catch_test_macros.hpp>
#include "wikigraph.h"

TEST_CASE("ParseFromFileTest1") {
    WikiGraph test;
    test.ParseFromFile("../tests/data/demofile.csv");
    std::string actual = "a>b\n"
                        "a>c\n"
                        "b>c\n"
                        "b>e\n"
                        "c>d\n"
                        "d>e\n";
                      
    std::string output = test.PrintEdgeList();
    REQUIRE(output == actual);
}

TEST_CASE("ParseFromFileTest2") {
    WikiGraph test;
    test.ParseFromFile("../tests/data/demofile_2.csv");
    std::string actual = "a>b\n"
                        "a>f\n"
                        "c>a\n"
                        "d>a\n"
                        "e>a\n"
                        "f>i\n"
                        "g>a\n"
                        "g>f\n"
                        "h>g\n"
                        "i>g\n"
                        "i>j\n"
                        "i>h\n"
                        "k>e\n";
                      
    std::string output = test.PrintEdgeList();
    REQUIRE(output == actual);
}

TEST_CASE("ParseFromFileTest3") {
    WikiGraph test;
    test.ParseFromFile("../tests/data/demofile_3.csv");
    std::string actual = "a>b\n"
                        "a>c\n"
                        "a>d\n"
                        "b>d\n"
                        "b>e\n"
                        "c>f\n"
                        "d>c\n"
                        "d>f\n"
                        "d>g\n"
                        "e>d\n"
                        "e>g\n"
                        "g>f\n";
                      
    std::string output = test.PrintEdgeList();
    REQUIRE(output == actual);
}

TEST_CASE("ShortestPathTest1") {
    WikiGraph test;
    test.ParseFromFile("../tests/data/demofile.csv");
    std::vector<std::string> a_to_c = {"a","c"};
    std::vector<std::string> a_to_e = {"a","b","e"};
    std::vector<std::string> c_to_e = {"c","d","e"};
    
    REQUIRE(test.ShortestPath("a", "c") == a_to_c);
    REQUIRE(test.ShortestPath("a", "e") == a_to_e);
    REQUIRE(test.ShortestPath("c", "e") == c_to_e);
    
}

TEST_CASE("ShortestPathTest2") {
    WikiGraph test;
    test.ParseFromFile("../tests/data/demofile_2.csv");
    std::vector<std::string> a_to_h = {"a","f","i","h"};
    std::vector<std::string> g_to_h = {"g","f","i","h"};
    std::vector<std::string> d_to_j = {"d","a","f","i","j"};

    REQUIRE(test.ShortestPath("a", "h") == a_to_h);
    REQUIRE(test.ShortestPath("g", "h") == g_to_h);
    REQUIRE(test.ShortestPath("d", "j") == d_to_j);
}

TEST_CASE("ShortestPathTest3") {
    WikiGraph test;
    test.ParseFromFile("../tests/data/demofile_3.csv");
    std::vector<std::string> a_to_f = {"a","c","f"};
    std::vector<std::string> a_to_g = {"a","d","g"};
    std::vector<std::string> b_to_c = {"b","d","c"};
    std::vector<std::string> e_to_f = {"e","d","f"};

    REQUIRE(test.ShortestPath("a", "f") == a_to_f);
    REQUIRE(test.ShortestPath("a", "g") == a_to_g);
    REQUIRE(test.ShortestPath("b", "c") == b_to_c);
    REQUIRE(test.ShortestPath("e", "f") == e_to_f);
}


TEST_CASE("SCCTest1") {
    WikiGraph test;
    test.ParseFromFile("../tests/data/demofile_4.csv");

    /*
    SCC should equal
    a, d, c, b
    e, g, f
    h
    */


    // REQUIRE(test.SCC() == );

}


TEST_CASE("SCCTest2") {
    WikiGraph test;
    test.ParseFromFile("../tests/data/demofile_5.csv");
    
    /*
    SCC should equal
    a, b, c
    d
    e
    */


    // REQUIRE(test.SCC() == );
}


TEST_CASE("SCCTest3") {
    WikiGraph test;
    test.ParseFromFile("../tests/data/demofile_6.csv");
    
    /*
    SCC should equal
    a, e, b
    c, d, h
    g, f
    */


    // REQUIRE(test.SCC() == );
}


