/*-------------------------------------------
   System - Multiple File Copy Program

   Seung Hun Han
   KITRI BoB Security Product Dev 9th
   dev.shhan@gmail.com
--------------------------------------------*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int DIRSTR_MAX = 256; // Limit Directory MAX Size 256.


/*-------------------------------------------
   Procedure: file_valid

   Purpose: Check whether the input file is valid or not

   Output:
   File Valid -> 1
   File Invalid -> 0
--------------------------------------------*/
int file_valid(char* origin_dir, char* file_name){
    char* file_dir = malloc(sizeof(char) * DIRSTR_MAX); char* slash = malloc(sizeof(char)); *slash = '/';
    strcpy(file_dir, origin_dir);
    strcat(file_dir, slash);
    strcat(file_dir, file_name);

    if(access(file_dir, 0) == 0) return 1;
    else return 0;
}

/*-------------------------------------------
   Procedure: dir_valid

   Purpose: Check whether the DIR is valid or not

   Output:
   DIR Valid -> 1
   DIR Invalid -> 0
--------------------------------------------*/
int dir_valid(char* dir){
    if(access(dir, 0) == 0) return 1;
    else return 0;
}


int main(int argc, char *argv[])
{


    // INPUT VALIDATION CHECK
    printf("ARGC : %d\n", argc);
    if ( argc < 3 ) {
        printf("Usage : %s <filename1> <filename2> ... <filenameN> <directory name>\n", argv[0]);
        return 0;
    }
    char origin_dir[DIRSTR_MAX];
    getcwd(origin_dir, DIRSTR_MAX); // Get Current DIR -> curr_dir
    for(int i=1;i<argc-1;i++){
        if(file_valid(origin_dir, argv[i]) == 0){
            printf("ERROR: Number %d file dosen't exist\n", i); // File Validation Check 1 ~ N
            return 1;
        }
    }
    if(dir_valid(argv[argc-1]) == 0){
        printf("ERROR: %s DIR dosen't exist\n", argv[argc-1]); // DIR Validation Check
        return 1;
    }


    // COPY FILES

    FILE *fd, *dest;
    char buf[257];
    int len;

    for(int i=1; i<argc-1; i++){
        fd = fopen(argv[i], "r");
        chdir(argv[argc-1]);
        dest = fopen(argv[i], "w");


        printf("\nCopying File Number: %d\n", i);
        while ( len = fread(buf, 1, 256, fd)  )
        {
            buf[len] = '\0';
            fwrite(buf, 1, len, dest);
            printf("Length : %d\n", len);
            printf("%s\n", buf);
        }

        fclose(dest);
        fclose(fd);

        chdir(origin_dir);
    }

    return 0;
}
