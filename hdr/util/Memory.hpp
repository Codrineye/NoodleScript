#pragma once

// Dependencies
#include <vector>

namespace ns {
  /*
   * Method in which ns uses memory
  */
  class Memory {
  public:
    /*
     * Constructor for memory
     * Deconstructor for memory
    */
    Memory();
    ~Memory();

    /*
     * Template for how to
     * create a template
    */
    template <typename Type>
    Type* create() {
      Type* pointer = new Type();
      pointers.push_back(pointer);
      return pointer;
    }

    /*
     * clear memory
    */
    void clear();

    /*
     * return the const pointer count
    */
    int getPointerCount() const;
  private:
    /*
     * vector containing all pointers
    */
    std::vector<void*> pointers;
  };

  extern Memory* globalMemory;
}