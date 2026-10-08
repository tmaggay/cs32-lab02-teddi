#include "student.h"
#include <string>
#include <cstring>

Student::Student(const char * const name, int perm) {
  this->perm = perm;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

int Student::getPerm() const {
        return perm;
}

const char * const Student::getName() const {
    return name;
}

void Student::setPerm(const int permNumber) {
    this->perm = permNumber;
}

void Student::setName(const char * const name) {
  if (this->name == name) return;
  
  char* newName = new char[strlen(name) + 1];
  strcpy(newName, name);
  delete[] this->name;
  this->name = newName;
}


Student::Student(const Student &orig) {
    this->perm = orig.perm;
    this->name = new char[strlen(orig.name) + 1];
    strcpy(this->name, orig.name); 
}

Student::~Student() {
    delete[] name;

}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  delete[] this->name;
  this->perm = right.perm;
  this->name = new char[strlen(right.name) + 1];
  strcpy(this->name, right.name);

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  return "tostring stub";
}

