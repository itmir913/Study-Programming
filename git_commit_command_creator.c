#include <stdio.h>
#include <dirent.h>
#include <windows.h>

/**
 * C Program to list all files and sub-directories in a directory
 * https://www.geeksforgeeks.org/c-program-list-files-sub-directories-directory/
 */
int main(int argc, char **argv) {
    struct dirent *de;  // Pointer for directory entry

    // opendir() returns a pointer of DIR type.
    DIR *dr = opendir(".");

    if (dr == NULL) {  // opendir returns NULL if couldn't open directory
        printf("Could not open current directory");
        return 0;
    }


    FILE *fp = fopen("codeup_git_commit.cmd", "w+");
    fseek(fp, 0, SEEK_SET);
    fputs("@echo off\n", fp);

    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
    // for readdir()
    while ((de = readdir(dr)) != NULL) {
        char *name = de->d_name;
        int len = strlen(name);

        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
            continue;
        }

        char token[3];
        strncpy(token, name + (len - 2), 2);

        if (strcmp(token, ".c") == 0) {
            char *codeup_number = strtok(name, "_");
            fprintf(fp, "git add %s*.c && git commit -m \"Code Up %s by C\"\n", codeup_number, codeup_number);
            printf("%s\n", name);
        }

    }

    closedir(dr);
    fputs("pause\n", fp);
    fclose(fp);

    system("pause");

    return 0;
}
