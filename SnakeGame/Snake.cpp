#include "Snake.h"

Snake::Snake() : body(std::list<sf::Sprite>(3))
{
    head = --body.end();
    tail = body.begin();
}

Snake::~Snake()
{
}

void Snake::init(const sf::Texture& texture)
{
    float x = 16.f;
    for (auto& piece : body)
    {
        piece.setTexture(texture);
        piece.setPosition({ x, 48.f });
        x += 16.f;
    }
}

void Snake::move(const sf::Vector2f& direction)
{
    tail->setPosition(head->getPosition() + direction);
    head = tail;
    ++tail;

    if (tail == body.end())
    {
        tail = body.begin();
    }
}

bool Snake::isOn(const sf::Sprite& other) const
{
    return other.getGlobalBounds().intersects(head->getGlobalBounds());
}

void Snake::grow(const sf::Vector2f& direction)
{
    sf::Sprite newPiece;
    newPiece.setTexture(*(body.begin()->getTexture()));
    newPiece.setPosition(head->getPosition() + direction);

    head = body.insert(++head, newPiece);
}

bool Snake::isSelfIntersecting() const
{
    bool flag = false;

    for (auto piece = body.begin(); piece != body.end(); ++piece)
    {
        if (head != piece)
        {
            flag = isOn(*piece);

            if (flag)
            {
                break;
            }
        }
    }

    return flag;
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& piece : body)
    {
        target.draw(piece);
    }
}