#include <cstdio>
using namespace std;

class Triangle
{
protected:
    float a, b, c;

public:
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

    Triangle(const Triangle& t)
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

    void scale(float k)
    {
        a = a * k;
        b = b * k;
        c = c * k;
    }

    float perimeter();
};

float Triangle::perimeter()
{
    return a + b + c;
}

int main()
{
    Triangle *t = new Triangle(3, 4, 5);
    printf("%f", t->perimeter());

    return 0;
}
