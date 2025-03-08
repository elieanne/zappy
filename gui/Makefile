##
## EPITECH PROJECT, 2023
## zappy
## File description:
## Makefile
##

SRC_COMPONENTS	=	Window/Window.cpp \
					Buttons/Button.cpp \
					Parallax/Parallax.cpp \
					PanelBar/PanelBar.cpp \
					TextBox/TextBox.cpp \
					SoundBox/SoundBox.cpp \
					SoundBox/SoundPlayers.cpp \

SRC_SCENE	=	Settings/SceneSettings.cpp \
				Game/SceneGame.cpp \
				Game/Display/Display.cpp \
				Game/Display/DisplayTile.cpp \
				Game/Event/Event.cpp \
				Game/Event/MapMove.cpp \
				Game/Event/Selected.cpp \
				Menu/SceneMenu.cpp \
				Manager/SceneManager.cpp \
				Skins/SceneSkins.cpp \
				Win/SceneWin.cpp

SRC_OBJECTS	=	Foods/Foods.cpp \
				Stones/Stones.cpp \

SRC_CHARACTERS	=	Players/Players.cpp \
					Players/Orientation.cpp \
					Eggs/Eggs.cpp \

SRC_ERROR	=	Errors.cpp \

SRC_NETWORK	=	Network.cpp \
				Handlers/Handler.cpp \
				Handlers/Commands/bct.cpp \
				Handlers/Commands/msz.cpp \
				Handlers/Commands/pbc.cpp \
				Handlers/Commands/pdi.cpp \
				Handlers/Commands/pdr.cpp \
				Handlers/Commands/pex.cpp \
				Handlers/Commands/pfk.cpp \
				Handlers/Commands/pgt.cpp \
				Handlers/Commands/pic.cpp \
				Handlers/Commands/pie.cpp \
				Handlers/Commands/pin.cpp \
				Handlers/Commands/plv.cpp \
				Handlers/Commands/pnw.cpp \
				Handlers/Commands/ppo.cpp \
				Handlers/Commands/tna.cpp \
				Handlers/Commands/enw.cpp \
				Handlers/Commands/ebo.cpp \
				Handlers/Commands/edi.cpp \
				Handlers/Commands/sgt.cpp \
				Handlers/Commands/seg.cpp \
				Handlers/Commands/smg.cpp \
				Handlers/Commands/sst.cpp \
				Handlers/Commands/suc.cpp \
				Handlers/Commands/sbp.cpp \

SRC_GAME	=	Map/Map.cpp	\
				Map/Tile.cpp	\
				Camera/Camera.cpp	\
				ItemDrawer/ItemDrawer.cpp	\

SRC_DATA	=	Data.cpp	\

SRC_TEAMS	=	Team.cpp	\

SRC_MAIN	=	Main.cpp	\
				Arguments/Arguments.cpp \

SRC	=	$(addprefix Components/, $(SRC_COMPONENTS)) \
		$(addprefix Scene/, $(SRC_SCENE)) \
		$(addprefix Objects/, $(SRC_OBJECTS)) \
		$(addprefix Characters/, $(SRC_CHARACTERS)) \
		$(addprefix Network/, $(SRC_NETWORK)) \
		$(addprefix Database/, $(SRC_DATA)) \
		$(addprefix Team/, $(SRC_TEAMS)) \
		$(addprefix Errors/, $(SRC_ERROR)) \
		$(SRC_GAME) \
		$(SRC_MAIN) \


OBJ	=	$(SRC:.cpp=.o)

NAME	=	zappy_gui

CXXFLAGS	=	-std=c++20 -Wall -Wextra -Wpedantic -fno-gnu-unique

LDLIBS	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

CPPFLAGS	=	-I ./Components/Window/ \
				-I ./Components/Buttons/ \
				-I ./Components/Parallax \
				-I ./Components/PanelBar/ \
				-I ./Components/TextBox/ \
				-I ./Components/SoundBox/ \
				-I ./Scene/ \
				-I ./Scene/Menu/ \
				-I ./Scene/Settings/ \
				-I ./Scene/Game/ \
				-I ./Scene/Skins \
				-I ./Scene/Win \
				-I ./Scene/Manager/ \
				-I ./Camera/ \
				-I ./Map/ \
				-I ./Objects/Foods/ \
				-I ./Objects/Stones/ \
				-I ./Objects/ \
				-I ./Factory/ \
				-I ./Factory/FactoryPlayers/ \
				-I ./Factory/FactoryObjects/ \
				-I ./Characters/Players/ \
				-I ./Characters/Eggs/ \
				-I ./Characters/ \
				-I ./Network/ \
				-I ./Network/Handlers/ \
				-I ./Arguments/ \
				-I ./Database/ \
				-I ./Struct/ \
				-I ./Team/ \
				-I ./ItemDrawer/ \
				-I ./Errors/ \
				-I ./ \

all:	$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LDLIBS)
	mv $(NAME) ../

clean:
	rm -rf $(NAME)

fclean:	clean

re:	fclean all

.PHONY: all clean fclean re
