CC = gcc
CFLAGS = -Wall -Werror -Wpedantic -g
# Source Files
SRC = client.c queue.c
# Object Files
OBJS = $(SRC:.c=.o)

all: client

client: $(OBJS)
	$(CC) $(CFLAGS) -o client $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(all) $(OBJS) client
