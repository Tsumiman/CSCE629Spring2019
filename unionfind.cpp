#include "unionfind.h"

UnionFind::UnionFind(int N): m_subsets(N, std::make_pair(0, 0))
{
  for (int i = 0; i < N; ++i) m_subsets[i].first = i;
}

int UnionFind::find(int i)
{
  if (parent(i) != i) {
    parent(i) = find(parent(i));
  }
  return parent(i);
}

void UnionFind::unite(int i, int j)
{
  int iRoot = find(i);
  int jRoot = find(j);
  if  (rank(iRoot) < rank(jRoot))
    parent(iRoot) = jRoot;
  else if (rank(iRoot) > rank(jRoot))
    parent(jRoot) = iRoot;
  else {
    parent(jRoot) = iRoot;
    rank(iRoot)++;
  }
}
