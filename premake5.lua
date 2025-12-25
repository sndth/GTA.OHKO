workspace("SA-OHKO")
  -- Common settings
  location("build")
  cppdialect("C++latest")
  staticruntime("On")
  multiprocessorcompile("On")

  includedirs {
    "extern"
  } configurations {
    "Debug",
    "Release"
  }

  -- Filter settings
  filter "configurations:Debug"
    symbols("Full")

  filter "configurations:Release"
    optimize("Full")

  -- Project settings
  project("SA-OHKO")
    kind("SharedLib")
    targetextension(".asi")

    files {
      "source/**.cpp",
      "source/**.hpp"
    }
