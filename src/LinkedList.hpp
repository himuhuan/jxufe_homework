#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory>
#include <iostream>

/**
 * @brief List上的一个节点
 */
template <typename T> class ListNode {
private:
    T value;
    /* C++ 11: 智能指针 */
    std::shared_ptr<ListNode> m_next;
public:

    explicit ListNode(T value = 0) : value(std::move(value)), m_next(nullptr) {
        
    }
    /**
     * @return the value stored in the node.
     */
    const T & val() const { return value; }
    T& val() { return value; }

    /**
     * @returns just like his name..
     **/
    std::shared_ptr<ListNode>& next() { return m_next; }
};

template <typename T> class LinkedList {
private:
    std::shared_ptr<ListNode<T>> first;  
    std::shared_ptr<ListNode<T>> last;
public:
    LinkedList() {
        first = std::make_shared<ListNode<T>>();
        last = nullptr;
    }

    bool empty() {
        if (last == nullptr)
            return true;
        else
            return false;
    }

    void push_back(const T& v) {
        if (empty()) {
            first->next() = std::make_shared<ListNode<T>>(v);
            last = first->next();
        } else {
            last->next() = std::make_shared<ListNode<T>>(v);
            last = last->next();
        }
    }

    void push_front(const T& v) {
        if (empty()) {
            first->next() = std::make_shared<ListNode<T>>(v);
            last = first->next();
        } else {
            std::shared_ptr<ListNode<T>> t = std::make_shared<ListNode<T>>(v);
            t->next() = first->next();
            first->next() = t;
        }
    }

    void erase(const T& v) {
        std::shared_ptr<ListNode<T>> t = first;
        std::shared_ptr<ListNode<T>> to_be_removed = nullptr;
        if (empty())
            return;
        while (t != last && t->next()->val() != v)
            t = t->next();
        if (t == last)
            return;

        to_be_removed = t->next();
        t->next() = t->next()->next();
        to_be_removed.reset();
        if (t->next() == nullptr)
            last = t;
        if (first == last)
            last = nullptr;
    }

    std::shared_ptr<ListNode<T>> find(const T & find_elem) {
        if (empty())
            return nullptr;
        std::shared_ptr<ListNode<T>> t = first;
        while (t != last && t->next()->val() != find_elem)
            t = t->next();
        if (t == last)
            return nullptr;
        return t->next();
    }

    void insert(std::shared_ptr<ListNode<T>> pos, const T& v) {
        if (empty()) {
            first->next() = std::make_shared<ListNode<T>>(v);
            last = first->next();
            return;
        }

        std::shared_ptr<ListNode<T>> p;
        for (p = first; p->next() != pos && p->next() != last; p = p->next())
            ;
        
        std::shared_ptr<ListNode<T>> temp = pos;
        auto new_node = std::make_shared<ListNode<T>>(v);
        p->next() = new_node;
        new_node->next() = temp;
    }

    void display() const {
        std::shared_ptr<ListNode<T>> t = first;
        std::cout << "{ ";
        while (t->next() != nullptr) {
            std::cout << t->next()->val() << " ";
            t = t->next();
        }
        std::cout << "}\n";
    }
};



#endif // !LINKED_LIST_HPP
