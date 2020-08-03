#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <queue>
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

bool BFS(const GraphNode& root, int key) {
  std::queue<const GraphNode*> explore;
  std::set<int> visited;

  explore.push(&root);
  while (!explore.empty()) {
    const auto cur = explore.front();
    if (cur->Key() == key) {
      return true;
    }
    for (const auto& nbr : cur->Neighbors()) {
      if (visited.count(nbr->Key()) == 1) {
        continue;
      }
      explore.push(nbr);
    }
    visited.insert(cur->Key());
    explore.pop();
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
  GraphNode ten(10);

  start.AddNeighbor(one);
  one.AddNeighbor(start);

  start.AddNeighbor(two);
  two.AddNeighbor(start);

  start.AddNeighbor(three);
  three.AddNeighbor(start);

  start.AddNeighbor(four);
  four.AddNeighbor(start);

  three.AddNeighbor(four);
  four.AddNeighbor(three);

  two.AddNeighbor(ten);
  ten.AddNeighbor(two);

  std::set<int> visited;
  const auto& key_node = BFS(one, std::atoi(argv[1]));
  if (key_node) {
    std::cout << "Found!\n";
  } else {
    std::cout << "Not Found!\n";
  }

  return 0;
}