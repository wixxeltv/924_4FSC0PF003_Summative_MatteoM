#ifndef LEAF_H
#define LEAF_H

#include <functional>
#include "node.h"

namespace behaviour_tree {

  class Leaf final : public Node {

      std::function<Status()> action_;

    public:
      explicit Leaf(const std::function<Status()> &action) : action_(action) {};
      Status Tick() override;
  };

  inline Status Leaf::Tick(){
    return action_();
  }

}

#endif //LEAF_H
