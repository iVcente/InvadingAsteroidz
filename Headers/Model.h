#ifndef MODEL_H
#define MODEL_H

#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "Matrix.h"
#include "Vector.h"

struct Color {
    int r, g, b;

    Color(int r, int g, int b): r(r), g(g), b(b) 
    { }
};

struct Model {
    std::map<int, Color> colors;
    Structs::Vector dimensions;
    Structs::Matrix<int> pixels;

    Model(): dimensions(), pixels() 
    { }

    void print() const {
        std::cout << "Colors:\n";
        for (const auto& color : colors)
            std::cout << color.first << " -> " << color.second.r << " " << color.second.g << " " << color.second.b << "\n";
        std::cout << "\nDimensions: Rows = " << dimensions.x << " | Columns = " << dimensions.y << "\n";
        std::cout << "\n";
        pixels.print();
    }
};

inline void loadModel(const std::string& filePath, const std::string& name, std::map<std::string, Model>& models) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "ERROR! Could not find: " << filePath << "\n";
        exit(EXIT_FAILURE);
    }

    std::string word = "";
    Model model = Model();

    // Reads the model's colors
    file >> word; // Just reads an irrelevant line.
    int nColors, id, r, g, b = 0;
    file >> nColors;

    for (int i = 0; i < nColors; i++) {
        file >> id >> r >> g >> b;
        Color c (r, g, b);
        model.colors.insert({id, c});
    }

    // Reads the model's "pixels"
    file >> word; // Just reads an irrelevant line.
    int rows, columns = 0;
    file >> rows >> columns;
    model.pixels.resize(rows, columns);
    model.dimensions = Structs::Vector(rows, columns);
    
    int pixel = 0;
    int y = 0;
    int x = 0;
    int aux = 0;

    while (file >> pixel) {
        
        if (aux == columns) {
            y++;
            x = 0;
            aux = 0;
        }

        model.pixels.at(y, x) = pixel;
        x++;
        aux++;
    }

    models.insert({name, model});
}

#endif