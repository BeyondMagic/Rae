#---------------------------------------------
# -- Program defaults.

NAME_PROGRAM = rae
VERSION      = 1.0.0

#OBJECTS = main.o

# The program's version


#---------------------------------------------
# -- For installations.

ifndef DESTDIR
DESTDIR = ~/.local
endif

#PREFIX = /usr/local
#MANPREFIX = $(PREFIX)/share/man
#EGPREFIX = $(PREFIX)/share/doc/$(NAME_PROGRAM)/examples

#---------------------------------------------
# -- CPP version.

CPP_VERSION = -std=c++2b
#CPP_VERSION := -std=c++2b

#---------------------------------------------
# -- Debugging.

#CPP_FLAGS := -ggdb

#---------------------------------------------
# -- Warnings we *need* to see.

CPP_FLAGS := -O3

CPP_FLAGS := $(CPP_FLAGS) -Wall

CPP_FLAGS := $(CPP_FLAGS) -Werror

CPP_FLAGS := $(CPP_FLAGS) -Wextra

CPP_FLAGS := $(CPP_FLAGS) -pedantic

CPP_FLAGS := $(CPP_FLAGS) -Wconversion

CPP_FLAGS := $(CPP_FLAGS) -Wsign-conversion

#---------------------------------------------
# -- Compile-time limits.

CPP_FLAGS := $(CPP_FLAGS) -fconstexpr-ops-limit=1000000000

CPP_FLAGS := $(CPP_FLAGS) -fconstexpr-loop-limit=100000000

#------------------------------------------------
# -- Sanitisers.

CPP_EXTRA := $(CPP_EXTRA) -fsanitize-undefined-trap-on-error

CPP_EXTRA := $(CPP_EXTRA) -fsanitize-address-use-after-scope

CPP_EXTRA := $(CPP_EXTRA) -fsanitize=address
CPP_EXTRA := $(CPP_EXTRA),undefined
#CPP_EXTRA := $(CPP_EXTRA),nullability
#CPP_EXTRA := $(CPP_EXTRA),implicit-integer-truncation
#CPP_EXTRA := $(CPP_EXTRA),implicit-integer-arithmetic-value-change
#CPP_EXTRA := $(CPP_EXTRA),implicit-conversion
#CPP_EXTRA := $(CPP_EXTRA),integer

#---------------------------------------------
# -- Extra libraries to be compiled.

CPP_LIBS = -lfmt `pkg-config --libs --cflags Magick++`
