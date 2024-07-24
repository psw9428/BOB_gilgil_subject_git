CC = gcc
CFLAGS = -Wall
SRCS = add-nbo.c
OBJS = $(SRCS:.c=.o)
TARGET = add-nbo

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean :
	rm -f $(OBJS) $(TARGET)

.PHONY : all clean

