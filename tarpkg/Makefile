# This is the Makefile to package the project as .tar.gz
VERSION = 1.0.0

# Default target
tar-pkg: all
	@tar --transform "s/^tmp/genpass2-${VERSION}-Linux/" -zcf genpass2-${VERSION}-Linux.tar.gz tmp

all: manpage meson-compile

manpage:
	@mkdir -p tmp/share/man/man1
	@cp ../man/genpass2.1 tmp/share/man/man1/genpass2.1

meson-compile:
	@mkdir -p tmp/bin
	@if [ ! -e build ]; then meson setup .. build --buildtype=release; fi
	@meson compile -C build
	@cp build/src/genpass2 tmp/bin

# Clean build artifacts
clean:
	@rm -rf build tmp genpass2-${VERSION}-Linux.tar*
