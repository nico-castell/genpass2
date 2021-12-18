# This is the Makefile to package the project as .tar.gz
VERSION = 1.0.2

# Change this value if you want to do a cross compilation
ARCH = $(shell uname -m)

# Default target
tar-pkg: all
	@tar --transform "s/^tmp-${ARCH}/genpass2-${VERSION}-${ARCH}/" -zcf genpass2-${VERSION}-${ARCH}.tar.gz tmp-${ARCH}

all: manpage meson-compile

manpage:
	mkdir -p tmp-${ARCH}/share/man/man1
	cp ../man/genpass2.1 tmp-${ARCH}/share/man/man1/genpass2.1

meson-compile:
	@mkdir -p tmp-${ARCH}/bin
ifeq (${ARCH}, $(shell uname -m))
	@if [ ! -e build-${ARCH} ]; then meson setup .. build-${ARCH} --buildtype=release; fi
else
	@if [ ! -e build-${ARCH} ]; then meson setup .. build-${ARCH} --buildtype=release --cross-file ../${ARCH}.build --cross-file ../cross.build; fi
endif
	@meson compile -C build-${ARCH}
	@cp build-${ARCH}/src/genpass2 tmp-${ARCH}/bin

# Clean build artifacts
clean:
	@rm -rf build-${ARCH} tmp-${ARCH} genpass2-${VERSION}-${ARCH}.tar*
