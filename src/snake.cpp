#include "snake.h"
#include <cmath>
#include <iostream>
#include <algorithm>

void Snake::Update(std::vector<SDL_Point> const &walls) {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell, walls);
  }
}

void Snake::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell, std::vector<SDL_Point> const &walls) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }

  for (auto const &wall : walls) {
    if (current_head_cell.x == wall.x && current_head_cell.y == wall.y) {
      alive = false;
    }
  }
}

void Snake::GrowBody() { growing = true; }

void Snake::EatFood(Food::FoodType &foodType){
  GrowBody();
  switch (foodType) {
    case Food::FoodType::normal: {
      speed += 0.02;
      return;
    }
    case Food::FoodType::fast: {
      speed += 0.04;
      return;
    }
    case Food::FoodType::slow: {
      speed -= 0.02;
      return;
    }
    case Food::FoodType::reverse: {
      Reverse();
      return;
    }
    default: {
      return;
    }
  }
}

void Snake::Reverse() {
  switch (direction) {
    case Direction::kUp: {
      direction = Direction::kDown;
      break;
    }
    case Direction::kDown: {
      direction = Direction::kUp;
      break;
    }
    case Direction::kLeft: {
      direction = Direction::kRight;
      break;
    }
    case Direction::kRight: {
      direction = Direction::kLeft;
      break;
    }
  }

  // add a body piece where the head is
  SDL_Point prev_head{static_cast<int>(head_x),
      static_cast<int>(head_y)};
  body.push_back(prev_head);

  // put the head at the last body piece
  head_x = body[0].x;
  head_y = body[0].y;
  // reverse the body
  std::reverse(body.begin(), body.end());

  //remove the body piece that is over the head
  body.pop_back();
}

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}