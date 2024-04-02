//
// Created by punkostigyork on 2023.06.01..
//

#include <cstring>
#include <iostream>

bool cmp(const char* a, const char* b) {
    if(strcmp(a, b) == 0)
        return true;
    return false;
}

void TEST(const char* str, unsigned int count) {
    switch(count) {
        case 0:
            if (cmp(str, "125090")) std::cout << "SIKERES!\n";
            else std::cout << "SIKERTELEN!\n";
            break;
        case 1:
            if (cmp(str, "650")) std::cout << "SIKERES!\n";
            else std::cout << "SIKERTELEN!\n";
            break;
        case 2:
            if (cmp(str, "122006")) std::cout << "SIKERES!\n";
            else std::cout << "SIKERTELEN!\n";
            break;
        case 3:
            if (cmp(str, "600")) std::cout << "SIKERES!\n";
            else std::cout << "SIKERTELEN!\n";
            break;
        case 4:
            if (cmp(str, "190511016")) std::cout << "SIKERES!\n";
            else std::cout << "SIKERTELEN!\n";
            break;
        case 5:
            if (cmp(str, "15625")) std::cout << "SIKERES!\n";
            else std::cout << "SIKERTELEN!\n";
            break;
        case 6:
            if (cmp(str, "80")) std::cout << "SIKERES!\n";
            else std::cout << "SIKERTELEN!\n";
            break;
        case 7:
            if (cmp(str, "25")) std::cout << "SIKERES!\n";
            else std::cout << "SIKERTELEN!\n";
            break;
        default:
            break;
    }
}

void TEST_PRIME(bool flag, const unsigned int count) {
    switch(count) {
        case 0:
            if(flag) std::cout << "1. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 1:
            if(!flag) std::cout << "1. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 2:
            if(flag) std::cout << "2. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 3:
            if(flag) std::cout << "3. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 4:
            if(flag) std::cout << "4. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 5:
            if(!flag) std::cout << "5. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 6:
            if(!flag) std::cout << "6. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 7:
            if(flag) std::cout << "7. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 8:
            if(flag) std::cout << "8. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 9:
            if(!flag) std::cout << "9. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 10:
            if(flag) std::cout << "10. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 11:
            if(!flag) std::cout << "11. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 12:
            if(flag) std::cout << "12. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 13:
            if(!flag) std::cout << "13. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 14:
            if(!flag) std::cout << "14.SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 15:
            if(!flag) std::cout << "15. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        case 16:
            if(flag) std::cout << "16. SIKERES!" << std::endl;
            else std::cout << "SIKERTELEN!" << std::endl;
            break;
        default:
            break;
    }
}
