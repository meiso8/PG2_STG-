#include"../Header/Quad.h"
#include"../Header/Transform.h"

Quad MakeLocalQuad(Vector2& size) {

    Quad q{};

    q.leftTop_ = { -size.x / 2.0f,-size.y / 2.0f };
    q.rightTop_ = { size.x / 2.0f,-size.y / 2.0f };
    q.leftBottom_ = { -size.x / 2.0f,size.y / 2.0f };
    q.rightBottom_ = { size.x / 2.0f,size.y / 2.0f };

    return q;

}

Quad MakeScreenQuad(Quad& local, Matrix3x3& worldMatrix) {

    Quad q{};

    q.leftTop_ = Transform(local.leftTop_, worldMatrix);
    q.rightTop_ = Transform(local.rightTop_, worldMatrix);
    q.leftBottom_ = Transform(local.leftBottom_, worldMatrix);
    q.rightBottom_ = Transform(local.rightBottom_, worldMatrix);

    return q;

};