#pragma once

namespace algCG {
    struct vertex {
        double X;
        double Y;
        double Z;
    };
    struct vector_u {
        double X;
        double Y;
        double Z;
    };
    struct view_point {
        double X;
        double Y;
        double Z;
    };
    struct barycenter {
        double X = 0;
        double Y = 0;
        double Z = 0;
    };

    bool Roberts_alg(vertex V1, vertex V2, vertex V3, view_point P, barycenter W) {
        vector_u Vec1, Vec2;
        //
        // for this face we find the coordinates of two vectors
        // that lie in the plane of the face
        //
        Vec1.X = V1.X - V2.X;
        Vec2.X = V3.X - V2.X;
        Vec1.Y = V1.Y - V2.Y;
        Vec2.Y = V3.Y - V2.Y;
        Vec1.Z = V1.Z - V2.Z;
        Vec2.Z = V3.Z - V2.Z;
        //
        // calculate the coefficients of the equation of the plane
        //
        double A, B, C, D;
        A = Vec1.Y * Vec2.Z - Vec2.Y * Vec1.Z;
        B = Vec1.Z * Vec2.X - Vec2.Z * Vec1.X;
        C = Vec1.X * Vec2.Y - Vec2.X * Vec1.Y;
        D = -(A * V1.X + B * V1.Y + C * V1.Z);
        //
        // coefficient changing the sign of the plane
        //
        double m;
        if ((A * W.X + B * W.Y + C * W.Z + D) < 0) m = 1.0;
        else if ((A * W.X + B * W.Y + C * W.Z + D) > 0) m = -1.0;
        else m = 0.0;
        //
        // adjust the direction of the plane
        //
        A *= m;
        B *= m;
        C *= m;
        D *= m;

        if ((A * P.X + B * P.Y + C * P.Z + D) > 0)
            return 0;
        else return 1;
    }
}