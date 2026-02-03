# Editor Module
editor_sources = files(
  'Editor.cpp'
)

editor_lib = static_library('luna_editor',
  editor_sources,
  dependencies : [qt6_dep, core_dep],
  include_directories : inc
)

editor_dep = declare_dependency(
  link_with : editor_lib,
  include_directories : include_directories('.')
)
