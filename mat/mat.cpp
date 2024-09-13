#include <climits>
#include <exception>
#include <iostream>

template <typename T, unsigned M, unsigned N>
class Matrix {
protected:
    T buffer[M*N] = {};
public:
    Matrix() = default;
    // Matrix(const T** mat) {
    //     for (unsigned i = 0; i < M; i++) {
    //         for (unsigned j = 0; j < N; j++) {
    //             buffer[M * i + j] = mat[M * i + j];
    //         }
    //     }
    // }
    Matrix(std::initializer_list<std::initializer_list<T>> init) {
        unsigned i = 0;
        for (const auto& row : init) {
            for (const auto& value : row) {
                buffer[i++] = value;
            }
        }
    }
   ~Matrix() {}

    T& operator[](unsigned i, unsigned j) {
        if (i < 1 or i > M or j < 1 or j > N) {
            throw std::exception();
        }
        return (T&)buffer[N * (i-1) + (j-1)];
    }

    Matrix<T, N, M> transpose() {
        Matrix<T, N, M> mat = Matrix<T, N, M>();

        for (unsigned i = 1; i <= M; i++) {
            for (unsigned j = 1; j <= N; j++) {
                mat[j, i] = (*this)[i, j];
            }
        }

        return mat;
    }

    friend std::ostream& operator<< (std::ostream& out, const Matrix<T, M, N>& mat) {
        // out << "T: " << typeid(T).name() << ", M: " << M << ", N: " << N << std::endl;
        for (unsigned i = 0; i < M; i++) {
            out << (i == 0 ? "( " : "  ");
            for (unsigned j = 0; j < N; j++) {
                out << mat.buffer[N * i + j] << " ";
            }
            out << (i == M - 1 ? ")" : "\n");
        }
        return out;
    };
};

int main() {
    Matrix<double, 3, 4> mat {
        { 9, 8, 7, 6 },
        { 5, 4, 3, 2 },
        { 1, 2, 3, 4 },
    };
    std::cout << mat << std::endl << std::endl;
    mat[1, 2] = 3.3;
    std::cout << mat << std::endl;

    try {
        mat[0, 0] = 2;
    } catch (std::exception e) {
        std::cout << "exception thrown when trying to set value at [0, 0]"
            << std::endl;
    }
    std::cout << mat << std::endl;

    Matrix<int, 0, 0> zero_by_zero_mat;
    std::cout << zero_by_zero_mat << std::endl;

    // Matrix<char, -1, 0> invalid_mat{};
    // std::cout << invalid_mat << std::endl;

    Matrix<double, 1, 4> row;
    row[1, 1] = 1;
    row[1, 2] = 2;
    row[1, 3] = 3;
    row[1, 4] = 4;
    std::cout << "row: " << std::endl
        << row << std::endl;

    auto column = row.transpose();
    std::cout << "row.transpose(): " << std::endl
        << column << std::endl;

    return 0;
}
