# CLI Password Generator 2
[![Commits since last release](https://img.shields.io/github/commits-since/nico-castell/genpass2/latest?label=Commits%20since%20last%20release&color=informational&logo=Git&logoColor=white&style=flat-square)](https://github.com/nico-castell/genpass2/commits)
[![Release](https://img.shields.io/github/v/release/nico-castell/genpass2?label=Release&color=informational&logo=GitHub&logoColor=white&style=flat-square)](https://github.com/nico-castell/genpass2/releases)
[![License](https://img.shields.io/github/license/nico-castell/genpass2?label=License&color=informational&logo=Open%20Source%20Initiative&logoColor=white&style=flat-square)](LICENSE)
[![Lines of code](https://img.shields.io/tokei/lines/github/nico-castell/genpass2?label=Lines%20of%20code&color=informational&logo=C&logoColor=white&style=flat-square)](https://github.com/nico-castell/genpass2)
[![CodeQL](https://img.shields.io/github/workflow/status/nico-castell/genpass2/CodeQL?label=CodeQL&logo=GitHub%20Actions&logoColor=white&style=flat-square)](https://github.com/nico-castell/genpass2/actions/workflows/codeql-analysis.yml)

This is a replacement program for the [Golang](https://golang.org/) based
[genpass](https://github.com/nico-castell/genpass) proyect. By using
[C](https://en.wikipedia.org/wiki/C_(programming_language)) and reading the file `/dev/urandom`
directly, this program can achieve absurdly superior speeds when generating very large ammounts of
random data.

Note that, unlike [genpass](https://github.com/nico-castell/genpass), this program does not run on
Windows.

## Usage
- **Standalone:** You can run it without arguments, and it will default to an 8 character password,
	or you can specify the length as follows:
	```shell
	genpass2 16
	```
	If you input a negative number (such as `-128`), the program will error and tell you that it's
	not a valid number. Any arguments after the first will be ignored. The maximum number of
	characters the password can have is 4,294,967,296. Why? Because for every character in the
	password, we need a byte in memory.
- **Variable:** This is the recommended way. You store the output in a variable, so the password
	never appears on screen.
	```shell
	MY_PASS=$(genpass2 16)
	```
- **Clipboard:** You can also put the password in your clipboard using the `xclip` command.
	```shell
	genpass2 16 | xclip -selection clipboard -i
	```
- **Manpage:** You can view the manpage if you need to see this information in the command line.
	```shell
	man genpass2
	```

---
## Build instructions and installation
To build this project you will need two things, [Meson](https://mesonbuild.com/index.html) and a 
C compiler.

1. First, clone this repository and change directory into it:
	```shell
	git clone https://github.com/nico-castell/genpass2.git
	cd genpass2
	```
2. Second, prepare the build folder using meson:
	```shell
	meson --buildtype=release build
	```
	You can also use the following flag:
	```shell
	--prefix=~/.local  # To install this program for the current user
	```
3. Use meson to build and install the project:
	```shell
	meson install -C build
	```

---
## Packaging the project and installing it
Thanks to the use of Makefiles, packaging the project as a .rpm or .deb is very easy. Just follow
these steps:

- If you're on Fedora or another RHEL based OS:
	```bash
	cd rpmbuild
	make
	```

	If you then want to install the package:
	```bash
	sudo dnf install ./RPMS/$(uname -m)/genpass2-1.0.2-1.*.rpm
	```

	If you want to remove the package:
	```bash
	sudo dnf remove genpass2
	```

	You will need to have `rpmdevtools` installed to build the package.

- If you're on Debian or another Debian based OS:
	```bash
	cd debian
	make
	```

	If you then want to install the package:
	```bash
	sudo apt install ./DEBS/genpass2_1.0.2-1*.deb
	```

	If you want to remove the package:
	```bash
	sudo apt remove genpass2
	```

	You will need to have `dpkg-dev` and `debhelper` installed to build the package.

- You can also use the tarpkg directory to build a tar archive you can deploy in /usr/local in case
	your system doesn't use either dnf (rpm) or apt (dpkg).
	```bash
	cd tarpkg
	make
	```

---
## About
This program and this repository are availabe under an [MIT License](LICENSE).
