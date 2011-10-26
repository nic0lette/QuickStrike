#Customisable stuff here
LINUX_COMPILER = gcc

PLUGIN_CFLAGS = `pkg-config pidgin --cflags --libs`

SOURCES = quickstrike.c
	
#Standard stuff here
.PHONY:	all clean install sourcepackage

all:	quickstrike.so

install:
	cp quickstrike.so /usr/lib/purple-2/
clean:
	rm -f quickstrike.so

quickstrike.so:	${SOURCES}
	${LINUX_COMPILER} ${PLUGIN_CFLAGS} -Wall -I. -g -O2 -pipe ${SOURCES} -o $@ -shared -fPIC -DPIC

