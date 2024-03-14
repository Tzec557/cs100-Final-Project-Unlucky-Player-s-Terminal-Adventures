
add_library(simpleLibrary
	Character.cpp
 	Enemy.cpp
	Point.cpp
	Player.cpp
	Game.cpp
	dice.cpp
	weapon.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})

