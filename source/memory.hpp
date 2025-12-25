#pragma once

// Standard includes
#include <cstdint>

class Memory
{
public:
  template<typename T>
  auto static ReadMemory(uintptr_t address) -> T
  {
    return *reinterpret_cast<T*>(address);
  }

  template<typename T>
  auto static inline WriteMemory(uintptr_t address, T new_value) -> void
  {
    *reinterpret_cast<T*>(address) = new_value;
  }
};
