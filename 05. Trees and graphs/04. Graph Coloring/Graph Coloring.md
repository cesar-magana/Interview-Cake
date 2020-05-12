# Graph Coloring

**Given an undirected graph ↴ with maximum degree ↴ \**D\*D\*\**, find a graph coloring ↴ using at most \**D+1\*D\*+1\** colors.**

For example:

![graph_coloring__frucht_graph_uncolored](/Users/cesar/Downloads/graph_coloring__frucht_graph_uncolored.svg)

This graph's maximum degree (D*D*) is 3, so we have 4 colors (D+1*D*+1). Here's one possible coloring:

![graph_coloring__frucht_graph_colored](/Users/cesar/Downloads/graph_coloring__frucht_graph_colored.svg)

Graphs are represented by a vector of N*N* node objects, each with a label, an unordered set of neighbors, and a color:

```cpp
class GraphNode
{
private:
    string label_;
    unordered_set<GraphNode*> neighbors_;
    string color_;

public:
    GraphNode(const string& label) :
        label_(label),
        neighbors_(),
        color_()
    {
    }

    const string& getLabel() const
    {
        return label_;
    }

    const unordered_set<GraphNode*> getNeighbors() const
    {
        return neighbors_;
    }

    void addNeighbor(GraphNode& neighbor)
    {
        neighbors_.insert(&neighbor);
    }

    bool hasColor() const
    {
        return !color_.empty();
    }

    const string& getColor() const
    {
        if (hasColor()) {
            return color_;
        }
        else {
            throw logic_error("GraphNode is not marked with color");
        }
    }

    void setColor(const string& color)
    {
        color_ = color;
    }
};

GraphNode a("a");
GraphNode b("b");
GraphNode c("c");

a.addNeighbor(b);
b.addNeighbor(a);
b.addNeighbor(c);
c.addNeighbor(b);

vector<GraphNode*> graph { &a, &b, &c };
```