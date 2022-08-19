// STEP _CPP _classwork49 _19.08.22
/*
ООП

Files
fstream


*/


#include <iostream>
#include <fstream> //ifstream читать + ofstream писать

/*
enum _Openmode {
    in = 0x01, //открыть только для чтения
    out = 0x02, //открыть только для записи
    ate = 0x04, //установить указатель на
    //конец файла
    app = 0x08, //дописывать данные в конец файла
    trunc = 0x10, //усечь файл до нулевой длины
    _Nocreate = 0x40, //если файл не существует,
    //ошибка открытия
    _Noreplace = 0x80, //если файл уже существует,
    //ошибка открытия
    binary = 0x20 //открыть файл для двоичного
    //обмена
};
ios::mode
*/

//пишем в файл
//2 3 - число строк и столбцов
//4 5 6
//7 8 9
int main()
{

    char ans;

    std::string mes[8]{
        "1. Write DATA to file\n",
        "2. Print DATA from file\n",
        "3. Exit\n",
        "Your choice: ",
        "Enter filename: ",
        "Enter array size: ",
        "Enter element of array: ",
        "Error file open\n"
    };

    do {
        for (int i = 0; i < 4; i++) {
            std::cout << mes[i];
        }
        std::cin >> ans;

    } while (ans < '1' || ans > '3');

    if (ans == '3') {
        std::cout << "Exit... \n";
        return 0;
    }


    char filename[100];
    int nRow;
    int nCol;

    int** arr;
    std::cout << mes[4];
    std::cin >> filename;

    if (ans == '1') {
        std::ofstream outF(filename, std::ios::out);
        if (!outF) {
            std::cout << mes[7];
            return -1;
        }
        std::cout << mes[5];
        std::cin >> nRow >> nCol;

        outF << nRow << " " << nCol << "\n";
        arr = new int* [nRow];
        for (int i = 0; i < nRow; i++) {
            arr[i] = new int[nCol];
        }

        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nCol; j++) {
                std::cout << mes[6];
                std::cin >> arr[i][j];
            }
        }

        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nCol; j++) {
                outF << arr[i][j] << " ";
            }
            /*if (i < nRow-1) */outF << "\n";
        }
        outF.close();
    }
    else {
        std::ifstream inF(filename, std::ios::in | std::ios::_Nocreate);
        if (!inF) {
            std::cout << mes[7];
            return -1;
        }

        int nRow;
        int nCol;

        inF >> nRow;
        inF >> nCol;

        int** arr = new int*[nRow];
        for (int i = 0; i < nRow; i++) {
            arr[i] = new int[nCol];
        }


       for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nCol; j++) {


                int dig;
                inF >> dig;
                arr[i][j] = dig;
                //std::cout << symb << " ";
                std::cout << arr[i][j] << " ";
            }
            std::cout << "\n";
        }


        inF.close();
    }
    

    return 0;
}
