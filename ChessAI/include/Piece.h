﻿#pragma once

#include <cstdint>

#include "Maths/vector2i.hpp"
#include "Mountain/resource/texture.hpp"

class Tile;

enum class PieceType : uint8_t
{
    King,
    Queen,
    Rook,
    Bishop,
    Knight,
    Pawn
};

class Piece
{
public:
    bool isWhite;
    PieceType pieceType = PieceType::Pawn;
    Vector2 globalPosition;
    Vector2 scaling;

    Tile* tile;

    bool isDragged = false;

public:
    Piece(bool isWhite, PieceType pieceType, Tile* tile);
    void Render();
    void Move(Vector2i newPosition);

public:
    static void LoadResources();

private:
    static inline std::array<Mountain::Pointer<Mountain::Texture>, 12> piecesTextures;
};
