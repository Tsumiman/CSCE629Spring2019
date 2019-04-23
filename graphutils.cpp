#include "graphutils.h"
#include <iostream>

Graph generateConnectedGraph(const int N, std::mt19937& rnd, std::uniform_real_distribution<> weights) {
  Graph G(N);
  for (int i = 1; i < N; ++i)
    G.addEdge(i, rnd()%i, weights(rnd));
  return G;
}

Graph generateG1(const int N, const double D, std::mt19937& rnd, std::uniform_real_distribution<> weights) {
  Graph G = generateConnectedGraph(N, rnd, weights);

  // 3*N - (N-1): Graph G already has N-1 edges since it is a tree
  int edgesToGenerate = std::poisson_distribution<int>(N*D/2 - (N-1))(rnd);
  std::cerr<<"G1 log: Generating "<<edgesToGenerate<<" edges"<<std::endl;

  for (int i = 0; i < edgesToGenerate; ++i) {
    // If the edge is already present, select a different pair of
    while (!G.addEdge(rnd()%N, rnd()%N, weights(rnd))) {}
  }
  int sumDegree = 0;
  for (int i = 0; i < N; ++i)
    sumDegree += G.nbh(i).size();
  std::cerr<<"G1 log: Average degree is "<<static_cast<double>(sumDegree)/N<<std::endl;
  return G;
}

Graph generateG2(const int N, const double R, std::mt19937& rnd, std::uniform_real_distribution<> weights) {
  Graph G = generateConnectedGraph(N, rnd, weights);

  // For each vertex we are going to generate approx. N*R edges to vertices with greater index
  for (int V = 0; V < N; ++V) {
    // If we have more than enough edges already, don't do anything:
    int edgesPresent = G.nbh(V).size();
    if (edgesPresent > N*R) continue;

    // For vertex V, we can have at most N-V-1 forward edges:
    int edgesToGenerate = std::min(std::poisson_distribution<int>(N*R - edgesPresent)(rnd), N-V-1);

    // Generate a set of candidate vertices. It is basically a range [V+1, N-1]
    std::vector<int> candidates;
    for (int U = V+1; U < N; ++U) candidates.push_back(U);

    // Try to add as many edges as possible up to edgesToGenerate.
    while (edgesToGenerate && !candidates.empty()) {
      int index = rnd()%candidates.size();
      // Swap-and-remove, so that we won't have to move the contents of the vector.
      int U = candidates[index];
      std::swap(candidates[index], candidates.back());
      candidates.pop_back();
      if (G.addEdge(V, U, weights(rnd))) --edgesToGenerate;
    }
  }

  int sumDegree = 0;
  for (int i = 0; i < N; ++i)
    sumDegree += G.nbh(i).size();
  std::cerr<<"G2 log: Average vertex is connected to "<<100*static_cast<double>(sumDegree)/N/N <<"% of other vertices"<<std::endl;
  return G;
}
