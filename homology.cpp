// homology.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <stdexcept>

using std::vector;
 

class Simplex {
public:
    vector<vector<int>> vertices;
    int dimension;
    
    Simplex(vector<vector<int>>& vs) : vertices(vs), dimension(vertices.size() - 1){
        if (vs.empty()) {
            throw std::invalid_argument("empty simplex");
        }
        int dim = vs[0].size();
        for (const auto& vertex : vs) {
            if (vertex.size() != dim) {
                throw std::invalid_argument("all vertices must have the same dimetion");
            }
        }
        if (vs.size() != vs[0].size()) {
            throw std::invalid_argument("a simplex in n dimentions must have n+1 vertices"); 
        }
    }

    void print() {
        return;
    }
};


/*TODO:
1)реализовать пустой симплекс, потому что некоторых размерностей может не быть
2)реализовать конструктор, принимающий на вход список симплексов
3)print
*/

class ChainComplex {
public:
    vector<vector<Simplex>> chain_complex;

    ChainComplex(vector<Simplex>& ss) {
        std::cout << "ChainComplex constructor" << std::endl;
        for (const auto& simplex : ss) {
            addSimplex(simplex);
        }
    }
  
    void inline addSimplex(const Simplex& s) {
        //проблема в том, что этого индекса может и не быть :(
        chain_complex[s.dimension].push_back(s);//крашится на этом месте
        std::cout << "nice" << std::endl;
    }

    void print() {
        return;
    }
    
};
    
int main()
{
    vector<vector<int>> vertices = { {1,0,0},{0,1,0},{0,0,1} };
    Simplex simplex(vertices);

    vector<Simplex> simplex_list = {simplex};
    
    //ChainComplex complex(simplex_list);

   
    return 0;
}