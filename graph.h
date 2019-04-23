#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class Graph {
private:
  std::vector<std::vector<int>> m_adjacency;
  std::vector<std::vector<double>> m_weight;
  std::vector<std::vector<int>> m_neighbours;

public:
  Graph(const int N);

  bool addEdge(const int V, const int U, const double weight);
  inline bool isEdge(const int V, const int U) { return (m_adjacency[V][U] == 1); }
  inline const std::vector<int>& nbh(const int V) const { return m_neighbours[V]; }
  inline double weight(const int V, const int U) const { return m_weight[V][U]; }
  int size() const;
};

#endif // GRAPH_H
