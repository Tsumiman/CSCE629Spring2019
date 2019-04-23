#include "djikstranaive.h"
#include "graph.h"
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>

DjikstraNaive::DjikstraNaive(std::shared_ptr<Graph> G, const int from, const int to):
  G(G), from(from), to(to), size(G->size()),
  parent(size, -1),
  bandwidth(size, -1),
  status(size, NodeType::New)
{
  parent[from]    = 0;
  bandwidth[from] = std::numeric_limits<double>::max();
  status[from]    = NodeType::Fringe;
}

void DjikstraNaive::setParent(const int V, const int U)
{
  parent[U]    = V;
  bandwidth[U] = std::min(bandwidth[V], G->weight(V, U));
  status[U]    = NodeType::Fringe;
}

int DjikstraNaive::selectNextFringe() const
{
  int selected = -1;
  for (int V = 0; V < size; ++V) {
    if (status[V] == NodeType::Fringe && (selected == -1 || bandwidth[selected] < bandwidth[V])) {
      selected = V;
    }
  }
  return selected;
}

void DjikstraNaive::updateFringeNbh(const int V)
{
  for (int U: G->nbh(V)) {
    if (status[U] != NodeType::InTree && bandwidth[U] < std::min(bandwidth[V], G->weight(V, U))) {
      setParent(V, U);
    }
  }
}

void DjikstraNaive::run()
{
  while (status[to] != NodeType::InTree) {
    int V = selectNextFringe();
    updateFringeNbh(V);
    status[V] = NodeType::InTree;
  }
}

int DjikstraNaive::answer() const
{
  return bandwidth[to];
}

std::vector<int> DjikstraNaive::path() const
{
  std::vector<int> path;
  path.push_back(to);
  while (path.back() != from) {
    path.push_back(parent[path.back()]);
  }
  std::reverse(path.begin(), path.end());
  return path;
}
