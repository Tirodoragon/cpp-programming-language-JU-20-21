#include <iostream>

using std::cout;
using std::endl;

class Drawing {
    public:
        virtual ~Drawing() {}

        virtual void drawLine() {}
        virtual void drawCircle() {}
};

class DP1 {
    public:
        DP1() {}

        void draw_a_line() {
            cout << "V1 line" << endl;
        }
        void draw_a_circle() {
            cout << "V1 circle" << endl;
        }
};

class DP2 {
    public:
        DP2() {}

        void drawline() {
            cout << "V2 line" << endl;
        }
        void drawcircle() {
            cout << "V2 circle" << endl;
        }
};

class V1Drawing : public Drawing {
    public:
        V1Drawing(DP1 d1) : dp(d1) {}

        void drawLine() override {
            this->dp.draw_a_line();
        }
        void drawCircle() override {
            this->dp.draw_a_circle();
        }

    private:
        DP1 dp;
};

class V2Drawing : public Drawing {
    public:
        V2Drawing(DP2 d2) : dp(d2) {}

        void drawLine() override {
            this->dp.drawline();
        }
        void drawCircle() override {
            this->dp.drawcircle();
        }

    private:
        DP2 dp;
};

class Shape {
    public:
        virtual ~Shape() {}

        virtual void draw() {}
        virtual void setLib(Drawing *i) {}
};

class Rectangle : public Shape {
    public:
        Rectangle(Drawing *i) : imp(i) {}

        virtual ~Rectangle() {}

        void draw() {
            imp->drawLine();
        }
        void setLib(Drawing *i) {
            imp = i;
        }

    private:
        Drawing *imp;
};

class Circle : public Shape {
    public:
        Circle(Drawing *i) : imp(i) {}

        virtual ~Circle() {}

        void draw() {
            imp->drawCircle();
        }
        void setLib(Drawing *i) {
            imp = i;
        }

    private:
        Drawing *imp;
};

int main()
{
    DP1 library1; // pierwsza biblioteka
    DP2 library2; // druga biblioteka

    Drawing *d1 = new V1Drawing(library1);
    Drawing *d2 = new V2Drawing(library2);

    Shape *p1 = new Rectangle(d1);
    Shape *p2 = new Circle(d2);

    p1->draw(); // rectangle linia V1
    p2->draw(); // circle okrag V2
    p1->setLib(d2);
    p2->setLib(d1);
    p1->draw(); // rectangle linia V2
    p2->draw(); // circle okrag V1

    delete p1;
    delete p2;
    delete d1;
    delete d2;
}