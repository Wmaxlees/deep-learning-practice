#include <iostream>
#include <stdlib.h>

#define        N       13

float data[2][N] = {
    {2.9f, 6.7f, 4.9f, 7.9f, 9.8f, 6.9f, 6.1f, 6.2f, 6.0f, 5.1f, 4.7f, 4.4f, 5.8f},
    {4.0f, 7.4f, 5.0f, 7.2f, 7.9f, 6.1f, 6.0f, 5.8f, 5.2f, 4.2f, 4.0f, 4.4f, 5.2f}
};

struct Delta {
    float m;
    float b;
};

Delta gradient_descent_step(float data[2][13], float current_m, float current_b, float alpha) {
    Delta result;
    result.m = 0.0f;
    result.b = 0.0f;

    for (int i = 0; i < N; ++i) {
        result.b += -1/(float)N * (data[1][i] - current_m * data[0][i]);
        result.m += -1/(float)N * data[0][i] * (data[1][i] - ((current_m * data[0][i]) + current_b));
    }

    result.m = current_m - (alpha * result.m);
    result.b = current_b - (alpha * result.b);

    return result;
}

int main(int argc, char** argv) {
    float m = 0;
    float b = 0;

    for (int i = 0; i < 5000000; ++i) {
        Delta newData = gradient_descent_step(data, m, b, .0000002f);

	m = newData.m;
        b = newData.b;

        std::cout << m << "x + " << b << std::endl;
    }  

    std::cout << m << "x + " << b << std::endl; 

    return EXIT_SUCCESS;
}

