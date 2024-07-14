// homology.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

struct Simplex {
public:
    std::vector<int> vertices;
    int dimention;

    Simplex(const std::vector<int>& v) : vertices(v), dimention(v.size() - 1) {}
    ~Simplex() {
        vertices.clear();
    }
};

struct SimplicialComplex {
public:
    std::vector<Simplex> simplices;

    void addSimplex(const Simplex& s) {
        simplices.push_back(s);
    }
};

int main()
{
    return 0;
}