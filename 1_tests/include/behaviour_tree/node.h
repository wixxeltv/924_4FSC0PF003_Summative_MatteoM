#ifndef NODE_H
#define NODE_H

#include "status.h"

namespace behaviour_tree {

class Node {
public:
  virtual Status Tick() = 0;
};
}
#endif //NODE_H
