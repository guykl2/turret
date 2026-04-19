//
// Created by guyka on 4/20/2026.
//

#ifndef UNTITLED8_PID_H
#define UNTITLED8_PID_H
class pid {
    public:
        double kp;
        double ki;
        double kd;
        double calculate(double error) {
            return error * kp;
        }


        pid() = default;

        pid(int i, int i1, int i2);
};


#endif //UNTITLED8_PID_H