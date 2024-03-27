#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

// food  temperature  cell
// [1    1     1]



using namespace std;


class Enviroment{
    private:
        int plane[15][15][3];
        int temperature;
    
    public:
        Enviroment(int);
        void weather(int);
        void set_food(int, int);
        bool get_food(int, int);
        bool set_cell(int, int);
        int get_temperature();

};

Enviroment::Enviroment(int _temperature){
    temperature = _temperature;
}

void Enviroment::weather(int _grades){
    temperature = temperature + _grades;
    
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j ++){
            plane[i][j][1] = temperature;
        }
    }
}


void Enviroment::set_food(int x, int y){
    plane[x][y][0] = 1;

}

bool Enviroment::get_food(int x, int y){
    if(plane[x][y][0] == 1){
        plane[x][y][0] = 0;
        return true;
    } else{
        return false;
    };

}

bool Enviroment::set_cell(int x, int y){
    plane[x][y][2] = 1;
    return true;
}


int Enviroment::get_temperature(){
    return temperature;
}





class Cell{
    private:

        int adn;
        int age = 0;

        int energy;
        int top_energy;

        bool food;
        int membrane_hardness;
        int temperature;


    public:
        Cell(int adn);

        void vitals_data();

        void core();

        //Function

        void feed();
        void heal();
        void grow();

        void mitosis();
        void dead();


        //Question to enviroment
        int get_temperature(int);
        bool get_food(bool);

        void time_of_life();


};

Cell::Cell(int _adn){

    energy = int(_adn/10000);
    
    membrane_hardness = int((_adn - (energy*10000))/100);

    top_energy = _adn - ( int(_adn / 100) * 100 ); 
    
}

void Cell::grow(){
    age++;
}


void Cell::vitals_data(){
    cout << "Tiempo de vida restante: " << energy << endl;
    cout << "Membrana: " << membrane_hardness << endl;
    cout << "Sensacion de calor: " << temperature << endl;
    cout << "Edad: " << age << endl;
}

void Cell::dead(){
    cout << "Celula muerta ";
}

int Cell::get_temperature(int _temperature){
    temperature = _temperature;
    return temperature;
}

bool Cell::get_food(bool food){
    return food;
}

void Cell::time_of_life(){
    energy--;
}



void Cell::heal(){
    if(energy > 50){
        membrane_hardness++;
        energy = energy - 3;
    }
}


void Cell::feed(){

    if (energy < top_energy){
        energy = energy + 5;
        cout << "feed " << endl;

    } else {
        cout << "No feed " << endl;
    }
    
}

void Cell::mitosis(){
    cout << "En teoria te puedes reproducir ";
}

void Cell::core(){

    grow();

    //Nutrition
    if(Cell::get_food(true)){
        feed();
    };


    //Reproduction
    if (energy >= 90 && temperature <= 30 && temperature >= 10 && age > 50){
        mitosis();
    };

    if(temperature <= 0 || temperature >= 45){
        
    }

    
    //DEAD
    if (membrane_hardness == 0){
        dead();
    };
    if (energy == 0){
        dead();
    };

    if (age >= 150){
        dead();
    }
}



int main(){

    Enviroment env(20);

    Cell c1(505050);

        while(true){
            sleep(1);


            env.set_cell(15, 15);

            c1.get_temperature(env.get_temperature());  

            c1.vitals_data();
            c1.time_of_life();
            c1.core();
            //Each cycle time energy lose one
            cout << "\n";    
            cout << "---HAPPEN ONE CYCLES" << endl;
            cout << "\n";

        }




        return 0;
}
