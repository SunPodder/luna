# Plugin Module
plugin_sources = files(
  'PluginManager.cpp'
)

plugin_lib = static_library('luna_plugin',
  plugin_sources,
  dependencies : [qt6_dep, core_dep, lua_dep, sol2_dep], # Plugin often relies on core types
  include_directories : inc
)

plugin_dep = declare_dependency(
  link_with : plugin_lib,
  include_directories : include_directories('.'),
  dependencies : [lua_dep, sol2_dep]
)
