# Copyright (C) 2009-2021 Simon Josefsson

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

DISTCHECK_CONFIGURE_FLAGS = --enable-gtk-doc --enable-gtk-doc-pdf

SUBDIRS = gl liboath oathtool

if ENABLE_PSKC
SUBDIRS += libpskc
SUBDIRS += pskctool
endif

if ENABLE_PAM
SUBDIRS += pam_oath
endif

ACLOCAL_AMFLAGS = -I m4 -I gl/m4

EXTRA_DIST = GNUmakefile .clcopying cfg.mk maint.mk
EXTRA_DIST += build-aux/oath-toolkit-version m4/dummy.m4
EXTRA_DIST += HACKING

# Website
EXTRA_DIST += website/asciidoc.css website/build-website.sh		\
	website/docs.txt website/download.txt website/intro-1.txt	\
	website/intro-2.txt website/config.cfg website/layout.css	\
	website/oath-toolkit.xsl website/style.css

# git-version-gen
EXTRA_DIST += $(top_srcdir)/.version
BUILT_SOURCES = $(top_srcdir)/.version
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@
dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version
