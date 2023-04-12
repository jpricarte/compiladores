#include <iostream>
#include <string>
#include <vector>
#include "fcg.hh"

void FCG::fromILOC(std::vector<ILOC_Code::Command> code) {
    /* TODO
     * Varrer comandos ILOC.
     * Implementar lógica para guardar informações relevantes e gerar grafo.
     * Escrever nodos e arestas diretamente nos atributos da classe.
     * 2 passadas?
     * */
    int block_begin = 0;
    for (ILOC_Code::Command command : code) {
        string com = command.to_string();
        cout << com;

        // analysis
        bool found_jump = com.find("jump") != string::npos;
        bool found_label = com.find("L") != string::npos;
//        bool found_halt = ((void *) &com == (void *)&code.back());
        if (found_jump) {
            cout << "\t[FIM DE BLOCO - JUMP]";
        } else if (found_label) {
            cout << "\t[FIM DE BLOCO - LABEL]";
        }
//        else if (found_halt) {
//            cout << "\t[FIM DE BLOCO - HALT]";
//        }

        cout << endl;
    }

}

string FCG::toDOT() {
    /* TODO
     * Se nodes e edges == empty => cancela.
     *
     * Percorrer grafo gerando comandos DOT.
     * Ref: https://graphviz.org/doc/info/lang.html
     *
     * Ler documentação da linguagem antes de implementar.
     * */
}