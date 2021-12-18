project('genpass2', 'c',
	version: '1.0.2',
	meson_version: '>= 0.50.0',
	default_options: [ 'warning_level=2' ]
)

if build_machine.system() == 'windows'
	warning('This project is not meant to be run on Windows')
endif

subdir('src')
subdir('man')
