#ifndef CODELAB_HEAP_SOLN_H_
#define CODELAB_HEAP_SOLN_H_

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <limits>

using std::vector;
using std::less;
using std::numeric_limits;
using std::make_heap;
using std::push_heap;
using std::pop_heap;

namespace codelab {

template<typename T,
         typename Comparator = less<T> >
class Heap {
 public:
  typedef T value_type;
  typedef T& reference;
  typedef const T& const_reference;
  typedef typename vector<T>::iterator iterator;
  typedef typename vector<T>::const_iterator const_iterator;

  bool empty() const;
  size_t size() const;
  const T& top() const;
  void pop();
  void clear();
  bool push(const T& elem);

  Heap() : max_size_(numeric_limits<size_t>::max()) { }
  explicit Heap(size_t max_size) : max_size_(max_size) { }
  virtual ~Heap() { }

 private:
  vector<T> heap_;
  size_t max_size_;

  void heapify();

  Heap(const Heap&);
  Heap& operator=(const Heap&);
};

////////////////////
// Implementation //
////////////////////
template<typename T,
         typename Comparator>
bool Heap<T, Comparator>::empty() const {
  return heap_.empty();
}

template<typename T,
         typename Comparator>
size_t Heap<T, Comparator>::size() const {
  return heap_.size();
}

template<typename T,
         typename Comparator>
const T& Heap<T, Comparator>::top() const {
  if (empty()) {
    throw "Heap is empty. Cannot use top.";
  }
  return heap_.front();
}

template<typename T,
         typename Comparator>
void Heap<T, Comparator>::pop() {
  if (empty()) {
    throw "Heap is empty. Cannot use pop.";
  }
  pop_heap(heap_.begin(), heap_.end(), Comparator());
  heap_.pop_back();
}

template<typename T,
         typename Comparator>
void Heap<T, Comparator>::clear() {
  heap_.clear();
}

template<typename T,
         typename Comparator>
bool Heap<T, Comparator>::push(const T& elem) {
  // if heap does not hit size limit, insert directly
  // o/w only insert when elem is "smaller" than top()
  // and top() is poped out
  if (size() >= max_size_) {
    if (!Comparator()(elem, top())) {
      return false;
    }
    pop();
  }
  heap_.push_back(elem);
  push_heap(heap_.begin(), heap_.end(), Comparator());
  return true;
}

template<typename T,
         typename Comparator>
void Heap<T, Comparator>::heapify() {
  make_heap(heap_.begin(), heap_.end(), Comparator());
}

}  // namespace codelab

#endif  // CODELAB_HEAP_SOLN_H_
