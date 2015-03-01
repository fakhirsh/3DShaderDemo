cmake_minimum_required(VERSION 2.8)

project(Game)

SET(CMAKE_EXECUTABLE_SUFFIX ".html")

set(PLATFORM "Emscripten")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ALLOW_MEMORY_GROWTH=1 -s FULL_ES2=1 --preload-file ../../Assets")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s TOTAL_MEMORY=97108864 -s FULL_ES2=1 --preload-file ../../Assets")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ALLOW_MEMORY_GROWTH=1 -s FULL_ES2=1 --embed-file ../../Assets")

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../../../Game/Emscripten)

# Set include directories
include_directories(../../FEngine)
include_directories(../../GameLogic)
include_directories(../../3rdparty/libpng-1.6.15)
include_directories(../../3rdparty/libogg-1.3.2/include)
include_directories(../../3rdparty/libvorbis-1.3.4/include)
include_directories(../../3rdparty/boost_1_56_0)
include_directories(../../3rdparty/FastDelegate)
include_directories(../../3rdparty/glm-0.9.5.4)
include_directories(../../3rdparty/PennerEasing)
include_directories(../../3rdparty/tinyxml2-master)
include_directories(../../3rdparty/RectangleBinPack)
#include_directories(../../3rdparty/freetype-2.5.4/include)


# Copy all the assets
CONFIGURE_FILE(../../../Assets/Config/SystemConfig.xml ../Assets/Config/SystemConfig.xml COPYONLY)
CONFIGURE_FILE(../../../Assets/Textures/banana.png ../Assets/Textures/banana.png COPYONLY)


# Add library subdirectories
add_subdirectory(../../3rdparty/libpng-1.6.15 ${CMAKE_BINARY_DIR}/libpng)
add_subdirectory(../../3rdparty/libvorbis-1.3.4 ${CMAKE_BINARY_DIR}/libvorbis)
add_subdirectory(../../3rdparty/PennerEasing ${CMAKE_BINARY_DIR}/PennerEasing)
add_subdirectory(../../3rdparty/tinyxml2-master ${CMAKE_BINARY_DIR}/tinyxml2)
add_subdirectory(../../3rdparty/RectangleBinPack ${CMAKE_BINARY_DIR}/RectangleBinPack)
#add_subdirectory(../../3rdparty/freetype-2.5.4 ${CMAKE_BINARY_DIR}/freetype)


# appears to be a nice way to add ALL source files lol
#file(GLOB sources *.cpp)
# And use it as follows:
#add_executable(Game ${sources})


set ( HDR

	)

set ( SRC
		main.cpp
		EMCGlue.cpp
		../../GameLogic/Screens/Test/Test3D.cpp
		../../FEngine/System/App.cpp
		../../FEngine/System/SystemConfig.cpp
		../../FEngine/Graphics2D/Texture.cpp
		../../FEngine/Graphics3D/SceneNode3D.cpp
		../../FEngine/Graphics3D/SceneNodeProperties3D.cpp
		../../FEngine/Graphics3D/RootSceneNode3D.cpp
		../../FEngine/Graphics3D/BananaNode.cpp
		../../FEngine/Graphics3D/VertexBoilNode.cpp
		../../FEngine/Graphics3D/ToonNode.cpp
		../../FEngine/ResourceCache/IOManagerDefault.cpp
		../../FEngine/ResourceCache/ResourceCache.cpp
		../../FEngine/Renderer/GLES20/RendererGLES20.cpp
		../../FEngine/Renderer/GLES20/Program.cpp
		../../FEngine/Renderer/GLES20/Vertex3DProgram.cpp
		../../FEngine/Renderer/GLES20/ToonProgram.cpp
		../../FEngine/Renderer/GLES20/VertexBoilProgram.cpp
		../../FEngine/StateManager/State.cpp
		../../FEngine/StateManager/StateManager.cpp
		../../FEngine/SoundManager/SoundManager.cpp
	)
	
# Executable
add_executable(Game
				${HDR} 
				${SRC} 
			)

# Link static libraries
target_link_libraries( Game
						png
						vorbis
						tinyxml2
						PennerEasing
						RectangleBinPack
					)

