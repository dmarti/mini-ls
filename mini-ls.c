#include <dirent.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* List directory contents recursively and indented. */

void listdir(int level)
{
    struct dirent **namelist;
    int count;
    int i;

    count = scandir(".", &namelist, NULL, alphasort);
    if (count < 0) {
        perror("scandir");
    } else {
        for (i=0; i<count; i++) {
            if (!strncmp(".", namelist[i]->d_name, 1)) {
	        continue;
	    }
            printf("%*s%s\n", level, "", namelist[i]->d_name);
            if (DT_DIR == namelist[i]->d_type) {
		chdir(namelist[i]->d_name);
		listdir(level + 2);
		chdir("..");
	    }
            free(namelist[i]);
        }
    }
    free(namelist); 
}

int main(void)
{
    listdir(0);
    return 0;
}
