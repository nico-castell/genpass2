# This is the Makefile to package the project as .tar.gz
VERSION = 0.2.3

# Standard build
tar-pkg: process-program
	@tar --transform "s/^tmp/genpass2-${VERSION}-Linux/" -zcf genpass2-${VERSION}-Linux.tar.gz tmp

# I would use meson, but it's simpler and faster to just compile in this Makefile
process-program: make-directories
	@gzip ../man/genpass2.1 -c >tmp/share/man/man1/genpass2.1.gz
	@c++ -fdiagnostics-color=always -D_FILE_OFFSET_BITS=64 -Wall -Winvalid-pch -Wnon-virtual-dtor -Wextra -O3 -o tmp/bin/genpass2 ../src/main.cpp

make-directories:
	@mkdir -p tmp/{bin,share/man/man1}

# Clean build artifacts
clean:
	@rm -rf tmp genpass2*.tar.gz
