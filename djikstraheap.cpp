#include "djikstraheap.h"
#include "graph.h"
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>

DjikstraHeap::DjikstraHeap(std::shared_ptr<Graph> G, const int from, const int to):
  G(G), from(from), to(to), size(G->size()),
  parent(size, -1),
  bandwidth(size, -1),
  status(size, NodeType::New),
  H(size)
{
  parent[from]    = 0;
  bandwidth[from] = std::numeric_limits<double>::max();
  status[from]    = NodeType::Fringe;
  H.insert(from, bandwidth[from]);
}

void DjikstraHeap::setParent(const int V, const int U)
{
  parent[U]    = V;
  bandwidth[U] = std::min(bandwidth[V], G->weight(V, U));
  status[U]    = NodeType::Fringe;
  H.updateByKey(U, bandwidth[U]);
}

int DjikstraHeap::selectNextFringe() const
{
  int selected = H.maximum();
  return selected;
}

void DjikstraHeap::updateFringeNbh(const int V)
{
  for (int U: G->nbh(V)) {
    if (status[U] != NodeType::InTree && bandwidth[U] < std::min(bandwidth[V], G->weight(V, U))) {
      setParent(V, U);
    }
  }
}

void DjikstraHeap::run()
{
  while (status[to] != NodeType::InTree) {
    int V = selectNextFringe();
    H.remove(0);
    updateFringeNbh(V);
    status[V] = NodeType::InTree;
  }
}

std::vector<int> DjikstraHeap::path() const
{
  std::vector<int> path;
  path.push_back(to);
  while (path.back() != from) {
    path.push_back(parent[path.back()]);
  }
  std::reverse(path.begin(), path.end());
  return path;
}

int DjikstraHeap::answer() const
{
  return bandwidth[to];
}
