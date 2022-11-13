#ifndef RB_NODE_H
#define RB_NODE_H

#include <string>

#include "NodeColor.h"

template<typename T>
class RBNode {
public:
    RBNode(T value, NodeColor color = NodeColor::Red, RBNode<T>* parent = nullptr)
        : value_{value}
        , color_{color}
        , parent_{parent}
        , left_child_{nullptr}
        , right_child_{nullptr} {
        ;
    }

    T const& value() const {
        return value_;
    }

    NodeColor& color() {
        return color_;
    }

    NodeColor const& color() const {
        return color_;
    }

    RBNode<T>& set_color(NodeColor color) {
        color_ = color;
        return *this;
    }

    RBNode<T>* parent() {
        return parent_;
    }

    RBNode<T> const* parent() const {
        return parent_;
    }

    RBNode<T>& set_parent(RBNode<T>* parent) {
        parent_ = parent;
        return *this;
    }

    bool has_parent() const {
        return parent_ != nullptr;
    }

    RBNode<T>* grandparent() {
        return has_grandparent() ? parent_->parent() : nullptr;
    }

    RBNode<T> const* grandparent() const {
        return has_grandparent() ? parent_->parent() : nullptr;
    }

    bool has_grandparent() const {
        return has_parent() && parent_->parent_ != nullptr;
    }

    RBNode<T>* left_child() {
        return left_child_;
    }

    RBNode<T> const* left_child() const {
        return left_child_;
    }

    RBNode<T>& set_left_child(RBNode<T>* child) {
        left_child_ = child;
        return *this;
    }

    RBNode<T>* right_child() {
        return right_child_;
    }

    RBNode<T> const* right_child() const {
        return right_child_;
    }

    RBNode<T>& set_right_child(RBNode<T>* child) {
        right_child_ = child;
        return *this;
    }

    bool has_black_children() const {
        auto left = left_child_ == nullptr || left_child_->color() == NodeColor::Black;
        auto right = right_child_ == nullptr || right_child_->color() == NodeColor::Black;
        return left && right;
    }

    ~RBNode() {
        delete left_child_;
        delete right_child_;
    }

private:
    T value_;
    NodeColor color_;

    RBNode<T>* parent_;
    RBNode<T>* left_child_;
    RBNode<T>* right_child_;
};

template<typename T>
bool operator==(RBNode<T> const& lhs, RBNode<T> const& rhs) {
    return lhs.value() == rhs.value();
}

template<typename T>
bool operator!=(RBNode<T> const& lhs, RBNode<T> const& rhs) { return !(lhs == rhs); }

namespace std {
    namespace {
        template<typename T>
        std::string to_string(RBNode<T> const& node, int depth) {
            auto rv = std::string(depth, ' ') + std::to_string(node.color()) + ": " + std::to_string(node.value());
            if (node.left_child() != nullptr) {
                rv += "\nL" + to_string(*node.left_child(), depth + 1);
            }
            if (node.right_child() != nullptr) {
                rv += "\nR" + to_string(*node.right_child(), depth + 1);
            }
            return rv;
        }
    }

    template<typename T>
    std::string to_string(RBNode<T> const& node) {
        auto rv = "\\ " + std::to_string(node.color()) + ": " + std::to_string(node.value());
        if (node.left_child() != nullptr) {
            rv += "\nL" + to_string(*node.left_child(), 2);
        }
        if (node.right_child() != nullptr) {
            rv += "\nR" + to_string(*node.right_child(), 2);
        }
        return rv;
    }
}
#endif // !RB_NODE_H
