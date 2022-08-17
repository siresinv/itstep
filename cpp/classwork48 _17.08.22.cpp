// STEP _CPP _classwork48 _17.08.22
/*
ООП

Files
ofstream

*/

#include <iostream>
#include <cstdio>
#include <io.h>
#include <direct.h>

// cw48-test1.txt

void renameFile() {
    char oldname[100];
    char newname[100];
    std::cout << "Enter old name: ";
    std::cin >> oldname;
    std::cout << "Enter new name: ";
    std::cin >> newname;

    if (rename(oldname, newname) != 0) {
        std::cout << "Error!\n";
    }
    else {
        std::cout << "OK!\n";

    }
    
    

}

void removeFile() {
    char name[100];
    std::cout << "Enter name: ";
    std::cin >> name; 
    if (remove(name) != 0) {
        std::cout << "Error!\n";
    }
    else {
        std::cout << "OK!\n";
    }
}

void searchFiles() {
    char name[100];
    std::cout << "Enter name: ";
    std::cin >> name;
    _finddata_t* fileinfo = new _finddata_t;
    //_finddata_t* fileinfo = new _finddata_t;
    double done = _findfirst(name, fileinfo);
    double next_done = done;
    std::cout << next_done << " -- ";
    int count = 0;
    while (next_done != -1) {
        count++;
        std::cout << fileinfo->name << std::endl;
        next_done = _findnext(done, fileinfo);
    }
    std::cout << "count: " << count << std::endl;
    _findclose(done);
    delete fileinfo;
}

void renameDir() {
    char oldnameDir[100];
    char newnameDir[100];
    std::cout << "Enter old DIR name: ";
    std::cin >> oldnameDir;
    std::cout << "Enter new DIR name: ";
    std::cin >> newnameDir;

    if (rename(oldnameDir, newnameDir) != 0) {
        std::cout << "Error!\n";
    }
    else {
        std::cout << "OK!\n";

    }
}

void removeDir() {
    char nameDir[100];
    std::cout << "Enter DIR name: ";
    std::cin >> nameDir;
    if (_rmdir(nameDir) == -1) {
        std::cout << "Error!\n";
    }
    else {
        std::cout << "OK!\n";
    }
}

void createDir() {
    char nameDir[100];
    std::cout << "Enter DIR name: ";
    std::cin >> nameDir;
    if (_mkdir(nameDir) == -1) {
        std::cout << "Error!\n";
    }
    else {
        std::cout << "OK!\n";
    }
}

int main()
{

    int ans;
    do {
        std::cout << "1 - Rename File\n";
        std::cout << "2 - Remove File\n";
        std::cout << "3 - Search Files\n";
        std::cout << "4 - Rename Dir\n";
        std::cout << "5 - Remove Dir\n";
        std::cout << "6 - Create Dir\n";

        std::cout << "0 - Exit  \n";
        std::cout << "Your choice: ";

        std::cin >> ans;

        switch (ans) {
        case 1:
            renameFile();
            break;
        case 2:
            removeFile();
            break;
        case 3:
            searchFiles();
            break;
        case 4:
            renameDir();
            break;
        case 5:
            removeDir();
            break;
        case 6:
            createDir();
            break;
        default:
            std::cout << "Exit ...";
            break;
        }

    } while (ans != 0);




    

    return 0;
}
