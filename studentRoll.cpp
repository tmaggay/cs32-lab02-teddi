#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node* newNode = new Node;
  newNode->s = new Student(s);
  newNode->next = NULL;
  

  if (tail == NULL) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }

}

std::string StudentRoll::toString() const {
  std::string result = "[";
  Node* current = head;
  while (current != NULL) {
    result += current->s->toString();
    if (current->next != NULL) {
      result += ",";
    }

    current = current->next;
  }
  result += "]";
  return result;

}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;
  Node* current = orig.head;
  while (current != NULL) {
    this->insertAtTail(*(current->s));
    current = current->next;
  
  }
}

StudentRoll::~StudentRoll() {
  Node* current = head;
  while (current != NULL) {
    Node* nextNode = current->next;
    delete current->s;
    delete current;
    current = nextNode;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)
  if (&right == this)
    return (*this);

  Node* current = head;
  while (current != NULL) {
    Node* nextNode = current->next;
    delete current->s;
    delete current;
    current = nextNode;
  }
  head = tail = NULL;


  current = right.head;
  while (current != NULL) {
    this->insertAtTail(*(current->s));
    current = current->next;
  }


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}






