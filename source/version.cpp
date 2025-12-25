// Project includes
#include "Memory.hpp"
#include "Version.hpp"

auto
Version::Verify() -> GameInfo
{
  // Todo - WTF is this?!
  auto info = GameInfo{};
  auto SA_Check = [&]() -> GameInfo {
    if (0x94BF == Memory::ReadMemory<uint32_t>(0x0082457C)) {
      info.game_title = GameName::SAN_ANDREAS;
    } else if (0x94BF == Memory::ReadMemory<uint32_t>(0x008245BC)) {
      info.game_title = GameName::SAN_ANDREAS;
    } else if (0x94BF == Memory::ReadMemory<uint32_t>(0x008252FC)) {
      info.ver_offset = 0x2680;
      info.game_title = GameName::SAN_ANDREAS;
    } else if (0x94BF == Memory::ReadMemory<uint32_t>(0x0082533C)) {
      info.ver_offset = 0x2680;
      info.game_title = GameName::SAN_ANDREAS;
    } else if (0x94BF == Memory::ReadMemory<uint32_t>(0x0085EC4A)) {
      info.ver_offset = 0x75130;
      info.game_title = GameName::SAN_ANDREAS;
    } else if (0x94BF == Memory::ReadMemory<uint32_t>(0x0085DEDA)) {
      info.ver_offset = 0x75770;
      info.game_title = GameName::SAN_ANDREAS;
    }

    return info;
  };

  return SA_Check();
}

auto
Version::IsSanAndreas(const GameInfo& info) -> bool
{
  return info.game_title == GameName::SAN_ANDREAS;
}
