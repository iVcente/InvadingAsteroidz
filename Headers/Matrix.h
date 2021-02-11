#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

namespace Structs {
    template<typename T>
    class Matrix {
        private:
            std::vector<std::vector<T>> data;

        public:
            Matrix() {
                data.resize(1);
                data.at(0).resize(1);
            }

            Matrix(const int y, const int x) { 
                data.resize(y);
                for (int i = 0; i < y; i ++)
                    data.at(i).resize(x);
            }

            int getNumRows() const {
                return data.size();
            }

            int getNumColumns() const {
                return data.at(0).size();
            }

            std::vector<T>& getColumn(const int i) {
                return data.at(i);
            }

            std::vector<std::vector<T>>& getMatrix() {
                return data;
            }

            T& at(const int y, const int x) {
                return data.at(y).at(x);
            }

            void resize(const int y, const int x) {
                data.resize(y);
                for (int i = 0; i < y; i ++)
                    data.at(i).resize(x);
            }

            void print() {
                for (auto& row : data) {
                    for (auto& element : row)
                        std::cout << element << " ";
                    std::cout << "\n";
                }
            }
    };
}

#endif