#ifndef MATHLIB_IMPLEMENTATION_TRANSFORM_HPP
#define MATHLIB_IMPLEMENTATION_TRANSFORM_HPP

#include "Matrix.hpp"

// -- SOLVED, left for context for the following points --
// TODO(3011): Create a more generic "lower-level" implementation of a
// transform that can take the final row as a template parameter.
// This will make it possible to represent more kinds of transformations
// efficiently.
// -- SOLVED, left for context for the following points --

// TODO(3011): As a follow-up to the previous point, it would be good
// if there was a way to put these different kinds of transforms into
// a single container with minimal overhead on performance for calculations.
// Keyword: type erasure

// Note(3011): With the above plans, it might be effectively impossible to
// serialize a transform. There could be a way to deal with this for
// in-library types built on top of this, but more obscure transform
// specializations will be problematic.

namespace Math
{
    template <Concept::StrongType T, Vector3T<MakeStaticStrongType<T>> BottomRowParam = Vector3T<MakeStaticStrongType<T>>::UnitZ()>
    class Transform2T final
    {
    public:
        using ScalarType = T;
        using VectorType = Vector2T<T>;
        using MatrixType = Matrix2T<T>;
        using RowVectorType = Vector3T<T>;
        using TransformMatrixType = Matrix3T<T>;
        static constexpr SizeType Dimension = 2;
        static constexpr RowVectorType BottomRow = BottomRowParam;

        constexpr explicit Transform2T() noexcept
            : rows()
        {}

        constexpr explicit Transform2T(T diag) noexcept
            : rows()
        {
            for (SizeType i = 0; i < 2; ++i) { rows[i][i] = diag; }
        }

        constexpr explicit Transform2T(const VectorType& row0,
                                       const VectorType& row1)
        noexcept
            : rows({ RowVectorType(row0),
                     RowVectorType(row1) })
        {}

        constexpr explicit Transform2T(const RowVectorType& row0,
                                       const RowVectorType& row1)
        noexcept
            : rows({ row0,
                     row1 })
        {}

        constexpr explicit Transform2T(T m00, T m01, T m02,
                                       T m10, T m11, T m12)
        noexcept
            : rows(RowVectorType(m00, m01, m02),
                   RowVectorType(m10, m11, m12))
        {}

        constexpr explicit Transform2T(const MatrixType& m)
        noexcept
            : rows(RowVectorType(m[0][0], m[0][1], 0),
                   RowVectorType(m[1][0], m[1][1], 0))
        {}

        constexpr explicit Transform2T(const MatrixType& m,
                                       const VectorType& v)
        noexcept
            : rows(RowVectorType(m[0][0], m[0][1], v[0]),
                   RowVectorType(m[1][0], m[1][1], v[1]))
        {}

        constexpr       RowVectorType& operator[] (SizeType index)       { return rows[index]; }
        constexpr const RowVectorType& operator[] (SizeType index) const { return rows[index]; }

        static constexpr Transform2T<T> Identity() noexcept { return Transform2T<T>(Cast<T>(1)); }
    private:
        Array<RowVectorType, 2> rows;
    };

    template <Concept::StrongType T, Vector4T<MakeStaticStrongType<T>> BottomRowParam = Vector4T<MakeStaticStrongType<T>>::UnitW()>
    class Transform3T final
    {
    public:
        using ScalarType = T;
        using VectorType = Vector3T<T>;
        using MatrixType = Matrix3T<T>;
        using RowVectorType = Vector4T<T>;
        using TransformMatrixType = Matrix4T<T>;
        static constexpr SizeType Dimension = 3;
        static constexpr RowVectorType BottomRow = BottomRowParam;

        constexpr explicit Transform3T() noexcept
            : rows()
        {}

        constexpr explicit Transform3T(T diag) noexcept
            : rows()
        {
            for (SizeType i = 0; i < 3; ++i) { rows[i][i] = diag; }
        }

        constexpr explicit Transform3T(const VectorType& row0,
                                       const VectorType& row1,
                                       const VectorType& row2)
        noexcept
            : rows({ RowVectorType(row0),
                     RowVectorType(row1),
                     RowVectorType(row2) })
        {}

        constexpr explicit Transform3T(const RowVectorType& row0,
                                       const RowVectorType& row1,
                                       const RowVectorType& row2)
        noexcept
            : rows({ row0,
                     row1,
                     row2 })
        {}

        constexpr explicit Transform3T(T m00, T m01, T m02, T m03,
                                       T m10, T m11, T m12, T m13,
                                       T m20, T m21, T m22, T m23)
        noexcept
            : rows(RowVectorType(m00, m01, m02, m03),
                   RowVectorType(m10, m11, m12, m13),
                   RowVectorType(m20, m21, m22, m23))
        {}

        constexpr explicit Transform3T(const MatrixType& m)
        noexcept
            : rows(RowVectorType(m[0][0], m[0][1], m[0][2], 0),
                   RowVectorType(m[1][0], m[1][1], m[1][2], 0),
                   RowVectorType(m[2][0], m[2][1], m[2][2], 0))
        {}

        constexpr explicit Transform3T(const MatrixType& m,
                                       const VectorType& v)
        noexcept
            : rows(RowVectorType(m[0][0], m[0][1], m[0][2], v[0]),
                   RowVectorType(m[1][0], m[1][1], m[1][2], v[1]),
                   RowVectorType(m[2][0], m[2][1], m[2][2], v[2]))
        {}

        constexpr       RowVectorType& operator[] (SizeType index)       { return rows[index]; }
        constexpr const RowVectorType& operator[] (SizeType index) const { return rows[index]; }

        static constexpr Transform3T<T> Identity() noexcept { return Transform3T<T>(Cast<T>(1)); }
    private:
        Array<RowVectorType, 3> rows;
    };
}

#endif //MATHLIB_IMPLEMENTATION_TRANSFORM_HPP
