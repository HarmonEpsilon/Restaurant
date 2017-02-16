/**
 * @file doublylinkedlist.h
 *
 * @brief
 *    Template for doubly linked list class.
 *
 * @author Judy Challinger & Your Name Here!
 * @date 1/1/16
 */

#ifndef CSCI_311_DOUBLYLINKEDLIST_H
#define CSCI_311_DOUBLYLINKEDLIST_H

template <class T>
class DoublyLinkedList {

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void append(T* data);
        bool empty() const { return (head == nullptr); }
        T* remove();
        T* first();
        T* next();

    private:
        class Node {
            public:
                Node();
                Node(T* data);
                Node* next;
                Node* prev;
                T* data;
        };
        Node* head;
        Node* tail;
        Node* current;
};

/**
 * @brief   Node constructor.
 */
template <class T>
DoublyLinkedList<T>::Node::Node() {
    next = nullptr;
    prev = nullptr;
    data = nullptr;
}

template<class T>
DoublyLinkedList<T>::Node::Node(T* data){
    this->data = data;
    next = nullptr;
    prev = nullptr;
}

/**
 * @brief   DoublyLinkedList constructor.
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}

/**
 * @brief   DoublyLinkedList destructor.
 */
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    delete head;
    head = nullptr;
    delete tail;
    tail = nullptr;
    delete current;
    current = nullptr;
}

/**
 * @brief   Appends a new Node at the end of the DoublyLinkedList.
 * @param   data A pointer to the data to be stored in the new Node.
 * @return  Nothing.
 *
 * Creates a new Node to hold the data and appends the Node at the end
 * of the list. The current Node pointer is set to point to the newly
 * appended Node.
 */
template <class T>
void DoublyLinkedList<T>::append(T* data) {
    Node* ptr = new Node(data);
    if(head == nullptr){
        tail = ptr;
        head = ptr;
        current = ptr;
    }
    else{
        ptr->prev = tail;
        tail->next = ptr;
        tail = ptr;
        current = ptr;
    }
}

/**
 * @brief   Get the first thing on the list.
 * @return  A pointer to the data stored in the first Node on the list,
 *          or nullptr if the list is empty.
 *
 * The current pointer is set to point to the first Node in the list,
 * or nullptr if the list is empty.
 */
template <class T>
T* DoublyLinkedList<T>::first() {
    if(head == nullptr){
        return nullptr;
    }
    else{
        current = head;
        return head->data;
    }
}

/**
 * @brief   Get the next thing on the list.
 * @return  A pointer to the data stored in the next Node on the list. The next
 *          Node is the one following whatever the current pointer is pointing
 *          to. If there is no next Node then nullptr is returned.
 *
 * The current pointer is set to point to the next Node in the list,
 * or nullptr if there is no next Node.
 */
template <class T>
T* DoublyLinkedList<T>::next() {
    if( head == nullptr || current == nullptr || current->next == nullptr){
        current = nullptr;
        return nullptr;
    }
    else{
        current = current->next;
        return current->data;
    }
}

/**
 * @brief   Remove the Node pointed to by the current pointer.
 * @return  A pointer to the data stored in the next Node on the list. The next
 *          Node is the one following the Node that was removed. If there is
 *          no next Node then nullptr is returned.
 *
 * The current pointer is set to point to the next Node in the list, following
 * the Node that was removed, or nullptr if there is no next Node.
 */
template <class T>
T* DoublyLinkedList<T>::remove() {
    if(head == nullptr){
        current = nullptr;
        return nullptr;
    }
    else if(current->next == nullptr && current->prev == nullptr){
        delete current;
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        return nullptr;
    }
    else if(current->next != nullptr && current->prev != nullptr){
        Node* before = current->prev;
        Node* after = current->next;
        delete current;
        before->next = after;
        after->prev = before;
        current = after;
        return current->data;
    }
    else if(current == head){
        Node *temp = current->next;
        delete current;
        current = temp;
        current->prev = nullptr;
        head = current;
        return current->data;
    }
    else{
        Node *temp = current->prev;
        delete current;
        current = nullptr;
        tail = temp;
        tail->next = nullptr;
        return nullptr;
    }
    return nullptr;
}
#endif
