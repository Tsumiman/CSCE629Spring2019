#ifndef DJIKSTRANAIVE_H
#define DJIKSTRANAIVE_H
#include <memory>
#include <vector>

class Graph;

class DjikstraNaive
{
private:
  enum class NodeType {InTree, Fringe, New};
  std::shared_ptr<Graph> G;
  int from, to, size;

  std::vector<int>    parent;
  std::vector<double> bandwidth;
  std::vector<NodeType> status;

  inline void setParent(const int V, const int U);
  inline int selectNextFringe() const;
  inline void updateFringeNbh(const int V);

public:
  DjikstraNaive(std::shared_ptr<Graph> G, const int from, const int to);

  void run();
  std::vector<int> path() const;
  int answer() const;
};

#endif // DJIKSTRANAIVE_H
