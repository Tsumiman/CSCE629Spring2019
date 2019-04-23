#include <iostream>
#include <vector>
#include <random>
#include <iterator>
#include "graph.h"
#include "djikstranaive.h"
#include "djikstraheap.h"
#include <memory>

using namespace std;

int main()
{
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_real_distribution<> weights(1.0, 100.0);
  std::shared_ptr<Graph> G = std::make_shared<Graph>(5);
  G->addEdge(0, 1, 17);
  G->addEdge(1, 2, 15);
  G->addEdge(2, 3, 7);
  G->addEdge(3, 4, 20);
  G->addEdge(1, 3, 13);
  DjikstraHeap algo(std::shared_ptr<Graph>(G), 0, 4);
  algo.run();
  std::vector<int> path = algo.path();
  std::copy(path.begin(), path.end(), std::ostream_iterator<int>(std::cout, "->"));
  cout << "Hello World!" << endl;
  return 0;
}
