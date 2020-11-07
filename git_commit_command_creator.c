#include <stdio.h>
#include <dirent.h>
#include <windows.h>

/**
 * CodeUp 홈페이지에서 제출한 코드를 다운로드 받은 뒤
 * 프로그램을 실행하면 cmd 파일이 생성된다.
 * 다운받은 .c 파일과 생성된 .cmd 파일을 모두 git 폴더로 복사한 뒤에
 * cmd를 실행하면 자동으로 commit과 push를 완료해준다.
 * 
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
    fputs("git push origin master\n", fp);
    fputs("pause\n", fp);
    fclose(fp);

    system("pause");

    return 0;
}
