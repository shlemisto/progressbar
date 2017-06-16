LIBNAME = libprogressbar
SHARED = $(LIBNAME).a
DYNAMIC = $(LIBNAME).so
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS += -std=c99 -Wimplicit-function-declaration -Wall -Wextra -pedantic

.PHONY: all clean

all: clean $(SHARED) $(DYNAMIC)

$(SHARED): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(DYNAMIC): LDFLAGS += -shared
$(DYNAMIC): $(SRC)
	$(CC) -fPIC -shared -o $@ -c $(CFLAGS) $(SRC)

clean:
	$(RM) $(OBJ) $(SHARED) $(DYNAMIC)
