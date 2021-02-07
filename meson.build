
project('wayland-mini-compositor',
	'cpp',
	version: '0.0.1')

wayland_server = dependency('wayland-server')

executable('mini-comp',
	[
		'src/main.cpp',
		'src/display.cpp',
		'src/resource.cpp',
		'src/compositor.cpp'
	],
	dependencies: wayland_server)
