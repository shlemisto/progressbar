CC = gcc
INCLUDES += -I../
LDFLAGS += -L../ -lprogressbar
CFLAGS += -g -Wall $(INCLUDES) $(LDFLAGS)

SRCS = example.c

OBJS = $(SRCS:.c=.o)

OUT = example

default: clean $(OUT)

$(OUT): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)

clean:
	$(RM) *.o *~ $(OUT)
