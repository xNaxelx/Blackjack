set(CMAKE_TOOLCHAIN_FILE "C:/Program Files/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(CMAKE_GENERATOR_PLATFORM "Win32")
set(VCPKG_TARGET_TRIPLET "x86-windows")

cmake_minimum_required(VERSION 3.27.0)
project(BlackJack)



set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(BOOST_MIN_VERSION "1.55.0")
find_package(Boost ${BOOST_MIN_VERSION} REQUIRED COMPONENTS filesystem) 

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

file(GLOB src 
	source/*.cpp source/*.h
	source/engine/*.cpp source/engine/*.h
	source/gameplay/*.cpp source/gameplay/*.h
)
add_executable(${PROJECT_NAME} ${WIN32_GUI} ${src})

if(Boost_FOUND)
	target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
	target_link_libraries(${PROJECT_NAME} PRIVATE Boost::filesystem)
	message("Boost founded")
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main 
	SDL2::SDL2 
	SDL2_image::SDL2_image 
	SDL2_mixer::SDL2_mixer 
	SDL2_ttf::SDL2_ttf
	)
	
#target_link_libraries(${PROJECT_NAME} Boost::filesystem Boost::bind Boost::function)
	
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
	
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resource DESTINATION ${CMAKE_CURRENT_BINARY_DIR})	