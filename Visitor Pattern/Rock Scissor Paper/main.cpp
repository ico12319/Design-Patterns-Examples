#include "GameFactory.h"

Type* gameFactory(){
    char gameType[1024];
    std::cin.getline(gameType, 1024);
    
    if(std::strcmp(gameType, "Rock") == 0)
        return new Rock();
    else if(std::strcmp(gameType, "Scissor") == 0)
        return new Scissor();
    else if(std::strcmp(gameType, "Paper") == 0)
        return new Paper();
    else
        return nullptr;
}





int main(int argc, const char * argv[]) {
    
    
    GameFactory game;
    size_t n;
    std::cout<<"Enter the amount of players!"<<std::endl;
    std::cin >> n;
    std::cin.ignore();
    
    for(int i = 0;i<n;i++)
        game.addPlayer(gameFactory());
    
    
    Type* winner = game.determineWinner();
    winner->print();
}
