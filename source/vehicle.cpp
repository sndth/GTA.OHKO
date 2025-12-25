#include "vehicle.hpp"

auto
Vehicle::IsBikeModel(int32_t model) -> bool
{
  switch (model) {
    case PCJ600:
    case Freeway:
    case Sanchez:
    case BMX:
    case Bike:
    case MountainBike:
    case FCR900:
    case NRG500:
    case HPV1000:
    case BF400:
    case Wayfarer:
      return true;

    default:
      return false;
  }
}
