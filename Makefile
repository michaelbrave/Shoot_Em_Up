NAME = ft_retro

all: $(NAME)

$(NAME):
		@clang++ -std=c++2a -lncurses -g -Wall -Werror -Wextra Projectile.cpp Enemy.cpp Player.cpp GameObject.cpp GameWorld.cpp mainMenu.cpp input.cpp render.cpp BigBoss.cpp main.cpp -o $(NAME)

fclean:
		@/bin/rm -f $(NAME)

re: fclean all
