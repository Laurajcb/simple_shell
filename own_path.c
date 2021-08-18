#include "shell.h"

#define TESTING_OF_OWN_PATH

char **own_path(void)
{
    int i = 0;
    for(i = 0; environ[i]; i++)
    {
        _putstr("%s\n",environ[i]);
    }

}

#ifdef TESTING_OF_OWN_PATH
int main()
{

}




#endif