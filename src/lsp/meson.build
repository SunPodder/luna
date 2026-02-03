# LSP Module
lsp_sources = files(
  'LspClient.cpp'
)

lsp_lib = static_library('luna_lsp',
  lsp_sources,
  dependencies : [qt6_dep, core_dep],
  include_directories : inc
)

lsp_dep = declare_dependency(
  link_with : lsp_lib,
  include_directories : include_directories('.')
)
