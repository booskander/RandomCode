#include <string>
#include <iostream>

// Original Author Booskander
// 2022-09-18
// --------------------some c++ flex------------------------
// ------------russian Multiplication Calculator------------
// 
// 
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

struct liste { 

private:
    long long* buffer;
    int size_;
    int capacity = 10;

    void resize(){
        capacity *=2;
        long long* nuff = new long long[capacity];
        for(int i = 0 ; i < size_; i++){
            nuff[i] = buffer[i];
        }
        delete[] buffer;
        buffer = nuff;
    }
public:
    liste(){ buffer = new long long[capacity];}

    long long get(int idx){
    try { 
        return buffer[idx];
    }
    catch(std::out_of_range e ){
        std::cout << e.what();
        throw idx;
        }
    }


    void push_back(long long& el){
        if(size_ == capacity - 1)
            resize();
        buffer[size_] = el;

        size_++;
    }

    int size(){return size_;}
    ~liste(){
        delete[] buffer;
    }

    void clear(){
        capacity = 10;
        long long* newBuff = new long long[capacity];
        delete[] buffer;
        buffer = newBuff;
        size_ = 0;
    }

};

long long multRusse(long long a, long long b) {

    long long rslt = 0;
    liste* arr1 = new liste();
    liste* arr2 = new liste();

 

    arr1->push_back(a);
    arr2->push_back(b);
    while (a > 0) {
        a = a / 2;
        b = b * 2;
        arr1->push_back(a);
        arr2->push_back(b);   
    }

    for (int i = 0; i < arr1->size(); i++) {
        if (arr1->get(i) % 2 != 0)
            rslt += arr2->get(i);
    }
    return rslt;
}



int main() {
    std::string premier;
    std::string deuxieme;
    long long calcul = 0;
   
    // instanciation des Tests
    Test test1;
    std::cout << "Veuillez entrer le premier nombre : ";
    std::cin >> premier;
    std::cout << "Veuillez entrer le deuxieme nombre : ";
    std::cin >> deuxieme;
    test1.valeur1 = std::stoll(premier);
    test1.valeur2 = std::stoll(deuxieme);
    calcul = multRusse(test1.valeur1, test1.valeur2);
    test1.verification(calcul);
    std::cout << "The result of the russian Multiplication is " << calcul <<std::endl;
    

    

    std::cout << "----------------------------------------------" << std::endl;
    Test test2;
    std::cout << "Veuillez entrer le premier nombre : ";
    std::cin >> premier;
    std::cout << "Veuillez entrer le deuxieme nombre : ";
    std::cin >> deuxieme;
    test2.valeur1 = std::stoll(premier);
    test2.valeur2 = std::stoll(deuxieme);
    calcul = multRusse(test2.valeur1, test2.valeur2);
    test2.verification(calcul);
    std::cout << "The result of the russian Multiplication is " << calcul <<std::endl;
    
    


    std::cout << "----------------------------------------------" << std::endl;
    Test test3;
    std::cout << "Veuillez entrer le premier nombre : ";
    std::cin >> premier;
    std::cout << "Veuillez entrer le deuxieme nombre : ";
    std::cin >> deuxieme;
    test3.valeur1 = std::stoll(premier);
    test3.valeur2 = std::stoll(deuxieme);
    calcul = multRusse(test3.valeur1, test3.valeur2);
    test3.verification(calcul);
    std::cout << "The result of the russian Multiplication is " << calcul <<std::endl;

    


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
