#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "fcg.hh"

//void FCG::fromILOC(std::vector<ILOC_Code::Command> code) {
//    /* TODO
//     * Varrer comandos ILOC.
//     * Implementar lógica para guardar informações relevantes e gerar grafo.
//     * Escrever nodos e arestas diretamente nos atributos da classe.
//     * 2 passadas?
//     * */
//    int cur_block = 0;
//    bool on_block = false;
//    bool on_cbr = false;
//    for (ILOC_Code::Command command : code) {
//        if (not on_block) {
//            cout << "[COMEÇO DE BLOCO "<<to_string(cur_block)<<"]" << endl;
//            on_block = true;
//            cur_block += 1;
//            this->nodes.push_back(cur_block);
//        }
//
//        string com = command.to_string();
//        cout << com;
//
//        // analysis
//        bool found_jump = com.find("jump") != string::npos;
//        bool found_cbr = com.find("cbr") != string::npos;
//        cout << endl;
//
//        cout << "\t[FIM DE BLOCO "<<to_string(cur_block)<<"]";
//        on_block = false;
//        if (found_jump) {
//            this->edges.push_back(make_pair(cur_block, cur_block + 1));
//        } else if (found_cbr) {
//
//        }
//
//        if (found_jump or found_cbr) {
//            cout << "\t[FIM DE BLOCO "<<to_string(cur_block)<<"]";
//            on_block = false;
//
//            if (on_cbr) {
//                on_cbr = false;
//                this->edges.push_back(make_pair(cur_block-1, cur_block + 1));
//            } else {
//                if (found_cbr) {
//                    on_cbr = true;
//                }
//                this->edges.push_back(make_pair(cur_block, cur_block + 1));
//            }
//        }
//    }
//
//    cout << "NODES" << endl;
//    for (auto node : nodes)
//        cout << node << endl;
//    cout << "EDGES" << endl;
//    for (auto edge : edges)
//        cout << edge.first << ", " << edge.second << endl;
//
//}

void FCG::fromILOC(std::vector<ILOC_Code::Command> code) {
    /*
     * Varrer comandos ILOC.
     * Implementar lógica para guardar informações relevantes e gerar grafo.
     * Escrever nodos e arestas diretamente nos atributos da classe.
     * 2 passadas?
     * */
    int cur_block = 0;
    bool on_block = false;
    map<int, int> label2block;
    vector<pair<int, int>> block2label;
    vector<pair<int, int>> dominators; // dominado -> dominador
    bool is_call = false;

    for (ILOC_Code::Command command : code) {
        if (command.label > 0) {
            on_block = true;
            cur_block += 1;
            cout << "\n[COMEÇO DE BLOCO " << cur_block << " por label " << command.label << "]" << endl;
            this->nodes.push_back(cur_block);
            label2block.insert({command.label, cur_block});
        } else if (not on_block) {
            on_block = true;
            cur_block += 1;
            cout << "\n[COMEÇO DE BLOCO " << cur_block << "]" << endl;
            this->nodes.push_back(cur_block);
        }

        string com = command.to_string();
        cout << ". " << com << endl;

        switch (command.instruct) {

            case ILOC_Code::STORE:
                if (command.op1 == ILOC_Code::RPC) {
                    cout << "EMPILHA" << endl;
                    stack.push_back(cur_block);
                }
                break;

            case ILOC_Code::JUMP: // ret
                cout << "[FIM DE BLOCO por jump]" << endl;
                dominators.emplace_back(cur_block, this->getDominator(cur_block));
                on_block = false;
                break;

            case ILOC_Code::JUMP_I:
                cout << "[FIM DE BLOCO por jumpI]" << endl;
                on_block = false;
                block2label.emplace_back(cur_block, command.op3);
                break;

            case ILOC_Code::CBR:
                cout << "[FIM DE BLOCO por cbr]" << endl;
                on_block = false;
                block2label.emplace_back(cur_block, command.op3);
                block2label.emplace_back(cur_block, command.op4);
                break;

            default:
                break;
        }
    }

    if (on_block) {
        cout << "[FIM DE BLOCO por halt]" << endl;
        on_block = false;
//        this->edges.emplace_back(prev_block, cur_block);
    }

    for (auto it : block2label) {
        int bl = it.first;
        int lab = it.second;
        this->edges.emplace_back(bl, label2block[lab]);
    }

    cout << "\n\nNODES" << endl;
    for (auto node : nodes)
        cout << node << endl;
    cout << "EDGES" << endl;
    for (auto edge : edges)
        cout << edge.first << ", " << edge.second << endl;

    // 2a leitura

}

void FCG::toDOT(string filename) {
    /* TODO
     * Se nodes e edges == empty => cancela.
     *
     * Percorrer grafo gerando comandos DOT.
     * Ref: https://graphviz.org/doc/info/lang.html
     *
     * Ler documentação da linguagem antes de implementar.
     * */
    ostringstream oss;

    oss << "digraph FluxControlGraph {" << endl;
    for (auto edge : this->edges) {
        oss << "\t" << edge.first << " -> "
        << edge.second << ";" << endl;
    }
    oss << "}" << endl;

    ofstream file(filename);
    file << oss.str();
    file.close();
}