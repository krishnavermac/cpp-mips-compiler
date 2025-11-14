#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("out.s");
    if (!out.is_open()) {
        cerr << "❌ Failed to create out.s file!" << endl;
        return 1;
    }

    // === MIPS header ===
    out << ".text\n.globl main\n\n";
    out << "main:\n";

    // === Function prologue ===
    out << "    addi $sp,$sp,-8\n";
    out << "    sw $ra,4($sp)\n";
    out << "    sw $fp,0($sp)\n";
    out << "    addi $fp,$sp,8\n\n";

    // === int a = 5 ===
    out << "    li $t0,5\n";        // load 5
    out << "    sw $t0,-4($fp)\n";  // store a at fp-4

    // === int b = 2 ===
    out << "    li $t1,2\n";        // load 2
    out << "    sw $t1,-8($fp)\n";  // store b at fp-8

    // === return a * b + 3 ===
    out << "    lw $t0,-4($fp)\n";  // load a
    out << "    lw $t1,-8($fp)\n";  // load b
    out << "    mul $t2,$t0,$t1\n"; // t2 = a*b
    out << "    li $t3,3\n";        // load 3
    out << "    add $v0,$t2,$t3\n"; // v0 = a*b + 3\n\n";

    // === print result ===
    out << "    move $a0,$v0\n";
    out << "    li $v0,1\n";
    out << "    syscall\n\n";

    // === exit ===
    out << "    li $v0,10\n";
    out << "    syscall\n\n";

    out.close();
    cout << "✅ MIPS code with variables generated in out.s!" << endl;
    return 0;
}