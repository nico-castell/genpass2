# Change log

All significant changes to **genpass2** will be documented here.

- [Released](#released)
	- [Version 1.0.2 - *2021-12-18*](#version-102---2021-12-18)
	- [Version 1.0.1 - *2021-12-16*](#version-101---2021-12-16)
	- [Version 1.0.0 - *2021-12-16*](#version-100---2021-12-16)
	- [Version 0.2.3 - *2021-12-13*](#version-023---2021-12-13)
	- [Version 0.2.2 - *2021-11-27*](#version-022---2021-11-27)
	- [Version 0.2.1 - *2021-11-16*](#version-021---2021-11-16)
	- [Version 0.2.0 - *2021-10-25*](#version-020---2021-10-25)
	- [Version 0.1.6 - *2021-10-23*](#version-016---2021-10-23)
	- [Version 0.1.5 - *2021-10-14*](#version-015---2021-10-14)
	- [Version 0.1.4 - *2021-10-12*](#version-014---2021-10-12)
	- [Version 0.1.3 - *2021-10-12*](#version-013---2021-10-12)
	- [Version 0.1.2 - *2021-10-11*](#version-012---2021-10-11)
	- [Version 0.1.1 - *2021-10-11*](#version-011---2021-10-11)
	- [Version 0.1.0 - *2021-10-11*](#version-010---2021-10-11)

## Released
### Version [1.0.2](https://github.com/nico-castell/genpass2/releases/tag/1.0.2) - *2021-12-18*
The program had no way to handle failing to open or read from */dev/urandom*. That is now handled
by printing an error and exiting. The new error codes **3** and **4** were added to the manpage.

### Version [1.0.1](https://github.com/nico-castell/genpass2/releases/tag/1.0.1) - *2021-12-16*
Well, this is embarrasing. I called `fgets()` instead of `fread()` which meant that the program
didn't always output a complete password, that was fixed. But as if that wasn't enough, the program
would output one more character than requested, so if you ran **genpass2 16** the program would
print a 17 character password, that was fixed too.

### Version [1.0.0](https://github.com/nico-castell/genpass2/releases/tag/1.0.0) - *2021-12-16*
The project was transitioned from C++ to C. This, and some tweaks in how the random data is
processed and dumped to stdout resulted in significant performance improvements. Additionally, CMake
was purged from the project, meaning that it only uses Meson now.

### Version [0.2.3](https://github.com/nico-castell/genpass2/releases/tag/0.2.3) - *2021-12-13*
The build system is now based on meson, CMake was deprecated. Additionally, the methods from .rpm
and .deb packaging were changed to manual builds assisted with Makefiles.

### Version [0.2.2](https://github.com/nico-castell/genpass2/releases/tag/0.2.2) - *2021-11-27*
Detect if the output of the program is not a terminal, if it isn't, don't print a newline character.

### Version [0.2.1](https://github.com/nico-castell/genpass2/releases/tag/0.2.1) - *2021-11-16*
Added author information on the manpage, also started making debian packages.

### Version [0.2.0](https://github.com/nico-castell/genpass2/releases/tag/0.2.0) - *2021-10-25*
Handle super large password requests by throwing an error. This required setting a password length
limit of 4,294,967,296 characters.

### Version [0.1.6](https://github.com/nico-castell/genpass2/releases/tag/0.1.6) - *2021-10-23*
Fixed passwords ending with an extra space character.

### Version [0.1.5](https://github.com/nico-castell/genpass2/releases/tag/0.1.5) - *2021-10-14*
Initialize the *sentence* array with zeros.

### Version [0.1.4](https://github.com/nico-castell/genpass2/releases/tag/0.1.4) - *2021-10-12*
Fixed the description of RPM packages.

### Version [0.1.3](https://github.com/nico-castell/genpass2/releases/tag/0.1.3) - *2021-10-12*
The program now cleans up after itself.

### Version [0.1.2](https://github.com/nico-castell/genpass2/releases/tag/0.1.2) - *2021-10-11*
Added information to the manpage.

### Version [0.1.1](https://github.com/nico-castell/genpass2/releases/tag/0.1.1) - *2021-10-11*
Fixed a typo and a missing description.

### Version 0.1.0 - *2021-10-11*
Initial release.
