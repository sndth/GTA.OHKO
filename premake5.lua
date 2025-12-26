workspace("SA.OHKO")
  -- Common settings
  location("build")
  cppdialect("C++latest")
  staticruntime("On")
  multiprocessorcompile("On")

  defines {
    "_CRT_NON_CONFORMING_SWPRINTFS",
    "GTASA",
    "GTAGAME_NAME=\"San Andreas\"",
    "GTAGAME_ABBR=\"SA\"",
    "GTAGAME_ABBRLOW=\"sa\"",
    "GTAGAME_PROTAGONISTNAME=\"CJ\"",
    "GTAGAME_CITYNAME=\"San Andreas\"",
    "PLUGIN_SGV_10US",
    "RW"
  } libdirs {
    "extern/plugin-sdk/output/lib"
  } includedirs {
    "extern",
    "extern/plugin-sdk/plugin_sa",
    "extern/plugin-sdk/plugin_sa/game_sa",
    "extern/plugin-sdk/plugin_sa/game_sa/rw",
    "extern/plugin-sdk/shared",
    "extern/plugin-sdk/shared/game"
  } configurations {
    "Debug",
    "Release"
  }

  -- Project settings
  project("SA.OHKO")
    kind("SharedLib")
    targetextension(".asi")

    files {
      "source/**.cpp",
      "source/**.hpp"
    }

    -- Filter settings
    filter "configurations:Debug"
      links("plugin_d")
      symbols("Full")

    filter "configurations:Release"
      links("plugin")
      optimize("Full")
