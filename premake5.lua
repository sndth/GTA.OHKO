workspace("GTA.OHKO")
  -- Common settings
  kind("SharedLib")
  location("build")
  cppdialect("C++latest")
  staticruntime("On")
  targetextension(".asi")
  multiprocessorcompile("On")

  defines {
    "RW",
    "_CRT_NON_CONFORMING_SWPRINTFS"
  } libdirs {
    "extern/plugin-sdk/output/lib"
  } includedirs {
    "extern",
    "extern/plugin-sdk/shared",
    "extern/plugin-sdk/shared/game"
  } configurations {
    "Debug",
    "Release"
  }

  -- Filter settings
  filter("configurations:Debug")
    symbols("Full")

  filter("configurations:Release")
    optimize("Full")

  -- Project settings
  project("SA.OHKO")
    files {
      "source/game_sa/**.cpp",
      "source/game_sa/**.json"
    } defines {
      "GTASA",
      "GTAGAME_NAME=\"San Andreas\"",
      "GTAGAME_ABBR=\"SA\"",
      "GTAGAME_ABBRLOW=\"sa\"",
      "GTAGAME_PROTAGONISTNAME=\"CJ\"",
      "GTAGAME_CITYNAME=\"San Andreas\"",
      "PLUGIN_SGV_10US"
    } includedirs {
      "extern/plugin-sdk/plugin_sa",
      "extern/plugin-sdk/plugin_sa/game_sa",
      "extern/plugin-sdk/plugin_sa/game_sa/rw"
    }

    -- Filter settings
    filter("configurations:Debug")
      links("Plugin_d")

    filter("configurations:Release")
      links("Plugin")
