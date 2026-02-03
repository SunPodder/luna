# UI Module
ui_sources = files(
  'MainWindow.cpp'
)

ui_lib = static_library('luna_ui',
  ui_sources,
  dependencies : [qt6_dep, core_dep],
  include_directories : inc
)

ui_dep = declare_dependency(
  link_with : ui_lib,
  include_directories : include_directories('.')
)
