#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int hide_hidden = 1;

void custom_ls(char* dirname)
{
    DIR* dirp;
    struct dirent* dir_entry;
    
    dirp = opendir(dirname);
    if (dirp == NULL) {
        printf("Error!\n");
        return;
    }

    while ((dir_entry = readdir(dirp)) != NULL) {
        if (hide_hidden && dir_entry->d_name[0] == '.')
            continue;
        printf("%s\n", dir_entry->d_name);

    }

}

int main(int argc, char** argv) 
{
    char opt;

    while ((opt = getopt(argc, argv, "a:h")) != -1) {
        switch (opt) {
            case 'h':
                printf("Usage: custom_ls [-a] <directory-name>\n");
                return 0;
            case 'a':
                hide_hidden = 0;
                custom_ls(optarg);
                break;
            case '?':
                hide_hidden = 0;
                custom_ls(".");
                break;
        }
    }

    // if no options are provided, optind provides the index of the directory name
    if (argc == 1)
        custom_ls(".");
    else if (optind < argc)
        custom_ls(argv[optind]);

    return 0;
}
