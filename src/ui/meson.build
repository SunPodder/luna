# UI Module

processed_files = qt6.preprocess(
  moc_headers : [
    'MainWindow.hpp',
    'widgets/TopBar.hpp',
    'widgets/AiPanel.hpp',
    'widgets/EditorPanel.hpp',
    'widgets/TerminalPanel.hpp',
    'widgets/SidePanel.hpp',
    'widgets/ToolsPanel.hpp',
    'widgets/StatusBar.hpp',
  ],
  dependencies: qt6_dep
)


# Import widget sources from widgets/meson.build
subdir('widgets')
ui_sources = files('MainWindow.cpp') + ui_widget_sources

ui_lib = static_library('luna_ui',
  ui_sources, processed_files,
  dependencies : [qt6_dep, core_dep],
  include_directories : inc
)

ui_dep = declare_dependency(
  link_with : ui_lib,
  include_directories : include_directories('.')
)
