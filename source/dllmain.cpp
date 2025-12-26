// Windows includes
#include <Windows.h>

// Project includes
#include "config.hpp"
#include "patches.hpp"
#include "version.hpp"

DWORD WINAPI
InitThread(LPVOID)
{
  try {
    auto const version = Version::Verify(Version::GameName::GTASA);
    if (version == 0x75770) {
      MessageBoxA(
        nullptr, "Unsupported game version", "One Hit Knock Out", MB_ICONERROR);
      return FALSE;
    }

    auto const config_path = Config::FindConfig();
    if (config_path.empty()) {
      MessageBoxA(
        nullptr, "SA.OHKO.json not found", "One Hit Knock Out", MB_ICONERROR);
      return FALSE;
    }

    auto const config_data = Config::LoadConfig(config_path);
    if (config_data.enable) {
      Patches::PatchHealthBar(version);
      Patches::StartOHKOThread(version);
    }
  } catch (const std::exception& e) {
    MessageBoxA(nullptr, e.what(), "One Hit Knock Out", MB_ICONERROR);
    return FALSE;
  }

  return TRUE;
}

BOOL APIENTRY
DllMain(HMODULE module, DWORD reason, LPVOID)
{
  if (reason == DLL_PROCESS_ATTACH) {
    MessageBoxA(nullptr, "a", "One Hit Knock Out", MB_ICONERROR);

    DisableThreadLibraryCalls(module);
    CreateThread(nullptr, 0, InitThread, nullptr, 0, nullptr);
  }

  return TRUE;
}
