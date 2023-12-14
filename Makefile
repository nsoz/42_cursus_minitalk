# Compiler and Compiler Flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Targets and their names
SERVER_NAME = server
CLIENT_NAME = client

# Rule to make all (default rule)
all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME):
	$(CC) $(CFLAGS) client.c -o $(CLIENT_NAME)

$(SERVER_NAME):
	$(CC) $(CFLAGS) server.c -o $(SERVER_NAME)

# Phony targets
.PHONY: all clean fclean re

# Rule to clean the project
clean:
	rm -rf $(CLIENT_NAME) $(SERVER_NAME)

# Rule to fully clean the project
fclean: clean

# Rule to remake the project
re: fclean all
