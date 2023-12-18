/* Nithisha Sathishkumar
* Novemeber 13, 2023
* Project 1
* Professor.Dimpsey
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Node Structor represent a single node in linked List
template <class T>
struct Node{
    T *data; 
    Node<T> *next; 
};

template <class T>
class List342{
public:
    //default, parameterized and copy constructor and destructorr
    List342();
    List342(const T &obj);
    List342(const List342<T> &other);
    ~List342();

    //Action
    bool BuildList(string file_name);
    bool Insert(T *obj);
    bool Remove(T target, T &result);
    bool Peek(T target, T &result) const;
    void DeleteList();
    bool Merge(List342<T> &list1);

    //setter
    int Size() const;
    
    //getter
    Node<T>& get_head() const;

    //operator
    List342<T>& operator+=(const List342<T> &other);
    List342<T> operator+(const List342<T> &other) const;
    bool operator==(const List342<T> &other) const;
    bool operator!=(const List342<T> &other) const;
    List342<T>& operator=(const List342<T>& other);

private:
    //private data member
    Node<T> *head_;
    int size;
};

//constructor
template<class T>
List342<T>::List342(){
    this->head_ = nullptr;
    size = 0;
}

//parameterized constructor
template<class T>
List342<T>::List342(const T& obj) {
    Node<T>* newNode = new Node<T>;
    newNode->data = new T(obj);
    newNode->next = nullptr;
    
    head_ = newNode;
    size = 1;
}

//copy constructor
template<class T>
List342<T>::List342(const List342<T> &other){
    this->head_ = nullptr;
    *this = other;
}

//destructor
template<class T>
List342<T>::~List342(){
    Node<T> *temp = head_;

    while(head_ != nullptr){
        temp = head_;
        head_ = head_->next;
        temp->data = nullptr;
        delete temp->data;
        delete temp;
    }
}

//get the head 
template<class T>
Node<T>& List342<T>::get_head() const{
    return *this->head_;
}

// Returns the current size (number of elements) of the list
template<class T>
int List342<T>::Size() const{
    return size;
}

// BuildList function reads data from a file and inserts it into the list.
// Takes a file name as a parameter and returns true if successful, false otherwise.
template<class T>
bool List342<T>::BuildList(string fileName){
    ifstream in_file;
    in_file.open(fileName);

    if(in_file.is_open()){
        while(!in_file.eof()){ // While there's data in the file
            T *item = new T(); //Create a new item
            in_file >> *item; 
            Insert(item);
        }

        return true;
        in_file.close(); //close the file

    }else{
        cout << "file: " << fileName << " not found " << endl;
        return false;
    }
}

// Insert function adds a new element to the list while maintaining order and no duplicate.
// Takes a pointer to the new element as a parameter and returns true if successful, false otherwise.
template<class T>
bool List342<T>::Insert(T *obj) {
    
    //check if the obj is nullptr
    if(obj == nullptr){
        return false;
    }

    //create a newNode
    Node<T> *newNode = new Node<T>;
    newNode->data = new T(*obj);

    //if the list is empty, insert the new element as the head
    if(head_ == nullptr) {
        head_ = newNode;
        size++;
        return true;
    }

    Node<T> *current = head_;
    Node<T> *prev = nullptr;

    while(current != nullptr) {

        //check for duplicate element
        if(*obj == *current->data) {
            newNode->data = nullptr;
            delete newNode->data; 
            delete newNode;
            return false;
        }

        //insert the new element before the current node
        if(*obj < *current->data) {
            newNode->next = current;
            if(prev != nullptr){
                prev->next = newNode;
            }else{
                head_ = newNode; 
            }
            size++;
            return true;
        }

        prev = current;
        current = current->next;
    }

    // If we reach here, the new element should be inserted at the end of the list
    prev->next = newNode;
    size++;
    return true;
}

// Removes the node containing the specified target data from the list.
// The removed data is stored in the 'result' parameter.
// Returns true if the removal is successful, false otherwise.
template<class T>
bool List342<T>::Remove(T target, T &result){

    //if the list is empty
    if(head_ == nullptr){
        return false;
    }

    Node<T> *current = head_->next;
    Node<T> *prev = head_;

    // Check if the head node contains the target data
    if(*head_->data == target){
        result = *head_->data;
        head_ = current;
        prev->data = nullptr; // Without this, there might be a malloc error due to double deletion
        delete prev->data; 
        delete prev;
        size--;
        return true;
    }

    // Iterate through the list to find and remove the node with the target data
    while(current != nullptr){
        if(*current->data == target){
            result = *current->data;
            prev->next = current->next;
            current->data = nullptr; // Without this, there might be a malloc error due to double deletion
            delete current->data;
            delete current;
            size--;
            return true;
        }

        prev = current;
        current = current->next;
    }

    // Target data not found in the list
    return false; 
}

// Retrieves the data of the node containing the specified target data without removing it.
// The retrieved data is stored in the 'result' parameter.
// Returns true if the target data is found, false otherwise.
template<class T>
bool List342<T>::Peek(T target, T &result) const{
    Node<T> *temp = head_;

    // Check if the list is empty
    if(head_ == nullptr){
        return false;
    }

    // Iterate through the list to find the node with the target data
    while(temp != nullptr){
        if(*temp->data == target){
            result = *temp->data;
            return true;
        }

        temp = temp->next;
    }

    // Target data not found in the list
    return false; 
}

// Deletes all nodes in the list and resets the size to zero.
template<class T>
void List342<T>::DeleteList(){
    Node<T> *temp = head_;
    while(head_ != nullptr){
        head_ = head_->next;
        temp->data = nullptr; // Without this, there might be a malloc error due to double deletion
        delete temp->data;
        delete temp;
        temp = head_;
    }
    size = 0; 
}

// Merges the calling list with another list, removing duplicates and maintaining the sorted order.
// Returns true if the merge is successful; otherwise, returns false.
template<class T>
bool List342<T>::Merge(List342<T> &list1) {
    // Check if the two lists are the same
    if (*this == list1) {
        return false;
    }

    Node<T> *current = head_;
    Node<T> *prev = nullptr;

    // While loop runs until either the head of the second list (list1.head) or the current node is null
    while (list1.head_ != nullptr && current != nullptr) {

        // Check if the head nodes of the two lists are duplicates
        if (*this->head_->data == *list1.head_->data) {
            Node<T> *temp = list1.head_;
            list1.head_ = list1.head_->next;

            // Delete the duplicate node from list1
            delete temp;
        }

        // Check if the head node of list1 should be the new head of the calling list
        else if (*this->head_->data > *list1.head_->data) {
            Node<T> *temp = list1.head_;
            list1.head_ = list1.head_->next;

            // Make a deep copy of the data and insert it into the calling list
            Node<T> *newNode = new Node<T>;
            newNode->data = new T(*(temp->data));
            newNode->next = current;
            head_ = newNode;
            size++;

            // Delete the duplicate node from list1
            delete temp;
        }

        // Check if the next node in the calling list is a duplicate of the head node of list1
        else if (*current->data == *list1.head_->data) {

            Node<T> *temp = list1.head_;
            list1.head_ = list1.head_->next;

            // Delete the duplicate node from list1
            delete temp;
        }

        // Check if the next node in the calling list should be the head node of list1
        else if (*current->data > *list1.head_->data) {
            Node<T> *temp = current->next;

            // Make a deep copy of the data and insert it into the calling list
            Node<T> *newNode = new Node<T>;
            newNode->data = new T(*(list1.head_->data));
            newNode->next = temp;
            current->next = newNode;

            // Delete the original head node of list1
            Node<T> *tempHead = list1.head_;
            list1.head_ = list1.head_->next;
            delete tempHead;
            size++;
        }

        // If none of the above conditions match, move to the next node in the calling list
        else {
            prev = current;
            current = current->next;
        }
    }

    // If the calling list is shorter than list1, append the remaining nodes from list1
    if (current == nullptr) {
        if (prev == nullptr) {
            // If the calling list is empty, update the head
            head_ = list1.head_;
        } else {
            prev->next = list1.head_;
        }
        list1.head_ = nullptr;
        size += list1.size;
    }

    return true;
}

// Overloads the equality operator to compare if the calling list is equal to another list.
// Two lists are considered equal if they have the same size and contain the same elements in the same order.
template<class T>
bool List342<T>::operator==(const List342<T> &other) const{
    if(this->size != other.Size()){
        return false;
    }

    Node<T> *temp = this->head_;
    Node<T> *other_temp = other.head_;

    // Compare each element of the two lists
    while(temp != nullptr){
        if(*(temp->data) != *(other_temp->data)){
            return false;
        }

        temp = temp->next;
        other_temp = other_temp->next;
    }

    return true;
}

// Overloads the inequality operator to compare if the calling list is not equal to another list.
// Two lists are considered not equal if they have different sizes or contain different elements.
template<class T>
bool List342<T>::operator!=(const List342<T> &other) const{
    
    if(this->size != other.Size()){
        return true;
    }

    Node<T> *temp = this->head_;
    Node<T> *other_temp = other.head_;

    while(temp != nullptr){
        if(*(temp->data) != *(other_temp->data)){
            return true;
        }

        temp = temp->next;
        other_temp = other_temp->next;
    }

    return false;
}

// Overloads the assignment operator to make a deep copy of another list.
// If the calling list and the other list are the same, no action is taken.
// If the other list is empty, the calling list is cleared.
// Otherwise, the calling list is populated with a deep copy of the elements from the other list.
template<class T>
List342<T>& List342<T>::operator=(const List342<T> &other){

    //check if this->list and other is same 
    if (*this == other) {
        return *this;
    }

    //Delete node in the this list and the size will equal to zero
    this->DeleteList();
    
    //if the other is empty it will return this
    if(other.head_ == nullptr){
        return *this;
    }

    Node<T> *current = other.head_;
    Node<T> *temp = nullptr;

    //iterate through the other list
    while(current != nullptr){

        //create a new node with a deep copy of the data 
        Node<T> *newNode = new Node<T>;
        newNode->data = (T*)current->data;

        //if temp is null, it means this is the first node in the new list
        if(temp == nullptr){
            head_ = newNode;

        }else{
            //Connect newNode to the previous node
            temp->next = newNode;
        }

        //Move temp to the newNode that was added
        temp = newNode;

        //Move to the next node in the other list
        current = current->next;
    }

    //assign the size to new list
    this->size = other.Size();
    
    return *this; 
}

// Overloads the addition operator to concatenate the elements of two lists.
// Creates a new list as a copy of the calling list.
// Uses the += operator to add the elements from the other list.
// Returns the resulting concatenated list.
template<class T>
List342<T> List342<T>::operator+(const List342<T> &other) const{

   //Create a new list as a copy of the calling list 
   List342<T> temp_list = *this; 

   //Use the += operator to add the elements from the other list
   temp_list += other;

   //Return the resulting concatenated list
   return temp_list;
   
}


// Overloads the compound addition operator to add the elements from another list.
// Checks if the calling list and the other list are the same; if so, returns the calling list unchanged.
// Iterates through the other list and adds elements to the calling list in a sorted order.
// Handles duplicate elements by skipping their addition to the calling list.
// Returns the modified calling list.
template<class T>
List342<T>& List342<T>::operator+=(const List342<T> &other){

    //check if this->list and other is same 
    if(this == &other){ 
        return *this;
    }

    Node<T> *current = other.head_;
    Node<T> *temp;

    //iterate through the other list
    while(current != nullptr){
        Node<T> *newNode = new Node<T>;
        newNode->data = (T*)current->data;
        
        // If the calling list is empty or the new node's data is less than the head's data
        if(head_ == nullptr || *newNode->data < *head_->data){
            newNode->next = head_;
            head_ = newNode;
            size++;

        }else if(*newNode->data == *head_->data){
            // Skip addition if the new node's data is equal to the head's data
            newNode->data = nullptr;
            delete newNode->data;
            delete newNode;

        }else{
            temp = head_;
            while (temp->next != nullptr && *newNode->data > *temp->next->data) {
                temp = temp->next;
            }

            // If the new node's data is less than the next node's data or at the end of the list
            if(temp->next == nullptr || *newNode->data < *temp->next->data){
                newNode->next = temp->next;
                temp->next = newNode;
                size++;

            }else{
                // Skip addition if the new node's data is equal to the next node's data
                newNode->data = nullptr;
                delete newNode->data;
                delete newNode;
            }
        }
        current = current->next;
    }

    return *this;

}

// Overloads the insertion stream operator to output the elements of the list.
// Starts from the head of the list and iterates through each node, printing its data.
// Prints an empty string if the list is empty.
// Returns the output stream.
template<class T>
inline ostream &operator<<(ostream &cout, const List342<T> &list){
    Node<T> *temp = &list.get_head();

    // If the list is empty, print an empty string
    if(temp == nullptr){
        cout << "";
        return cout;
    }

    // Iterate through the list and print each element's data
    while(temp != nullptr){
        cout << *temp->data;
        temp = temp->next;
    }

    return cout;
}
