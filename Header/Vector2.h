#pragma once

struct Vector2
{
    float x;
    float y;

    Vector2 operator+(const Vector2& obj) { return{ x + obj.x,y + obj.y }; };
    Vector2 operator-(const Vector2& obj) { return{ x - obj.x,y - obj.y }; };
    Vector2 operator*(const Vector2& obj) { return{ x * obj.x,y * obj.y }; };
    Vector2 operator/(const Vector2& obj) { return{ x / obj.x,y / obj.y }; };

    Vector2 operator+=(const Vector2& obj) { return{ x += obj.x,y += obj.y }; };
    Vector2 operator-=(const Vector2& obj) { return{ x -= obj.x,y -= obj.y }; };
    Vector2 operator*=(const Vector2& obj) { return{ x *= obj.x,y *= obj.y }; };
    Vector2 operator/=(const Vector2& obj) { return{ x /= obj.x,y /= obj.y }; };

};