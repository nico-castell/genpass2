# This is the Makefile to create an rpm package
VERSION = 1.0.2

# Standard build
rpm-pkg: make-source
	@rpmbuild --define "_topdir $(shell pwd)" -bb SPECS/genpass2.spec

make-source: make-directories
	@cd .. && tar --transform "s/^\./genpass2-${VERSION}/" -zcf rpmbuild/SOURCES/genpass2-${VERSION}.tar.gz ./{src,man,meson.build}

make-directories:
	@mkdir -p BUILD RPMS SOURCES SRPMS

# Clean build artifacts
clean:
	@rm -rf BUILD* RPMS SRPMS SOURCES
