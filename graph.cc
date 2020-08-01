#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

template <typename ElemType>
class Graph {
 public:
  struct GraphNode;
  struct GraphEdge;

  struct GraphEdge {
    const GraphNode* from_node;
    const GraphNode* to_node;
    double weight = 0.0;
  };

  struct GraphNode {
    GraphNode(const ElemType& elem) : elem(elem) {}
    ElemType elem;
    std::vector<GraphEdge*> out_neighbors;
    // maybe if needed?
    std::vector<GraphEdge*> in_neighbors;

    void Print() const { std::cout << "This elem is: " << elem << std::endl; }
  };

  Graph() = default;
  ~Graph() = default;

  std::shared_ptr<const GraphNode> AddVertex(const ElemType& elem) {
    std::shared_ptr<GraphNode> graph_node(new GraphNode(elem));
    vertices_.emplace_back(graph_node);
    return graph_node;
  }

  std::shared_ptr<const GraphNode> FindVertex(const ElemType& elem) {
    const auto itr = std::find_if(vertices_.begin(), vertices_.end(),
                                  [&elem](const std::shared_ptr<GraphNode> g) {
                                    return g->elem == elem;
                                  });
    return itr == vertices_.end() ? nullptr : *itr;
  }

  // AddConnection(const )

 private:
  std::vector<std::shared_ptr<GraphNode>> vertices_;
};

int main() {
  Graph<int> g;
  std::shared_ptr<const Graph<int>::GraphNode> gn = g.AddVertex(4);

  gn->Print();

  auto found_gn = g.FindVertex(4);
  if (found_gn) {
    std::cout << "Found!" << std::endl;
  }

  return 0;
}