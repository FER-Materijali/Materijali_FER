#ifndef RB_TREE_H
#define RB_TREE_H

#include <memory>
#include <string>

#include "NodeColor.h"
#include "RBNode.h"

template<typename T>
class RBTree {
public:
    RBTree<T>& insert(T const& value);

    RBTree<T>& remove(T const& value);

    RBNode<T>* min(RBNode<T>& node);

    RBNode<T>* max(RBNode<T>& node);

    RBNode<T>* search(T const& value);

    RBNode<T>* root() {
        return root_.get();
    }

    RBNode<T> const* root() const {
        return root_.get();
    }

private:
    void fix_insert_violations(RBNode<T>* node);
    void fix_remove_violations(RBNode<T>* node);

    void left_rotate(RBNode<T>* node);
    void right_rotate(RBNode<T>* node);

    void transplant(RBNode<T>* u, RBNode<T>* v);

    std::unique_ptr<RBNode<T>> root_;
};

template<typename T>
inline RBTree<T>& RBTree<T>::insert(T const& value) {
    if (search(value) != nullptr) {
        return *this;
    }

    auto* x = root_.get();
    decltype(x) y = nullptr;

    while (x != nullptr) {
        y = x;
        x = value < x->value() ? x->left_child() : x->right_child();
    }
    auto* node = new RBNode<T>(value, NodeColor::Red, y);
    if (y == nullptr) {
        root_.reset(node);
    }
    else if ( value < y->value()) {
        y->set_left_child(node);
    }
    else {
        y->set_right_child(node);
    }
    fix_insert_violations(node);
    return *this;
}

template<typename T>
inline RBTree<T>& RBTree<T>::remove(T const& value) {
    RBNode<T>* z = search(value);
    if (z == nullptr) {
        return *this;
    }
    RBNode<T>* y = z;
    RBNode<T>* x = nullptr;
    auto originalColor = y->color();
    if (z->left_child() == nullptr) {
        x = z->right_child();
        transplant(z, z->right_child());
    }
    else if (z->right_child() == nullptr) {
        x = z->left_child();
        transplant(z, z->left_child());
    }
    else {
        y = min(*(z->right_child()));
        originalColor = y->color();
        x = y->right_child();
        if (y->parent() == z) {
            if (x != nullptr) {
                x->set_parent(y);
            }
        }
        else {
            transplant(y, y->right_child());
            y->set_right_child(z->right_child());
            y->right_child()->set_parent(y);
        }
        transplant(z, y);
        y->set_left_child(z->left_child());
        y->left_child()->set_parent(y);
        y->set_color(z->color());
    }

    z->set_left_child(nullptr).set_right_child(nullptr);
    delete z;

    if (originalColor == NodeColor::Black) {
        fix_remove_violations(x);
    }

    return *this;
}

template<typename T>
inline RBNode<T>* RBTree<T>::min(RBNode<T>& node) {
    RBNode<T>* rv = std::addressof(node);
    while (rv->left_child() != nullptr) {
        rv = rv->left_child();
    }
    return rv;
}

template<typename T>
inline RBNode<T>* RBTree<T>::max(RBNode<T>& node) {
    RBNode<T>* rv = std::addressof(node);
    while (rv->right_child() != null) {
        rv = rv->right_child();
    }
    return rv;
}

template<typename T>
inline RBNode<T>* RBTree<T>::search(T const& value) {
    auto* x = root_.get();
    while (x != nullptr && x->value() != value) {
        x = value < x->value() ? x->left_child() : x->right_child();
    }
    return x;
}

template<typename T>
inline void RBTree<T>::fix_insert_violations(RBNode<T>* node) {
    RBNode<T>* x = node;
    while (x->has_parent() && x->parent()->color() == NodeColor::Red) {
        if (!x->has_grandparent()) {
            continue;
        }

        if (x->parent() == x->grandparent()->left_child()) {
            RBNode<T>* y = x->grandparent()->right_child();
            if (y != nullptr && y->color() == NodeColor::Red) {
                x->parent()->set_color(NodeColor::Black);
                y->set_color(NodeColor::Black);
                x->grandparent()->set_color(NodeColor::Red);
                x = x->grandparent();
            }
            else {
                if (x == x->parent()->right_child()) {
                    x = x->parent();
                    left_rotate(x);
                }

                x->parent()->set_color(NodeColor::Black);
                x->grandparent()->set_color(NodeColor::Red);
                right_rotate(x->grandparent());
            }
        }
        else {
            RBNode<T>* y = x->grandparent()->left_child();
            if (y != nullptr && y->color() == NodeColor::Red) {
                x->parent()->set_color(NodeColor::Black);
                y->set_color(NodeColor::Black);
                x->grandparent()->set_color(NodeColor::Red);
                x = x->grandparent();
            }
            else {
                if (x == x->parent()->left_child()) {
                    x = x->parent();
                    right_rotate(x);
                }

                x->parent()->set_color(NodeColor::Black);
                x->grandparent()->set_color(NodeColor::Red);
                left_rotate(x->grandparent());
            }
        }
    }
    root_->set_color(NodeColor::Black);
}

template<typename T>
inline void RBTree<T>::fix_remove_violations(RBNode<T>* node) {
    if (node == nullptr) { return; }

    RBNode<T>* x = node;
    while (x != root_.get() && x->color() == NodeColor::Black) {
        if (x == x->parent()->left_child()) {
            RBNode<T>* w = x->parent()->right_child();
            if (w->color() == NodeColor::Red) {
                w->set_color(NodeColor::Black);
                x->parent()->set_color(NodeColor::Red);
                left_rotate(x->parent());
                w = x->parent()->right_child();
            }

            if (w->has_black_children()) {
                w->set_color(NodeColor::Red);
                x = x->parent();
            }
            else {
                if (w->right_child()->color() == NodeColor::Black) {
                    w->left_child()->set_color(NodeColor::Black);
                    w->set_color(NodeColor::Red);
                    right_rotate(w);
                    w = x->parent()->right_child();
                }

                w->set_color(x->parent()->color());
                x->parent()->set_color(NodeColor::Black);
                w->right_child()->set_color(NodeColor::Black);
                left_rotate(x->parent());
                x = root_.get();
            }
        }
        else {
            RBNode<T>* w = x->parent()->left_child();
            if (w->color() == NodeColor::Red) {
                w->set_color(NodeColor::Black);
                x->parent()->set_color(NodeColor::Red);
                right_rotate(x->parent());
                w = x->parent()->left_child();
            }

            if (w->has_black_children()) {
                w->set_color(NodeColor::Red);
                x = x->parent();
            }
            else {
                if (w->left_child()->color() == NodeColor::Black) {
                    w->right_child()->set_color(NodeColor::Black);
                    w->set_color(NodeColor::Red);
                    left_rotate(w);
                    w = x->parent()->left_child();
                }

                w->set_color(x->parent()->color());
                x->parent()->set_color(NodeColor::Black);
                w->left_child()->set_color(NodeColor::Black);
                right_rotate(x->parent());
                x = root_.get();
            }
        }
    }
    if (x != nullptr) {
        x->set_color(NodeColor::Black);
    }
}

template<typename T>
inline void RBTree<T>::left_rotate(RBNode<T>* node) {
    if (node->right_child() == nullptr) {
        return;
    }

    RBNode<T>* y = node->right_child();
    node->set_right_child(y->left_child());
    if (y->left_child() != nullptr) {
        y->left_child()->set_parent(node);
    }
    y->set_parent(node->parent());
    if (!node->has_parent()) {
        root_.release();
        root_.reset(y);
    }
    else if (node == node->parent()->left_child()) {
        node->parent()->set_left_child(y);
    }
    else {
        node->parent()->set_right_child(y);
    }
    y->set_left_child(node);
    node->set_parent(y);
}

template<typename T>
inline void RBTree<T>::right_rotate(RBNode<T>* node) {
    if (node->left_child() == nullptr) {
        return;
    }

    RBNode<T>* y = node->left_child();
    node->set_left_child(y->right_child());
    if (y->right_child() != nullptr) {
        y->right_child()->set_parent(node);
    }
    y->set_parent(node->parent());
    if (!node->has_parent()) {
        root_.release();
        root_.reset(y);
    }
    else if (node == node->parent()->right_child()) {
        node->parent()->set_right_child(y);
    }
    else {
        node->parent()->set_left_child(y);
    }
    y->set_right_child(node);
    node->set_parent(y);
}

template<typename T>
inline void RBTree<T>::transplant(RBNode<T>* u, RBNode<T>* v) {
    if (v != nullptr) {
        v->set_parent(u->parent());
    }

    if (!u->has_parent()) {
        root_.release();
        root_.reset(v);
    }
    else if (u == u->parent()->left_child()) {
        u->parent()->set_left_child(v);
    }
    else {
        u->parent()->set_right_child(v);
    }
}

namespace std {
    template<typename T>
    std::string to_string(RBTree<T> const& tree) {
        if (tree.root() == nullptr) {
            return "Empty";
        }
        return std::to_string(*tree.root());
    }
}

#endif // !RB_TREE_H

