Name:    genpass2
Version: 1.0.2
Release: 1
Summary: Installs a command to generate very secure passwords from the command line.
URL:     https://github.com/nico-castell/genpass2
License: MIT
Vendor:  Nicolás Castellán

%define _build_id_links none
Source0: %{name}-%{version}.tar.gz
BuildRequires: meson
BuildRequires: gcc

%description
This is a replacement program for the Golang based genpass proyect. By using C and reading the file /dev/urandom directly, this program can achieve absurdly superior speeds when generating very large ammounts of random data.

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
* Sat Dec 18 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 1.0.2-1
- Handled possible failure points in fopen() and fread() functions by making the program stop
  and return an error code.
- The manpage now lists error codes 3 and 4 for failing to open /dev/urandom and failing to read
  from /dev/urandom, respectively.

* Thu Dec 16 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 1.0.1-1
- Fixed wrong function call, from fgets() to fread(), this was causing the program to generate
  incomplete passwords.
- Fixed program outputting an extra character, if you asked for a 16 character password, it
  would print a 17 character password.

* Thu Dec 16 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 1.0.0-1
- The project is no longer written in C++, it was rewritten in C.
- Tweaks in how the data is processed and printed resulted in significant performance improvements.
- CMake was purged from the project, it only uses Meson now.

* Mon Dec 13 2021 Nicolás Castellán <cnicolas.developer@gmail.com> - 0.2.3-1
- Moved to the meson build system.
- Changed method for rpm packaging from CPack to manual packaging.
- Chenged method for deb packaging from CPack to manual packaging.

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
