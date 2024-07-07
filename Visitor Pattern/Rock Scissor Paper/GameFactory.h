#include "Paper.h"

class GameFactory{
    
private:
    Type** data = nullptr;
    size_t capacity = 0;
    size_t size = 0;
    
    void resize(size_t newCap);
    void move(GameFactory&& other);
    void copy(const GameFactory& other);
    void destroy();
    void remove(size_t index);
    static Output determineWinnerBetweenTwo(Type* lhs, Type* rhs);
    
public:
    GameFactory();
    GameFactory(const GameFactory& other);
    GameFactory(GameFactory&& other) noexcept;
    GameFactory& operator=(const GameFactory& other);
    GameFactory& operator=(GameFactory&& other) noexcept;
    ~GameFactory();
    
    void addPlayer(Type* type);
    void addPlayer(const Type& other);
    Type* getPlayer(size_t index) const;
    Type* determineWinner();
    
    
    
};
