#include <cstdio>
using namespace std;

class Triangle
{
public:
    float a, b, c;
    Triangle()
    {
        printf("Triange()\n");
        a = b = c = 1;
    }
    Triangle(const float a, const float b, const float c)
    {
        printf("Triangle(const float a, const float b, const float c)\n");
        this->a = a;
        this->b = b;
        this->c = c;
    }
    Triangle(const Triangle &t)
    {
        printf("Triangle(const Triangle &t)\n");
        a = t.a;
        b = t.b;
        c = t.c;
    }
    ~Triangle()
    {
        printf("%f, %f, %f\n", a, b, c);
        printf("~Triangle()\n");
    }
};

int main()
{
    return 0;
}