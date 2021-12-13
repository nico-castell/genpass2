Name:    genpass2
Version: 0.2.3
Release: 1%{?dist}
Summary: Installs a command to generate very secure passwords from the command line.
URL:     https://github.com/nico-castell/genpass2
License: MIT
Vendor:  Nicolás Castellán

Source0: %{name}-%{version}.tar.zst
BuildRequires: meson
BuildRequires: gcc-c++

%description
This is a replacement program for the Golang based genpass proyect. By using C++ and reading the file /dev/urandom directly, this program can achieve absurdly superior speeds when generating very large ammounts of random data.

%prep
%autosetup

%build
%meson --buildtype=release
%meson_build

%install
%meson_install

%files
%{_bindir}/genpass2
%{_mandir}/man1/genpass2.1.*

%changelog
* Mon Dec 13 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 0.2.3-1
- Moved to the meson build system.

* Sat Nov 27 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 0.2.2-1
- Detect if stdout is a pipe, if it is, don't print the newline character.

* Tue Nov 16 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 0.2.1-1
- Added author information in the manpage.

* Mon Oct 25 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 0.2.0-1
- Handle super large password requests by throwing an error. This required setting a password length
  limit of 4,294,967,296 characters.

* Sat Oct 23 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 0.1.6-1
- Fixed passwords ending with an extra space character.

* Thu Oct 14 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 0.1.5-1
- Initialize the main array with zeros.

* Tue Oct 12 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 0.1.4-1
- Fixed the description of RPM packages.

* Tue Oct 12 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 0.1.3-1
- The program now cleans up after itself.

* Mon Oct 11 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 0.1.2-1
- Added information to the manpage.

* Mon Oct 11 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 0.1.1-1
- Fixed a typo and a missing description.

* Mon Oct 11 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 0.1.0-1
- Initial release.
