project('genpass2', 'cpp',
	version: '0.2.3',
	meson_version: '>= 0.50.0',
	default_options: [ 'warning_level=2' ]
)

executable(
	meson.project_name(),
	'src/main.cpp',
	install: true
)

if build_machine.system() == 'windows'
	message('This project is not meant to be run on Windows')
endif

install_man('man/genpass2.1')
