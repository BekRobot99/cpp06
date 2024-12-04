CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
SRCS = main.cpp Base.cpp 
OBJS = $(SRCS:.cpp=.o)
NAME = Identify_real_type

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
