#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <bits/stdc++.h>
#include "fcg.hh"

using namespace std;


int FCG::getDominator(int block) {
    bool findBlock = (find(this->nodes.begin(), this->nodes.end(), block) != this->nodes.end());
    if (not findBlock)
        return -1;

    cout << "BUSCANDO DOMINADOR DE " << block << endl;

    for (auto edge : this->edges) {
        cout << edge.first << " -> " << edge.second << endl;
        if (edge.second == block) {
            cout << "found " << endl;
            return getDominator(edge.first);
        }
    }
    return block;
}

void FCG::fromILOC(vector<ILOC_Code::Command> code) {
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

            case ILOC_Code::STORE: // call
                if (cur_block != 1 and command.op1 == ILOC_Code::RPC) {
                    cout << "[FOUND CALL]" << endl;
                    is_call = true;
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
    }   // fim da 1a passada



    // 2a passada
    is_call = false;
    on_block = false;
    cur_block = 0;
    for (ILOC_Code::Command command : code) {
        if (command.label > 0) {
            on_block = true;
            cur_block += 1;
            cout << "\n[2. COMEÇO DE BLOCO " << cur_block << " por label " << command.label << "]" << endl;
        } else if (not on_block) {
            on_block = true;
            cur_block += 1;
        }
        switch (command.instruct) {
            case ILOC_Code::STORE: // call
                if (command.op1 == ILOC_Code::RPC) {
                    cout << "[2. FOUND CALL]" << endl;
                    is_call = true;
                }
                break;

            case ILOC_Code::JUMP: // ret
                cout << "[2. FIM DE BLOCO por jump]" << endl;
                on_block = false;
                break;

            case ILOC_Code::JUMP_I:
                if (is_call) {
                    is_call = false;
                    // Percorrer toda a lista de dominadores
                    // Sempre que encontrar o bloco para qual queremos pular:
                    //  Adicionamos uma aresta entre o retorno (prov. outro bloco) e o bloco SEGUINTE ao que
                    // estamos atualmente
                    int target_block = label2block[command.op3];
                    for (auto dom_bl : dominators) {
                        int ret_block = dom_bl.first;
                        int dominator = dom_bl.second;
                        cout << target_block << " vs " << dominator << ": " << ret_block << "->" << cur_block+1 << endl;
                        if (dominator == target_block) {
                            // fala "a função que esta sendo chamada retorna depois daqui"
                            this->edges.emplace_back(ret_block, cur_block+1);
                        }
                    }
                }
                break;

            case ILOC_Code::CBR:
                cout << "[2. FIM DE BLOCO por cbr]" << endl;
                on_block = false;
                break;

            default:
                break;
        }
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
    // descobrir dominadores
    /* Durante a primeira leitura:
     *  Quando encontrar um retorno (JUMP em registrador):
     *      Acha o dominador que começa a função
     *      Guarda as seguintes infos (Bloco de retorno, o dominador)
     */
    /* Durante a segunda leitura
     *  Quando encontrar uma chamada de função:
     *      Cria uma aresta entre o bloco que chamou e o bloco que será enviado
     *      Busca o bloco que será enviado entre o cjto de dominadores
     *      Cria uma aresta entre o(s) bloco(s) que retornam da função e o bloco seguinte a chamada
     */

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

    oss << "digraph FlowControlGraph {" << endl;
    for (auto edge : this->edges) {
        oss << "\t" << edge.first << " -> "
        << edge.second << ";" << endl;
    }
    oss << "}" << endl;

    ofstream file(filename);
    file << oss.str();
    file.close();
}