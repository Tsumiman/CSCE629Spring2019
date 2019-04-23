#ifndef DJIKSTRAHEAP_H
#define DJIKSTRAHEAP_H
#include <memory>
#include <vector>
#include "heap.h"

class Graph;

class DjikstraHeap
{
private:
  enum class NodeType {InTree, Fringe, New};
  std::shared_ptr<Graph> G;
  int from, to, size;

  std::vector<int>    parent;
  std::vector<double> bandwidth;
  std::vector<NodeType> status;
  Heap H;

  inline void setParent(const int V, const int U);
  inline int selectNextFringe() const;
  inline void updateFringeNbh(const int V);

public:
  DjikstraHeap(std::shared_ptr<Graph> G, const int from, const int to);

  void run();
  std::vector<int> path() const;
  int answer() const;
};

#endif // DJIKSTRAHEAP_H
