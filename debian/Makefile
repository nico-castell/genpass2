# This is the Makefile to create a debian package

# Standard build
deb-pkg: make-directories
	@cd .. && dpkg-buildpackage -us -uc -b >/dev/null
	@mv ~/genpass2*.buildinfo ~/genpass2*.changes ~/genpass2*.deb DEBS

make-directories:
	@mkdir -p DEBS

# Clean build artifacts
clean:
	@cd .. && rm -rf obj-*-linux-gnu
	@rm -rf debhelper* .debhelper* files genpass2* DEBS
