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

    float area()
    {
        return a * a * 0.43301270189;
    }
};

class CompositionOfTriangles
{
protected:
    Triangle* t1;
    Triangle* t2;

public:
    CompositionOfTriangles()
    {
        printf("CompositionOfTriangles()\n");
        t1 = new Triangle(1, 1, 1);
        t2 = new Triangle(2, 2, 2);
    }

    CompositionOfTriangles(const float a1, const float b1, const float c1, const float a2, const float b2,
                           const float c2)
    {
        printf(
            "CompositionOfTriangles(const float a1, const float b1, const float c1, const float a2, const float b2, const float c2)");
        t1 = new Triangle(a1, b1, c1);
        t2 = new Triangle(a2, b2, c2);
    }

    CompositionOfTriangles(const CompositionOfTriangles& cot)
    {
        printf("CompositionOfTriangles(const CompositionOfTriangles &cot)\n");
        t1 = new Triangle(*cot.t1);
        t2 = new Triangle(*cot.t2);
    }

    ~CompositionOfTriangles()
    {
        printf("~CompositionOfTriangles()\n");
        delete t1;
        delete t2;
    }
};


int main()
{
    CompositionOfTriangles* cot1 = new CompositionOfTriangles();
    CompositionOfTriangles* cot2 = new CompositionOfTriangles(*cot1);

    delete cot1;
    delete cot2;

    return 0;
}
