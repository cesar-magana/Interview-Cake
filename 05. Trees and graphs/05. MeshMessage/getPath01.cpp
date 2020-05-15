#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <deque>
#include <unordered_set>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

vector<string> getPath(const unordered_map<string, string>& howWeReachedNodes,
                       const string& endNode)
{
    vector<string> shortestPath;
    string current = endNode;
    
    while ( ! current.empty() ) {
        shortestPath.push_back( current );
        current = howWeReachedNodes.find( current )->second;
    }
    reverse( shortestPath.begin(), shortestPath.end() );
    return shortestPath;
}

vector<string> getPath(const unordered_map<string, vector<string>>& graph,
                       const string& startNode, const string& endNode)
{
    // find the shortest route in the network between the two users
    if (graph.count(startNode) == 0) {
        throw invalid_argument("Start node not in graph");
    }
    if (graph.count(endNode) == 0) {
        throw invalid_argument("End node not in graph");
    }
    
    deque<string> nodesToVisit;
    nodesToVisit.push_back( startNode );
    
    unordered_set<string> nodesSeen;
    nodesSeen.insert( startNode );
    
    unordered_map<string,string> howWeReachedNodes;
    howWeReachedNodes.emplace( startNode, "" );
    
    while ( ! nodesToVisit.empty() ) {
        string current = nodesToVisit.front();
        nodesToVisit.pop_front();
        
        if ( current == endNode ) {
            vector<string> path = getPath( howWeReachedNodes, endNode );
            return path;
        }
        for ( const auto& neighbor : graph.find(current)->second ) {
            if ( nodesSeen.count( neighbor ) == 0 ) {
                nodesSeen.insert( neighbor );
                nodesToVisit.push_back( neighbor );
                howWeReachedNodes.emplace( neighbor, current );
            }
        }
    }

    return  vector<string>();
}


















// tests

unordered_map<string, vector<string>> getNetwork()
{
    return unordered_map<string, vector<string>> {
        { "a", {"b", "c", "d"} },
        { "b", {"a", "d"} },
        { "c", {"a", "e"} },
        { "d", {"a", "b"} },
        { "e", {"c"} },
        { "f", {"g"} },
        { "g", {"f"} }
    };
}

const lest::test tests[] = {
    {CASE("two hop path 1") {
        const vector<string> expected {"a", "c", "e"};
        const auto actual = getPath(getNetwork(), "a", "e");
        EXPECT(actual == expected);
    }},
    {CASE("two hop path 2") {
        const vector<string> expected {"d", "a", "c"};
        const auto actual = getPath(getNetwork(), "d", "c");
        EXPECT(actual == expected);
    }},
    {CASE("one hop path 1") {
        const vector<string> expected {"a", "c"};
        const auto actual = getPath(getNetwork(), "a", "c");
        EXPECT(actual == expected);
    }},
    {CASE("one hop path 2") {
        const vector<string> expected {"f", "g"};
        const auto actual = getPath(getNetwork(), "f", "g");
        EXPECT(actual == expected);
    }},
    {CASE("one hop path 3") {
        const vector<string> expected {"g", "f"};
        const auto actual = getPath(getNetwork(), "g", "f");
        EXPECT(actual == expected);
    }},
    {CASE("zero hop path") {
        const vector<string> expected {"a"};
        const auto actual = getPath(getNetwork(), "a", "a");
        EXPECT(actual == expected);
    }},
    {CASE("no path") {
        const vector<string> expected;
        const auto actual = getPath(getNetwork(), "a", "f");
        EXPECT(actual == expected);
    }},
    {CASE("start node not present") {
        EXPECT_THROWS(getPath(getNetwork(), "h", "a"));
    }},
    {CASE("end node not present") {
        EXPECT_THROWS(getPath(getNetwork(), "a", "h"));
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}