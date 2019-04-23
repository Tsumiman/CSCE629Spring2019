#ifndef HEAP_H
#define HEAP_H
#include <vector>

class Heap {
private:
  std::vector<int> H;
  std::vector<double> D;
  std::vector<double> I;

  inline int root(const int index) const { return (index-1)/2; }
  inline int left(const int index) const { return 2*index+1; }
  inline int right(const int index) const { return 2*index+2; }

  inline bool leftPresent(const int index) const { return left(index) < static_cast<int>(H.size()); }
  inline bool rightPresent(const int index) const { return right(index) < static_cast<int>(H.size()); }

  void heapifyUp(const int index);
  void heapifyDown(const int index);

public:
  Heap(int maxKey);

  void insert(int key, double value);
  void remove(int index);
  int index(int key);
  int maximum() const;
  void updateByKey(int key, double value);
  bool empty() const;
};

#endif // HEAP_H
