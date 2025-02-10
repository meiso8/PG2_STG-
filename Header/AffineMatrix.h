#pragma once

#include"Matrix3x3.h"
#include"Vector2.h"

//アフィン行列作成関数
Matrix3x3 MakeAffineMatrix(Vector2 scale, float theta, Vector2 translate);
