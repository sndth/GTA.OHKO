#pragma once

// Standard includes
#include <cstdint>

class Vehicle
{
  enum BikeModels
  {
    PCJ600 = 461,
    Freeway = 463,
    Sanchez = 468,
    BMX = 481,
    Bike = 509,
    MountainBike = 510,
    FCR900 = 521,
    NRG500 = 522,
    HPV1000 = 523,
    BF400 = 581,
    Wayfarer = 586
  };

public:
  auto static IsBikeModel(int32_t model) -> bool;
};
