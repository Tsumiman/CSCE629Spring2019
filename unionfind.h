#ifndef UNIONFIND_H
#define UNIONFIND_H
#include <vector>
#include <algorithm>

class UnionFind
{
  std::vector<std::pair<int, int>> m_subsets;
  inline int& rank(int i) { return m_subsets[i].second; }
  inline int& parent(int i) { return m_subsets[i].first; }

public:
  UnionFind(int N);

  inline int find(int i);
  inline void unite(int i, int j);
};

#endif // UNIONFIND_H
