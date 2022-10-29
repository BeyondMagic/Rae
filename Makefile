.POSIX:

include config.mk

#---------------------------------------------

all: build

#-----------------------------------------------

install:
	cp    -f ./distribution/$(NAME_PROGRAM)-$(VERSION) ${DESTDIR}/distribution/$(NAME_PROGRAM)

clean:
	rm    -r distribution

uninstall:
	rm    -f ${DESTDIR}/distribution/$(NAME_PROGRAM)

optimise:
	mkdir -p ./distribution
	g++   ./source/$(NAME_PROGRAM).c++ $(CPP_VERSION) $(CPP_FLAGS) $(CPP_LIBS) -o ./distribution/$(NAME_PROGRAM)-$(VERSION)

build:
	mkdir -p ./distribution
	g++   ./source/$(NAME_PROGRAM).c++ $(CPP_VERSION) $(CPP_FLAGS) $(CPP_EXTRA) $(CPP_LIBS) -o ./distribution/$(NAME_PROGRAM)-$(VERSION)

.PHONY: all build install clean uninstall optimise
