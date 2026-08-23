#ifndef VECTOR_H
#define VECTOR_H

template <typename Object> class Vector {
public:
  // Default Constructor
  Vector() : vector_memory(nullptr), capacity(0), current_size(0) {}

  // Destructor
  ~Vector() { delete[] vector_memory; }

  // Copy Constructor
  Vector(const Vector &rhs) {
    vector_memory = new Object[rhs.capacity];
    capacity = rhs.capacity;
    current_size = rhs.current_size;

    for (int member = 0; member < current_size; ++member) {
      vector_memory[member] = rhs.vector_memory[member];
    }
  }

  // Copy assignment Operator=
  Vector &operator=(const Vector &rhs) {
    if (this != &rhs) {
      delete[] this->vector_memory;
      vector_memory = new Object[rhs.capacity];
      capacity = rhs.capacity;
      current_size = rhs.current_size;

      for (int member = 0; member < current_size; ++member) {
        vector_memory[member] = rhs.vector_memory[member];
      }
    }
    return *this;
  }

  // Move constructor
  Vector(Vector &&rhs) {
    this->vector_memory = rhs.vector_memory;
    this->capacity = rhs.capacity;
    this->current_size = rhs.current_size;
    rhs.vector_memory = nullptr;
    rhs.capacity = 0;
    rhs.current_size = 0;
  }

  // Move assignment operator
  Vector &operator=(Vector &&rhs) {
    if (this != &rhs) {
      delete[] this->vector_memory;
      this->vector_memory = rhs.vector_memory;
      capacity = rhs.capacity;
      current_size = rhs.current_size;

      rhs.vector_memory = nullptr;
      rhs.capacity = 0;
      rhs.current_size = 0;
    }
    return *this;
  }
  // Reserve function
  void reserve(int newCapacity) {
    if (newCapacity <= capacity) {
      return;
    }
    Object *new_vector_memory;
    new_vector_memory = new Object[newCapacity];

    for (int i = 0; i < current_size; ++i) {
      new_vector_memory[i] = vector_memory[i];
    }

    delete[] vector_memory;
    vector_memory = new_vector_memory;
    capacity = newCapacity;
  }

  // Resize function
  void resize(int newSize) {
    if (newSize > capacity) {
      reserve(newSize);
    }
    current_size = newSize;
  }
  // Function to add element add the end of the vector
  void push_back(Object newElement) {
    if (current_size == capacity) {
      reserve(capacity * 2 + 1);
    }
    current_size++;
    vector_memory[current_size - 1] = newElement;
  }
  // Function to delete last elemnt of the vector
  void pop_back() {
    if (current_size <= 0) {
      return;
    }
    current_size--;
  }

  int size() const { return current_size; }

  // Method overloading for operator[]
  // Accessor
  const Object &operator[](int index) const { return vector_memory[index]; }
  // Mutator
  Object &operator[](int index) { return vector_memory[index]; }

private:
  Object *vector_memory;
  int capacity;
  int current_size;
};
#endif
