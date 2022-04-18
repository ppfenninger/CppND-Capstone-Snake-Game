#include "food.h"

#include "SDL.h"

void Food::SetRandomFoodType() {
    type = FoodType(rand() % 4);
}

std::ostream& operator<<(std::ostream& os, const Food& food) {
    std::string foodType;
    switch(food.type) {
        case Food::FoodType::normal:
            foodType = "normal";
            break;
        case Food::FoodType::fast:
            foodType = "fast";
            break;
        case Food::FoodType::slow:
            foodType = "slow";
            break;
        case Food::FoodType::reverse:
            foodType = "reverse";
            break;
        default:
            foodType = "type unknown";
            break;
    }

    os << "Food in location " << food.location.x << ", " << food.location.y << " is of type: " << foodType << "\n";
    return os;
}