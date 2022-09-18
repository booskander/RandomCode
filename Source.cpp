#include <string>
#include <iostream>

// Original Author Booskander
// 2022-09-18
// --------------------some c++ flex------------------------
// ------------russian Multiplication Calculator------------
// 
// 
// Ps: Yes it's in french, tokebekicitte
using namespace std;

struct Test {
    long long valeur1 = 0; 
    long long valeur2 = 0;
    bool isPassed = false;
    void verification(long long calcul) {
        if (calcul == (this->valeur1 * this-> valeur2))
            isPassed = true;
    }
};

long long multRusse(int a, int b) {

    long long rslt = 0;
    int capacity = 12;
    long long* arr1 = new long long[capacity];
    long long* arr2 = new long long[capacity];

    int idx = 0; 

    arr1[idx] = a;
    arr2[idx] = b;
    while (a > 0) {
        if (idx == capacity)
            capacity *= 2;
        idx++;

        a = a / 2;
        b = b * 2;
        arr1[idx] = a;
        arr2[idx] = b;
    }

    for (int i = 0; i < idx ; i++) {
        if (arr1[i] % 2 != 0)
            rslt += arr2[i];
    }
    delete[] arr1, arr2;
    return rslt;
}



int main() {
    std::string premier;
    std::string deuxieme;
   
    // instanciation des Tests
    Test test1;
    std::cout << "Veuillez entrer le premier nombre : ";
    std::cin >> premier;
    std::cout << "Veuillez entrer le deuxieme nombre : ";
    std::cin >> deuxieme;
    test1.valeur1 = std::stoll(premier);
    test1.valeur2 = std::stoll(deuxieme);

    test1.verification(multRusse(test1.valeur1, test1.valeur2));

        

    

    std::cout << "----------------------------------------------" << std::endl;
    Test test2;
    std::cout << "Veuillez entrer le premier nombre : ";
    std::cin >> premier;
    std::cout << "Veuillez entrer le deuxieme nombre : ";
    std::cin >> deuxieme;
    test2.valeur1 = std::stoll(premier);
    test2.valeur2 = std::stoll(deuxieme);

    test2.verification(multRusse(test2.valeur1, test2.valeur2));

    
    


    std::cout << "----------------------------------------------" << std::endl;
    Test test3;
    std::cout << "Veuillez entrer le premier nombre : ";
    std::cin >> premier;
    std::cout << "Veuillez entrer le deuxieme nombre : ";
    std::cin >> deuxieme;
    test3.valeur1 = std::stoll(premier);
    test3.valeur2 = std::stoll(deuxieme);

    test3.verification(multRusse(test3.valeur1, test3.valeur2));
    


    std::cout << "----------------------------------------------" << std::endl;

    Test* mesTests = new Test[3];

    mesTests[0] = test1;
    mesTests[1] = test2;
    mesTests[2] = test3;
    int ctr = 0;


    // Sortie des Test


    for (int i = 0; i < 3; i++) {
        /*std::cout << "----------------------------" << endl;
        std::cout << mesTests[i].isPassed << endl;
        std::cout << "----------------------------" << endl;*/
        if (mesTests[i].isPassed)
            ++ctr;
    }
        

    std::cout << std::to_string(ctr) + " /3 tests passent" << endl;


    delete[] mesTests;

    return 0;
}