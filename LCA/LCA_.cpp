#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string cursos[] = {"", "Matematica_I", "Discretas_I", "Programacion_de_videojuegos", "Comunicacion", "Metodologia_del_estudio", "IVU", "Matematica_II", "Discretas_II", "ICC",
"CCI","Filosofia","Musica","Persona_y_familia","Calculo_I","Arquitectura","Abstracta","CCII","DBP","Antropologia","Artistica","Literaria","Estadistica","Calculo_II","TC","AED",
"BDI","Teologia","Fisica","Analisis_Numerico","ADA","BDII","IS1","Moral","Teatro","Matematica_Aplicada","EDA","Operativos","Competitiva","IS2","Oratoria","IA","Lenguajes","Grafica",
"Redes","Met_investigacion","IS3","Liderazgo","Compiladores","IHC","Seguridad","Paralelas","Proyectos_I","Computacion_sociedad","Historia_cultura","Topicos_IA","Topicos_Grafica",
"Molecular","Topicos_IS","Big_Data","Proyectos_II","Enseñanza_iglesia","Empresas_I","Historia_Ciencia","Robotica","Cloud_Computing","Proyectos_III","Sistemas_de_informacion",
"Etica","Empresas_II","Realidad_peruana","Ingles"};

int index(string a)
{
    for(int i = 0; i < 72; i++){
        if(a == cursos[i]){
            return i;
        }
    }
}

class Graph{
    int cant;
    vector<vector<int > > ancestros_cu;//ancestros de cada nodo
    vector<vector<int > > sucesors_cu;
public:
    Graph(int cant_){
        cant = cant_;
        vector<vector<int> > temp(cant_+1);//el primer vector va a estar vacio
        ancestros_cu = temp;
        sucesors_cu = temp;
    }
    void addEdge(int padre, int hijo){
        ancestros_cu[hijo].push_back(padre);
        for(int i = 0; i < ancestros_cu[padre].size(); i++){
            if(find(ancestros_cu[hijo].begin(), ancestros_cu[hijo].end(), ancestros_cu[padre][i]) != ancestros_cu[hijo].end()){;}
            else{
                ancestros_cu[hijo].push_back(ancestros_cu[padre][i]);
            }
        }
        sucesors_cu[padre].push_back(hijo);
    }

    void LCA(int a, int b){
        bool encontrado = false;
        for(int i = 0; i < ancestros_cu[a].size(); i++){
            if(find(ancestros_cu[b].begin(), ancestros_cu[b].end(), ancestros_cu[a][i]) != ancestros_cu[b].end()){
                cout << "LCA(" << cursos[a] << "," << cursos[b] << ") = " << cursos[ancestros_cu[a][i]] << endl;
                encontrado = true;
                break;
            }
        }
        if(!encontrado)
            cout << "No se encontro curso en comun" << endl;
    }

    void Generar_malla(){
        for(int i = 1; i <= sucesors_cu.size(); i++){
            for(int j = 0; j < sucesors_cu[i].size(); j++){
                //start -> main [color="0.002 0.999 0.999"];
                cout << cursos[i] << " -> " <<  cursos[sucesors_cu[i][j]] << "[color=\"0.002 0.999 0.999\"];" << endl;
            }
        }
    }
};

int main()
{
    int cant = 71;
    Graph grafo(cant);
    grafo.addEdge(1,7);
    grafo.addEdge(1,14);
    grafo.addEdge(2,8);
    grafo.addEdge(2,16);
    grafo.addEdge(3,10);
    //addEdge(4,4);
    //addEdge(5,5);
    //addEdge(6,6);
    grafo.addEdge(7,23);
    grafo.addEdge(8,15);
    grafo.addEdge(8,24);
    grafo.addEdge(9,25);
    grafo.addEdge(10,16);
    grafo.addEdge(10,17);
    grafo.addEdge(10,18);
    grafo.addEdge(11,19);
   // addEdge(12,12);
    //addEdge(13,13);
    grafo.addEdge(14,22);
    grafo.addEdge(14,23);
    grafo.addEdge(14,28);
    grafo.addEdge(15,37);
    grafo.addEdge(16,26);
    grafo.addEdge(17,25);
    grafo.addEdge(17,32);
    //addEdge(18,18);
    grafo.addEdge(19,27);
    //addEdge(20,20);
    //addEdge(21,21);
    grafo.addEdge(22,41);
    grafo.addEdge(23,35);
    grafo.addEdge(23,29);
    grafo.addEdge(24,42);
    grafo.addEdge(25,30);
    grafo.addEdge(26,31);
    grafo.addEdge(26,32);
    grafo.addEdge(27,33);
    //grafo.addEdge(28,28);
    grafo.addEdge(29,43);
    grafo.addEdge(30,36);
    grafo.addEdge(30,57);
    grafo.addEdge(30,38);
    grafo.addEdge(30,51);
    grafo.addEdge(30,45);
    grafo.addEdge(31,59);
    grafo.addEdge(32,39);
    grafo.addEdge(33,53);
    grafo.addEdge(33,68);
    grafo.addEdge(34,40);
    grafo.addEdge(35,57);
    grafo.addEdge(36,43);
    grafo.addEdge(37,44);
    //grafo.addEdge(38,38);//
    grafo.addEdge(39,46);
    grafo.addEdge(39,67);
    grafo.addEdge(40,47);
    grafo.addEdge(41,55);
    grafo.addEdge(42,48);
    grafo.addEdge(43,56);
    grafo.addEdge(43,49);
    grafo.addEdge(44,50);
    grafo.addEdge(44,51);
    grafo.addEdge(45,52);
    grafo.addEdge(46,58);
    grafo.addEdge(47,62);
    //addEdge(48,48);//
    //addEdge(49,49);//
    //addEdge(50,50);//
    grafo.addEdge(51,59);
    grafo.addEdge(52,60);
    //addEdge(53,53);//
    grafo.addEdge(54,63);
    grafo.addEdge(55,64);
    //addEdge(56,56);//
    //addEdge(57,57);//
    //addEdge(58,58);//
    grafo.addEdge(59,65);
    grafo.addEdge(60,66);
    grafo.addEdge(61,68);
    grafo.addEdge(62,69);
    grafo.addEdge(63,70);
    //addEdge(64,64);//
    //addEdge(65,65);
    //addEdge(66,66);
    //addEdge(67,67);
   // addEdge(68,68);
   // addEdge(69,69);
   // addEdge(70,70);
    //addEdge(71,71);
    while(true){
        string curso_a, curso_b;
        cout << "Curso 1: "; cin >> curso_a; if(curso_a == "salir")break;
        cout << "Curso 2: "; cin >> curso_b;
        int i1 = index(curso_a);
        int i2 = index(curso_b);
        grafo.LCA(i1,i2);
    }
    grafo.Generar_malla();
    return 0;
}
