# Core Module
core_sources = files(
  'Core.cpp'
)

core_lib = static_library('luna_core',
  core_sources,
  dependencies : [qt6_dep],
  include_directories : inc
)

core_dep = declare_dependency(
  link_with : core_lib,
  include_directories : include_directories('.')
)
