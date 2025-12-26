#pragma once

#include <filesystem>

class Config
{
  struct OHKOConfig
  {
    bool enable = true;
    bool die_after_bike_fall = true;
  };

  inline static OHKOConfig m_config_;

public:
  auto static GetConfig() -> OHKOConfig&;
  auto static FindConfig() -> std::filesystem::path;
  auto static LoadConfig(const std::filesystem::path& path) -> OHKOConfig;
};
