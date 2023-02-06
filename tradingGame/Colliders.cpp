#include "Colliders.h"

void BoxCollider::setObjType(int type)
{
    objType = type;
}

int BoxCollider::getObjType()
{
    return objType;
}

void BoxCollider::setPos(sf::Vector2f newPos)
{
    pos = newPos;
}

sf::Vector2f BoxCollider::getPos()
{
    return pos;
}

sf::IntRect BoxCollider::getBounds()
{
    return bounds;
}

void BoxCollider::setBounds(sf::IntRect newBounds)
{
    bounds = newBounds;
}

void BoxCollider::update(float deltaTime)
{

    bounds = { (int)pos.x, (int)pos.y, (int)bounds.width, (int)bounds.height };

}

bool BoxCollider::isCollidingWith(BoxCollider targ)
{
    if (bounds.intersects(targ.getBounds())) {
        return true;
    }

    return false;
}

void BoxCollider::drawCollider(sf::RenderTarget* targWindow, sf::Color color)
{
    sf::RectangleShape boundsVisual;
    boundsVisual.setSize({ (float)bounds.width, (float)bounds.height });
    boundsVisual.setPosition(pos);

    boundsVisual.setOutlineColor(color);
    boundsVisual.setFillColor(sf::Color::Transparent);
    boundsVisual.setOutlineThickness(2);

    sf::Vertex diagonal[2];
    diagonal[0].position = pos;
    diagonal[1].position = { pos.x + bounds.width , pos.y + bounds.height };

    diagonal[0].color = color;
    diagonal[1].color = color;

    targWindow->draw(boundsVisual);
    targWindow->draw(diagonal, 2, sf::Lines);
}

void BoxCollider::setSleep(bool value)
{
    isSleep = value;
}

bool BoxCollider::getSleep()
{
    return isSleep;
}
