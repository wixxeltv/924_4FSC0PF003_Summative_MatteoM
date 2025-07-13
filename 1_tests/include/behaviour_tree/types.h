#ifndef NODE_H
#define NODE_H
#include <functional>
#include <memory>
namespace behaviour_tree {

enum class Status {
  SUCCESS,
  FAILURE,
  RUNNING
};

class Node {
public:
  Node() = default;
  virtual ~Node() = default;
  virtual Status Tick();

};

class CompositeNode : public Node {
  std::vector<std::unique_ptr<Node>> children_;
public:
   ~CompositeNode() override = default;
  void Add(std::unique_ptr<Node> child);

};

}
#endif //NODE_H
