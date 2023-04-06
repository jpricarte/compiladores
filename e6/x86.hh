#ifndef X_86_HH
#define X_86_HH

#include <string>
#include <vector>
#include "iloc.hh"


namespace x86 {
    struct Control {
        const int NUM_REG = 6;
        int rc = 0;
        std::vector<std::string> registers{"eax", "ebx", "ecx", "edx", "esi", "edi"};
        std::vector<bool> in_use{false, false, false, false, false, false};

        inline int alloc_reg() {
            int initial_pos = this->rc;
            while (this->in_use[this->rc]) {
                this->rc++; 
                this->rc %= NUM_REG;
                if (this->rc == initial_pos)
                    return -1;
            }
            this->in_use[this->rc] = true;
            return this->rc; 
        }

        inline std::string reg_as_atnt(int reg_id) {
            return "%"+registers[reg_id];
        }

        // LEMBRAR DE COLOCAR O DESLOCAMENTO INVERTIDO
        inline std::string rbp_inderect_as_atnt(int reg_id, int desloc) {
            return to_string(desloc)+"(%rbp)";
        }

        inline void free_reg(int reg_id) {
            this->in_use[reg_id] = false;
        }
    };

    struct Command {
        std::string instruction;
        std::string op1;
        std::string op2;
        bool is_macro;

        std::string to_string();
    };

    struct CodeElement {
        std::vector<Command> code;
        int temp_reg_id;
        std::string label_true;
        std::string label_false;

        inline CodeElement() = default;
        void copy_code(std::vector<Command> from);
    };

    Command define_global_int(const std::string& var_name);

    Command iloc_to_x86(Control& x86_control, const ILOC_Code::Command& iloc_command, const std::string& op1, const std::string& op2);
}
#endif // X_86_HH