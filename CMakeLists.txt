cmake_minimum_required(VERSION 3.16.0)
# Project started with x86_64 architecture

# Project config
set(PROJ "genpass2")
set(VERS "0.2.0")

project("${PROJ}" VERSION "${VERS}")
add_executable("${PROJ}" "src/main.cpp")

# Use more warnings
target_compile_options(
	"${PROJ}" BEFORE
	PUBLIC -Wall -Wextra
)

# Install
install(
	TARGETS "${PROJ}"
	RUNTIME
	DESTINATION bin
)
install(
	FILES "man/${PROJ}.1"
	DESTINATION share/man/man1
)

# Prepare CPack
# Common variables to all packagers
set(CPACK_PACKAGE_NAME "${PROJ}")
set(CPACK_PACKAGE_VERSION "${VERS}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Installs a command to generate very secure passwords from the command line.")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/nico-castell/genpass2")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_SOURCE_DIR}/assets/description.txt")

# RPM (RHEL-based distros) - Use -DCPACK_BINARY_RPM=ON flag to enable it
set(CPACK_RPM_FILE_NAME "RPM-DEFAULT")
set(CPACK_RPM_PACKAGE_LICENSE "MIT") # SPDF License Identifier
set(CPACK_RPM_CHANGELOG_FILE "${CMAKE_SOURCE_DIR}/assets/changelog.txt")

# DEB (Debian-based distros) - Use -DCPACK_BINARY_DEB=ON flag to enable it
set(CPACK_DEBIAN_FILE_NAME "DEB-DEFAULT")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "$ENV{USER}")

# Use CPack
include(CPack)
