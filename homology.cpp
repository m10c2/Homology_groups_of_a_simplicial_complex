// homology.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using std::vector;

/*TODO: 
1) добавить исключение при несостыковке размерностей
2) добавить деструктор
*/
class Simplex {
public:
    vector<vector<int>> vertices;
    int dimention;
    
    
    Simplex(vector<vector<int>>& vs) : vertices(vs), dimention(vs.size() - 1) {}
};


/*TODO:
1)реализовать пустой симплекс, потому что некоторых размерностей может не быть
2)конструктор, делающий из списка вершин цепной комплекс
3)деструктор
*/

class ChainComplex {
public:
    vector<vector<Simplex>> chain_complex;

    ChainComplex() {

    }
    ~ChainComplex() {
        for (int i = 0; i < chain_complex.size(); i++) {
            for (int j = 0; j < chain_complex[i].size(); j++) {
                //delete chain_complex[i][j];
            }
        }
    }
   
    void inline addSimplex(const Simplex& s) {
        chain_complex[s.dimention].push_back(s);
    }

};
    
int main()
{
    vector<vector<int>> vertices = { {1,0,0},{0,1,0},{0,0,1} };
    Simplex simplex(vertices);

    std::cout << simplex.dimention << std::endl;



    return 228;
}