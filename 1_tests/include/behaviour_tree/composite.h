#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "node.h"

#include <memory>
#include <vector>

namespace behaviour_tree
{

class Composite : public Node {

protected:
  std::vector<std::unique_ptr<Node>> children_;
  int current_child_ = 0;

public:
  void Add(std::unique_ptr<Node> child);
  void Reset();

};

inline void Composite::Add(std::unique_ptr<Node> child){
  // If child not null, add it
  if (child) {
    children_.push_back(std::move(child));
  }
}

inline void Composite::Reset() { // NOLINT(*-no-recursion)
  current_child_ = 0;
  for (auto& child : children_)
  {
    if (auto* compositeChild = dynamic_cast<Composite*>(child.get())) {
      compositeChild->Reset();
    }
  }
}

}

#endif //COMPOSITE_H
