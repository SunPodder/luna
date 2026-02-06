# Process modules
subdir('core')
subdir('plugin')
subdir('lsp')
subdir('editor')
subdir('ai')
subdir('ui')

# Main executable
luna_sources = files('main.cpp')

processed_res = qt6.compile_resources(
  sources: 'res/resources.qrc',
)

executable('luna',
  luna_sources,
  processed_res,
  dependencies : [
    qt6_dep,
    termwidget_dep,
    lua_dep,
    sol2_dep,
    core_dep, 
    plugin_dep,
    lsp_dep, 
    editor_dep, 
    ai_dep, 
    ui_dep
  ],
  include_directories : inc,
  install : true
)
