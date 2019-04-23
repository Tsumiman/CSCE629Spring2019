#ifndef GRAPHUTILS_H
#define GRAPHUTILS_H
#include "graph.h"
#include <random>

Graph generateConnectedGraph(const int N, std::mt19937& rnd, std::uniform_real_distribution<> weights);
Graph generateG1(const int N, const double D, std::mt19937& rnd, std::uniform_real_distribution<> weights);
Graph generateG2(const int N, const double R, std::mt19937& rnd, std::uniform_real_distribution<> weights);

#endif // GRAPHUTILS_H
