#include "Debug_Display.h"

#include <memory>
#include <mutex>
#include <SFML/Graphics.hpp>

#include "Display.h"
#include "Chunk/Chunk_Location.h"
#include "Maths/Position_Converter_Maths.h"

namespace Debug_Display
{
    namespace
    {
        sf::Font font;


        //t_ prefix for TEXT
        sf::Text t_fps;

        sf::Text t_chunkPosition;
        sf::Text t_blockPosition;
        sf::Text t_worldPosition;

        sf::Text t_lookVector;


        void initText(sf::Text& text)
        {
            text.setFont            (font);
            text.setCharacterSize   (23);
            text.move               (5, 0);
            text.setOutlineColor    (sf::Color::Black);
            text.setOutlineThickness(2);
        }
    }

    void init()
    {
        font.loadFromFile("Data/Font/rs.ttf");

        initText(t_fps);
        initText(t_chunkPosition);
        initText(t_blockPosition);
        initText(t_worldPosition);

        initText(t_lookVector);

        t_chunkPosition.move(0, 40);
        t_blockPosition.move(0, 80);
        t_worldPosition.move(0, 120);

        t_lookVector.move(0, 160);
    }

    void addFPS(float fps)
    {
        t_fps.setString("FPS: " + std::to_string((int)fps));
    }

    void addPlayerPosition  (const Vector3& location)
    {
        Chunk_Location cl(Maths::worldToChunkPosition(location));
        Vector3        bl(Maths::worldToBlockPosition(location));

        t_chunkPosition.setString("Chunk Location: X: " + std::to_string(cl.x) +
                                                 " Z: " + std::to_string(cl.z));

        t_blockPosition.setString("Block Location: X: " + std::to_string((int)bl.x) +
                                                 " Y: " + std::to_string((int)bl.y) +
                                                 " Z: " + std::to_string((int)bl.z));

        t_worldPosition.setString("World Location: X: " + std::to_string(location.x) +
                                                 " Y: " + std::to_string(location.y) +
                                                 " Z: " + std::to_string(location.z));
    }

    void addLookVector(const Vector3& rotation)
    {
        t_lookVector.setString("Look Rotation: X: " + std::to_string((int)rotation.x) +
                                             " Y: " + std::to_string((int)rotation.y) +
                                             " Z: " + std::to_string((int)rotation.z));
    }


    void draw()
    {
        Display::sfDraw(t_fps);

        Display::sfDraw(t_chunkPosition);
        Display::sfDraw(t_blockPosition);
        Display::sfDraw(t_worldPosition);

        Display::sfDraw(t_lookVector);
    }
}