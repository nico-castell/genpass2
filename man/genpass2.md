% genpass2(1) 1.0.2
% Nicolás Castellán <cnicolas.developer@gmail.com>
% Dec 2021

<!-- Use:                                                             -->
<!--   pandoc genpass2.1.md -s -t man -o genpass2.1                   -->
<!-- to convert this markdown to groff format                         -->
<!-- Choose from these sections:                                      -->
<!-- 1. Executable programs: Or, shell commands.                      -->
<!-- 2. System calls: Functions provided by the kernel.               -->
<!-- 3. Library calls: Functions within program libraries.            -->
<!-- 4. Special files.                                                -->
<!-- 5. File formats and conventions: For example, “/etc/passwd”.     -->
<!-- 6. Games.                                                        -->
<!-- 7. Miscellaneous: Macro packages and conventions, such as groff. -->
<!-- 8. System administration commands: Usually reserved for root.    -->
<!-- 9. Kernel routines: Not usually installed by default.            -->

# NAME
genpass2 - Uses the device file /dev/urandom to genereate very secure passwords.

# SYNOPSIS
**genpass2**

**genpass2** 20

# DESCRIPTION
**genpass** reads as many characters as specified by the first argument (8 characters if no
arguments are passed) from /dev/urandom and then processes all the data to turn the randomness into
human readable characters.

## Usage
- **Standalone:** You can run it without arguments, and it will default to an 8 character password,
	or you can specify the length as follows:

		genpass2 16

	If you input a negative number (such as `-128`), the program will error and tell you that it's
	not a valid number. Any arguments after the first will be ignored. The maximum number of
	characters the password can have is 4,294,967,296. Why? Because for every character in the
	password, we need a byte in memory.
- **Variable:** This is the recommended way. You store the output in a variable, so the password
		never appears on screen.

		MY_PASS=$(genpass2 16)

- **Clipboard:** You can also put the password in your clipboard using the `xclip` command.

		genpass2 16 | xclip -selection clipboard -i


# EXAMPLES
**genpass2** 20  
G*b9APs=DX^q-(&J@%x@

# EXIT VALUES
**0**
: Success

**1**
: The first argument could not be parsed into a valid number. Make sure the first number is between
  0 and 4,293,967,296, without letters or symbols (including **-**).

**2**
: The program could not allocate enough memory for the password. Make sure you have enough free
  memory; for every character you want to generate, you'll need a byte of free memory.

**3**
: The program failed to open /dev/urandom. Check that the file is enabled by the kernel.

**4**
: The program failed to read from /dev/urandom. Check that your user has permission to read from
  this file.

# COPYRIGHT
Copyright © Nicolás Castellán 2021. License MIT. This software is provided "AS IS", there's no
warrany of any kind.
