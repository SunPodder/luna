project('luna', 'cpp',
  version : '0.1.0',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

# Dependencies
qt6 = import('qt6')
qt6_dep = dependency('qt6', modules: ['Core', 'Gui', 'Widgets', 'OpenGL', 'Svg', 'SvgWidgets'])
gl_dep = dependency('gl', required: false)

# Include directories
inc = include_directories('src')

subdir('src')
subdir('tests')
