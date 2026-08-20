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

private:
  Object *vector_memory;
  int capacity;
  int current_size;
};
#endif
