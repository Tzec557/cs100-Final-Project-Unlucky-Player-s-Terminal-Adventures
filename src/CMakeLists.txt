
add_library(simpleLibrary
	Character.cpp
 	Enemy.cpp
	Point.cpp
	Player.cpp
	Game.cpp
	dice.cpp
	weapon.cpp
)

add_executable(runMain main.cpp Game.cpp Character.cpp Player.cpp Enemy.cpp dice.cpp weapon.cpp Point.cpp)


find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})
find_library(M_LIB m)
if(M_LIB)
    target_link_libraries(simpleLibrary ${M_LIB})
endif()

