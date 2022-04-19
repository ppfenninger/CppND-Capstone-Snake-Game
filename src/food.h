#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include "SDL.h"

class Food {
    public:
        enum class FoodType {normal, fast, slow, reverse};

        Food() = default;
        Food(int x_location, int y_location) {
            location.x = x_location;
            location.y = y_location;
            SetRandomFoodType();
        };

        SDL_Point location;
        FoodType type;

    friend std::ostream& operator<<(std::ostream& os, const Food& food);
        
    private:
        void SetRandomFoodType();
};

#endif
