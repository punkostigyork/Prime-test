/**@file gtest.cpp
 * @brief A tesztprogram
 * @author Pünkösti Györk
 */

#include <iostream>
#include "menu.h"

using std::cout;
using std::cin;

int main() {
    int menu;

    do {
        cout << "Mit műveletet szeretne végrehajtani?\n";
        cout
                << "1. Két számot összeadni.\n"
                << "2. Két számot kivonni (a különbségük abszolút értékét adja vissza)\n"
                << "3. Két számot összeszorozni.\n"
                << "4. Két számot egészen elosztani.\n"
                << "5. Ellenőrizni, hogy egy szám prím-e.\n"
                << "6. Kilépés\n"
                << "\n";

        cin >> menu;

        switch(menu) {
            case 1: {
                int option;

                cout << "Hogyan szereté megadni az összeadandó számokat?\n";
                cout
                        << "1. A billentyűzetről beolvasva.\n"
                        << "2. File-ból beolvasva.\n"
                        << "\n";

                cin >> option;
                cout << std::endl;

                switch(option) {
                    case 1: {
                        menu_add();
                        break;
                    }
                    case 2:
                        try {
                            menu_file_add();
                        } catch(std::runtime_error& e) {
                            std::cout << e.what() << std::endl;
                        }
                        break;
                    default:
                        cout << "\nIlyen művelet nincsen!\n";
                        break;
                }

                break;
            }

            case 2: {
                int option;

                cout << "Hogyan szereté megadni a kivonandó számokat?\n";
                cout
                        << "1. A billentyűzetről beolvasva.\n"
                        << "2. File-ból beolvasva.\n"
                        << "\n";

                cin >> option;

                switch (option) {
                    case 1:
                        menu_sub();
                        break;
                    case 2:
                        try {
                            menu_file_sub();
                        } catch(std::runtime_error& e) {
                            std::cout << e.what() << std::endl;
                        }
                        break;
                    default:
                        cout << "\nIlyen művelet nincsen!\n";
                        break;
                }

                break;
            }

            case 3: {
                int option;

                cout << "Hogyan szereté megadni az összeszorzandó számokat?\n";
                cout
                        << "1. A billentyűzetről beolvasva.\n"
                        << "2. File-ból beolvasva.\n"
                        << "\n";

                cin >> option;

                switch(option) {
                    case 1:
                        menu_mul();
                        break;
                    case 2:
                        try {
                            menu_file_mul();
                        } catch(std::runtime_error& e) {
                            std::cout << e.what() << std::endl;
                        }
                        break;
                    default:
                        cout << "\nIlyen művelet nincsen!\n";
                        break;
                }

                break;
            }

            case 4: {
                int option;

                cout << "Hogyan szereté megadni az elosztandó számokat?\n";
                cout
                        << "1. A billentyűzetről beolvasva.\n"
                        << "2. File-ból beolvasva.\n"
                        << "\n";

                cin >> option;

                switch (option) {
                    case 1:
                        menu_div();
                        break;
                    case 2:
                        try {
                            menu_file_div();
                        } catch(std::runtime_error& e) {
                            std::cout << e.what() << std::endl;
                        }
                        break;
                    default:
                        cout << "\nIlyen művelet nincsen!\n";
                        break;
                }

                break;
            }

            case 5: {
                int option;

                cout << "Hogyan szereté megadni a számot?\n";
                cout
                        << "1. A billentyűzetről beolvasva.\n"
                        << "2. File-ból beolvasva.\n"
                        << "\n";

                cin >> option;

                switch(option) {
                    case 1:
                        menu_fermat();
                        break;
                    case 2:
                        try{
                            menu_file_fermat();
                        } catch(std::runtime_error& e) {
                            std::cout << e.what() << std::endl;
                        }
                        break;
                    default:
                        cout << "\nIlyen művelet nincsen!\n";
                        break;
                }

                break;
            }

            case 6:
                break;
            default:
                cout << "\nIlyen művelet nincsen!\n";
                break;
        }

        cout << "\n";
    } while(menu != 6);

    return 0;
}