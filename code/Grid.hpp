#pragma once
#include "Piece.hpp"
#include <vector>
#define DIR_RIGHT 1
#define DIR_LEFT  0

namespace den {
    struct Piece;
    class Grid {
    public:
        Grid(SDL_Renderer* r, int tilesize);
        ~Grid();
        
        void Draw();
        bool Update();
        
        void QueueMove(bool dir);
    private:
        Block*** grid;
        
        SDL_Renderer* renderer;
        
        void Move(Piece* p, bool dir);
        bool CheckHorCollision(Piece* p, bool dir);
        
        bool CheckDownCollision(Piece* p);
        Piece* ApplyGravity(Piece* p);
        
        bool CheckCollision(uint i, uint j);
        void SetBlock(uint i, uint j, Block* val);
        void NewBlock(uint type, uint i, uint j);
        
        std::vector<bool> move_queue;
        int tile_s;
    };
}
