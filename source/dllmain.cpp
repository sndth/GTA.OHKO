// Windows includes
#include <Windows.h>

// Standard includes
#include <fstream>

// Project includes
#include "patches.hpp"
#include "version.hpp"

// External includes
#include <nlohmann/json.hpp>
using json = nlohmann::json;

DWORD WINAPI
InitThread(LPVOID)
{
  try {
    auto ifs = std::ifstream("scripts/SA-OHKO.json"); // WTF?
    auto json = json::parse(ifs);
    auto version = Version::Verify();

    if (!Version::IsSanAndreas(version) || 0x75770 == version.ver_offset) {
      MessageBoxA(
        nullptr, "Unsupported game version", "One Hit Knock Out", MB_ICONERROR);
      return FALSE;
    }

    bool enable = json.value("Enable", true);
    bool die_after_bike_fall = json.value("DieAfterBikeFall", true);

    if (enable) {
      Patches::PatchHealthBar(version.ver_offset);
      Patches::StartOHKOThread(version.ver_offset, die_after_bike_fall);
    }
  } catch (const json::exception& e) {
    MessageBoxA(
      nullptr,
      ("Failed to open SA-OHKO.json: " + std::string(e.what())).c_str(),
      "One Hit Knock Out",
      MB_ICONERROR);
    return FALSE;
  }

  return 0;
}

BOOL APIENTRY
DllMain(HMODULE module, DWORD reason, LPVOID)
{
  if (reason == DLL_PROCESS_ATTACH) {
    DisableThreadLibraryCalls(module);
    CreateThread(nullptr, 0, InitThread, nullptr, 0, nullptr);
  }

  return TRUE;
}
