# AI Module
ai_sources = files(
  'AiAssist.cpp'
)

ai_lib = static_library('luna_ai',
  ai_sources,
  dependencies : [qt6_dep, core_dep],
  include_directories : inc
)

ai_dep = declare_dependency(
  link_with : ai_lib,
  include_directories : include_directories('.')
)
