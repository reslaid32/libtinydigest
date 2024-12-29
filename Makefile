# Define the output directories
OUTDIR = build
OBJDIR = $(OUTDIR)/obj
BINDIR = $(OUTDIR)/bin
LIBDIR = $(OUTDIR)/lib
INCDIR = include
SRCDIR = src
TESTDIR = tests
# EXAMPLESDIR = examples

# Set the compiler and flags
CC = gcc
CCFLAGS = -Wall -fPIC
LDFLAGS = -L$(LIBDIR)

ifeq ($(shell uname), Linux)
  LIBEXT = .so
  APPEXT = 
else
  LIBEXT = .dll
  APPEXT = .exe
endif

# Default target
# Target for building libraries only
only-lib: libraries

# Target for building all project (with tests)
all: libraries

# Create directories if they don't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

$(LIBDIR):
	mkdir -p $(LIBDIR)

# Build libraries
libraries: $(OBJDIR) $(LIBDIR)
	@echo "Building tinydigest library..."
	$(CC) $(CCFLAGS) -I$(INCDIR) -c $(SRCDIR)/crc32.c -o $(OBJDIR)/crc32.o
	$(CC) $(CCFLAGS) -I$(INCDIR) -c $(SRCDIR)/sha256.c -o $(OBJDIR)/sha256.o
	$(CC) $(CCFLAGS) -I$(INCDIR) -c $(SRCDIR)/sha512.c -o $(OBJDIR)/sha512.o
	$(CC) -shared $(OBJDIR)/crc32.o \
			$(OBJDIR)/sha256.o $(OBJDIR)/sha512.o -o $(LIBDIR)/libtinydigest$(LIBEXT)

install: libraries
	@echo "Installing libraries, and headers..."
	mkdir -p $(DESTDIR)/lib
	mkdir -p $(DESTDIR)/include/tinydigest

	@if [ -f $(LIBDIR)/libtinydigest$(LIBEXT) ]; then \
		cp $(LIBDIR)/libtinydigest$(LIBEXT) $(DESTDIR)/lib/; \
	else \
		echo "Library not found: $(LIBDIR)/libtinydigest$(LIBEXT)"; \
	fi

	@if [ -d $(INCDIR)/tinydigest ]; then \
		cp $(INCDIR)/tinydigest/*.h $(DESTDIR)/include/tinydigest/; \
	else \
		echo "Header files not found: $(INCDIR)/tinydigest/*.h"; \
	fi

uninstall:
	@echo "Uninstalling libraries, and headers..."
	rm -f $(DESTDIR)/lib/libtinydigest$(LIBEXT)
	rm -rf $(DESTDIR)/include/tinydigest

reinstall: uninstall install

# Clean up files
clean-objs:
	rm -rf $(OBJDIR)

# clean-bins:
# 	rm -rf $(BINDIR)

clean-libs:
	rm -rf $(LIBDIR)

clean-all: clean-objs clean-bins clean-libs

clean: clean-all

.PHONY: all only-lib libraries clean-objs clean-libs clean-all clean install uninstall reinstall