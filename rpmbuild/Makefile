# This is the Makefile to create an rpm package
VERSION = 0.2.3

# Standard build
rpm-pkg: make-directories
	@cd .. && tar --transform "s/^\./genpass2-${VERSION}/" -zcf rpmbuild/SOURCES/genpass2-${VERSION}.tar.gz ./{src,man,meson.build}
	@rpmbuild --define "_topdir $(shell pwd)" --quiet -bb SPECS/genpass2.spec 2>/dev/null

make-directories:
	@mkdir -p BUILD RPMS SOURCES SRPMS

# Clean build artifacts
clean:
	@rm -rf BUILD* RPMS SRPMS SOURCES
