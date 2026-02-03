# Process modules
subdir('core')
subdir('plugin')
subdir('lsp')
subdir('editor')
subdir('ai')
subdir('ui')

# Main executable
luna_sources = files('main.cpp')

executable('luna',
  luna_sources,
  dependencies : [
    qt6_dep, 
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
