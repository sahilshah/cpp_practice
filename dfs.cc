#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <set>
#include <vector>

class GraphNode {
 public:
  GraphNode() = default;
  explicit GraphNode(int key) : key_(key) {}

  const int Key() const { return key_; }

  const std::vector<const GraphNode*>& Neighbors() const { return neighbors_; }

  void AddNeighbor(const GraphNode& nbr) { neighbors_.push_back(&nbr); }

 private:
  int key_;
  std::vector<const GraphNode*> neighbors_;
};

// visited is in_out.
// it gets updated on each visit.
template <typename Key>
bool DFS(const GraphNode& root, const Key& key, std::set<Key>& visited) {
  if (root.Key() == key) {
    return true;
  }
  visited.insert(root.Key());
  for (const GraphNode* nbr : root.Neighbors()) {
    if (visited.count(nbr->Key()) != 1) {
      if (DFS(*nbr, key, visited)) {
        return true;
      }
    }
  }
  return false;
}

int main(int argc, char** argv) {
  // Assume a graph API.
  GraphNode start(0);
  GraphNode one(1);
  GraphNode two(2);
  GraphNode three(3);
  GraphNode four(4);

  start.AddNeighbor(one);
  one.AddNeighbor(start);

  start.AddNeighbor(two);
  two.AddNeighbor(start);

  start.AddNeighbor(three);
  three.AddNeighbor(start);

  start.AddNeighbor(four);
  four.AddNeighbor(start);

  std::set<int> visited;
  const auto& key_node = DFS(one, std::atoi(argv[1]), visited);
  if (key_node) {
    std::cout << "Found!\n";
  } else {
    std::cout << "Not Found!";
  }

  return 0;
}