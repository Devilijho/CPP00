sources = Contact.cpp PhoneBook.cpp main.cpp

objects = $(sources:.cpp=.o)

cc = c++

cflags = -Wall -Wextra -Werror -std=c++98

NAME = pbmanager

$(NAME): $(objects)
	$(cc) $(cflags) -o $(NAME) $(objects)

%.o: %.cpp
	$(cc) $(cflags) -c $< -o $@

all: $(NAME)

clean:
	rm -f ${objects}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
