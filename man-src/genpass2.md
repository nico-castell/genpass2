% genpass2(1) 0.1.0
% Nicolás Castellán
% Oct 2021

<!-- Use:                                                             -->
<!--   pandoc binme.1.md -s -t man -o binme.1                         -->
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

# EXAMPLES
**genpass2** 20  
G*b9APs=DX^q-(&J@%x@

# EXIT VALUES
**0**
: Success

**1**
: The first argument could not be parsed into a valid number.

# COPYRIGHT
Copyright © Nicolás Castellán 2021. License MIT. This software is provided "AS IS", there's no
warrany of any kind.