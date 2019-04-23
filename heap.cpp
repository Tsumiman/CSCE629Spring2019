#include "heap.h"

Heap::Heap(int maxKey) {
  D.resize(maxKey, 0);
  I.resize(maxKey, -1);
}

void Heap::insert(int key, double value) {
  H.push_back(key);
  D[key] = value;
  I[key] = H.size()-1;
  heapifyUp(H.size()-1);
}

void Heap::remove(int index) {
  int key = H[index];
  I[key] = -1;
  std::swap(I[key], I[H.back()]);
  std::swap(H[index], H.back());
  H.pop_back();
  heapifyUp(index);
  heapifyDown(index);
}

int Heap::index(int key)
{
  return I[key];
}

int Heap::maximum() const {
  return H[0];
}

void Heap::updateByKey(int key, double value)
{
  int index = I[key];
  if (index == -1) insert(key, value);
  else {
    D[key] = value;
    heapifyUp(index);
    heapifyDown(index);
  }
}

bool Heap::empty() const
{
  return H.empty();
}

void Heap::heapifyUp(const int index) {
  int R = root(index);
  if (D[H[index]] > D[H[R]]) {
    std::swap(I[H[index]], I[H[R]]);
    std::swap(H[index], H[R]);
    heapifyUp(R);
  }
}

void Heap::heapifyDown(const int index) {
  int largest = index;
  int L = left(index);
  int R = right(index);

  if (leftPresent(index) && D[H[L]] > D[H[index]]) {
    largest = L;
  }

  if (rightPresent(index) && D[H[R]] > D[H[largest]]) {
    largest = R;
  }

  if (largest != index) {
    std::swap(I[H[index]], I[H[largest]]);
    std::swap(H[index], H[largest]);
    heapifyDown(largest);
  }
}
