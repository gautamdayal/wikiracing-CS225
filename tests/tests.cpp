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