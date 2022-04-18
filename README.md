# CPPND: Capstone Snake Game Example

I added two new features to the basic snake game: walls and different food types. 

The walls are gray spots in the game that cause the snake to die when they are hit.

I decided to create four different food types that affect the speed and direction of the snake: normal, fast, slow, and reverse.
All food types cause the snake to grow in lenth by 1 
- The normal food type increases the snake's speed by 0.02
- The fast food type increases the snake's speed by 0.04
- The slow food type decreases the snake's speed by 0.02
- The reverse food type causes the snake to switch directions

## Rubric Criteria

* Loops / functions / IO Inputs
  * Functions
    * I created several new functions: EatFood in snake.cpp, PlaceWall in game.cpp, and SetFoodColor in renderer.cpp
    * Each function I created either deals with the different types of foods to force the snake to do different things or places walls
    * I also edited many functions in the code to take in a Food instance instead of an SDL_Point for the food items. 
  * Control Structures
    * I added switch statements on both food type and direction to do different things when different foods are eaten and to implement my reverse direction food
    * I used a variety of vector methods including push_back, pop_back, and reverse to reverse the direction of my snake.

* Object oriented programming
  * I created a new class Food that holds the type of food and the location. When a new piece of food is created, the food constructor randomly assigns a type. The food types are contained in an enum which is used in game, snake, and render
  * In Food.h, I overrode the cout function to allow the type of food to be printed to the console. 
  * In Food.h, I defined both the construtor and the destructor
  * New methods are self documenting such as Snake::EatFood, Renderer::SetFoodColor, and Game::PlaceWall
  * I specified every new variable as either private or public as apprpriate

* Memory Managment
  * SetFoodColor and EatFood both pass food in as a reference. 


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
