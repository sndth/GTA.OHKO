#pragma once

// Standard includes
#include <cstdint>

class Version
{
  enum class GameName
  {
    UNDEFINED,
    SAN_ANDREAS
  };

  struct GameInfo
  {
    int32_t ver_offset;
    GameName game_title;

    GameInfo()
      : ver_offset(0)
      , game_title(GameName::UNDEFINED)
    {
    }
  };

public:
  auto static Verify() -> GameInfo;
  auto static IsSanAndreas(const GameInfo& info) -> bool;
};
