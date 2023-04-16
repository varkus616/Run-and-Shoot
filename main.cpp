#include <Game.h>
#include <random>
#include <ctime>
int main()
{
    srand(time(0));
    Game game;
    game.run(60.f);
    return 0;
}
