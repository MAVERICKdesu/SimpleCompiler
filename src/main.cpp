#include "common.h"
#include <fstream>

extern TreeNode *root;
extern FILE *yyin;
extern int yyparse();

using namespace std;
int main(int argc, char *argv[])
{
    freopen("test.s", "w" , stdout);
    cout << ".bss\n";
    if (argc == 2)
    {
        FILE *fin = fopen(argv[1], "r");
        if (fin != nullptr)
        {
            yyin = fin;
        }
        else
        {
            cout << "failed to open file: " << argv[1] << endl;
        }
    }
    yyparse();
    if(root != NULL) {
		get_label(root);
        root->genNodeId();
        //root->printAST();
		root->gen_asm();
    }
    fclose(stdout);
    return 0;
}
