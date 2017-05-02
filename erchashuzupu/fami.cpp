#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "famil.h"


void main()
    {
	BTree bt;
	bt=creatree();
	disptree(bt);
	while(1){
	
	findson(bt);
	}
    }
