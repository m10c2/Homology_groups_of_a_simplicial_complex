
#include <iostream>
#include <vector>
#include <stdexcept>
using std::vector;
 

class Simplex {
public:
    vector<vector<int>> vertices;
    int dimension;
    
    Simplex(const vector<vector<int>>& vs) : vertices(vs), dimension(vertices.size() - 1){
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
    Simplex() {
        dimension = 0;
        vertices = {};
    }

    void printSimplex() {
        if (dimension == 0) {
            std::cout << "{ }" << std::endl;
        }
        else {
            std::cout << "{";
            for (int i = 0; i < vertices.size(); i++) {
                std::cout << "{";
                for (int j = 0; j < vertices[0].size(); j++) {
                    std::cout << vertices[i][j];
                    if (j != vertices[0].size() - 1) {
                        std::cout << ",";
                    }
                }
                std::cout << "}";
                
                if (i!= vertices.size() - 1) {
                    std::cout << ",";
                }
            }
            std::cout << "}" << std::endl;;
        }
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

    ChainComplex(const vector<Simplex>& ss) {
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

    ChainComplex() {}

    void printComplex() {
        for (int i = 0; i < chain_complex.size(); i++) {
            for (int j = 0; j < chain_complex[i].size(); j++) {
                chain_complex[i][j].printSimplex();
            }
        }
    }
};
    
int main()
{
    vector<vector<int>> vertices = { {1,0,0},{0,1,0},{0,0,1} };
    Simplex simplex(vertices);
    Simplex* emptysimplex = new Simplex();
    
    vector<Simplex> simplex_list = {simplex};
    
    ChainComplex complex(simplex_list);

   
    return 0;
}