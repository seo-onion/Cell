#include <iostream>
#include <string>
#include <unistd.h>


class Cell{
    private:
        int DNA;

        int membrane_hardness;
        
        int energy;
        int temperature;
        int age = 0;

    public: 

        Cell(int);

        void core(int, bool);

        void dead();
        void grow();

        void divide();
        void feed();
        void heal();
        
        void getter();

};  

Cell::Cell(int RNA){
    energy = int(RNA/100);
    membrane_hardness = RNA - int(RNA/100) * 100 ;
}

void Cell::getter(){
    std::cout << "Energy: " << energy << std::endl;
    std::cout << "Membrane: " << membrane_hardness << std::endl;
    std::cout << "Age: " << age << std::endl;
}

void Cell::dead(){
    std::cout << "Cell dead" << std::endl;
}

void Cell::grow(){
    age++;
    energy--;
}

void Cell::divide(){
    std::cout << "dividing" << std::endl;
}

void Cell::heal(){
    membrane_hardness++;
    std::cout << "Healing" << std::endl;
}

void Cell::feed(){
    energy = energy + 10;
    std::cout << "Eating" << std::endl;
}

void Cell::core(int temperature, bool food){

    if(temperature < 0 || temperature > 40){
        membrane_hardness--;
    };

    if (food){
        feed();
    };

    if (energy <= 0 || membrane_hardness <= 0){
        dead();
    };

    if (energy >= 50 && age >= 50 && temperature >= 0 && temperature<=35){
        divide();
    }

    if (energy > 25 && membrane_hardness < 10) {
        heal();
    }

    grow();

}

int main(){

    int temperature = 20;
    bool food = true;

    int instruction = 0;

    Cell c1(1010);

    while(true){

            

            sleep(1);

            c1.core(temperature, food);
            c1.getter();

            std::cout << "\n";    
            std::cout << "---HAPPEN ONE CYCLES" << std::endl;
            std::cout << "\n";


            //2 for food
            //1 for temperature

            std::cin >> instruction;
            
            if(int(instruction/100) == 1){
                temperature = instruction - int(instruction/100) * 100;
            } else if(instruction == 2){
                food = true;
            } else{
                food = false;
            }


        }

    return 0;



}

