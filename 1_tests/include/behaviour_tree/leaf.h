#ifndef LEAF_H
#define LEAF_H

#include "types.h"

namespace behaviour_tree {
  class Leaf : public Node {
      std::function<void()> action_;
    public:
      explicit Leaf(const std::function<void()> &action) : action_(action) {};
      Status Tick() override;
  };
}

#endif //LEAF_H
