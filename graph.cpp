#include "graph.h"

Graph::Graph(const int N):
  m_adjacency(N, std::vector<int>(N, 0)),
  m_weight(N, std::vector<double>(N, 0)),
  m_neighbours(N, std::vector<int>()) {
}

bool Graph::addEdge(const int V, const int U, const double weight) {
  if (V == U) return false;
  if (m_adjacency[V][U]) return false;
  m_adjacency[V][U] = m_adjacency[U][V] = 1;
  m_weight[V][U] = m_weight[U][V] = weight;
  m_neighbours[V].push_back(U);
  m_neighbours[U].push_back(V);
  return true;
}

int Graph::size() const
{
  return static_cast<int>(m_adjacency.size());
}
