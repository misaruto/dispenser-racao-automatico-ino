#include <Stepper.h>

// Definições dos pinos do motor
#define e1 8
#define e2 9
#define e3 10
#define e4 11

const int passosPorGiro = 64;

class MotorPasso {
private:
    Stepper motor;
    int velocidade;

public:
   
    MotorPasso(int pin1, int pin2, int pin3, int pin4, int passosPorGiro, int velocidade)
        : motor(passosPorGiro, pin1, pin3, pin2, pin4) { 
        
        this->velocidade = velocidade;

        motor.setSpeed(this->velocidade);
    }

    void girar() {
        motor.step(passosPorGiro);
    }
};
