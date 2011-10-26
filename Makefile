#Customisable stuff here
LINUX_COMPILER = gcc

LIBPURPLE_CFLAGS = -I/usr/include/libpurple
GLIB_CFLAGS = `pkg-config pidgin --cflags --libs`

SOURCES = quickstrike.c
	
#Standard stuff here
.PHONY:	all clean install sourcepackage

all:	quickstrike.so

install:
	cp quickstrike.so /usr/lib/purple-2/
clean:
	rm -f quickstrike.so

quickstrike.so:	${SOURCES}
	${LINUX_COMPILER} ${LIBPURPLE_CFLAGS} -Wall ${GLIB_CFLAGS} -I. -g -O2 -pipe ${SOURCES} -o $@ -shared -fPIC -DPIC

