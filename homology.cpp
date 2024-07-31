
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
            dimension = 0;
            return;
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


class ChainComplex {
public:
    vector<vector<Simplex>> chain_complex;

    ChainComplex(const vector<Simplex>& ss) {
        for (const auto& simplex : ss) {
            addSimplex(simplex);
        }
    }
  
    void inline addSimplex(const Simplex& s) {
        //проблема в том, что этого индекса может и не быть :(
        while (chain_complex.size() <= s.dimension) {
            chain_complex.push_back({});
        }
        chain_complex.at(s.dimension).push_back(s);
    }

    ChainComplex() {}

    void printComplex() {
        for (int i = 0; i < chain_complex.size(); i++) {
            std::cout << "Dimension " << i << ":" << std::endl;
            for (int j = 0; j < chain_complex[i].size(); j++) {
                chain_complex[i][j].printSimplex();
            }
            std::cout << "\n";
        }
    }
};

int main() {

    try {
        vector<vector<int>> vs1 = { {1,0,0},{0,1,0},{0,0,1} };
        vector<vector<int>> vs2 = { {1,0},{2,1} };
        vector<vector<int>> vs3 = { {1,1},{2,2} };

        Simplex s1(vs1);
        Simplex s2(vs2);
        Simplex s3(vs3);

        ChainComplex cc({ s1, s2, s3 });

        cc.printComplex();
    }
    catch (const std::exception e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}