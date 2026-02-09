#include "Basic2D.h"

bool Basic2D::IsOverlapping(Basic2D& other)
{
    Vector2 selfBoundsTop(rect.w + position.X, rect.h + position.Y);
    Vector2 selfBoundsBottom(-rect.w + position.X, -rect.h + position.Y);
    Vector2 otherBoundsTop(other.rect.w + other.position.X, other.rect.h + other.position.Y);
    Vector2 otherBoundsBottom(-other.rect.w + other.position.X, -other.rect.h + other.position.Y);

    if (selfBoundsTop.X > otherBoundsTop.X) {

    }

    return false;
}
