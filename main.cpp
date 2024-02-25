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

class RightTriangle : public Triangle
{
public:
    RightTriangle() : Triangle()
    {
        printf("RightTriangle()\n");
    }

    RightTriangle(const float a) : Triangle(a, a, a)
    {
        printf("RightTriangle(const float a)\n");
    }

    RightTriangle(const RightTriangle& rt)
    {
        printf("RightTriangle(const RightTriangle &rt)");
        a = b = c = rt.a;
    }

    ~RightTriangle()
    {
        printf("%f, %f, %f\n", a, b, c);
        printf("~RightTriangle()\n");
    }
};

int main()
{
    RightTriangle* rt = new RightTriangle(3);
    delete rt;

    return 0;
}
