
project('wayland-mini-compositor',
	'cpp',
	version: '0.0.1')

wayland_server = dependency('wayland-server')

srcs = [
     'src/main.cpp',
     'src/display.cpp',
     'src/resource.cpp',
     'src/compositor.cpp',
     'src/shm.cpp',
     'src/shell.cpp',
     'src/seat.cpp',
     'src/surface.cpp',
     'src/region.cpp'
]

executable('mini-comp',
	srcs,
	dependencies: wayland_server)


subdir('clients')
