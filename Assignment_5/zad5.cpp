#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

class LRDD {
    public:
        void display() {
            cout << "Low display driver" << endl;
        }
};

class HRDD {
    public:
        void display() {
            cout << "High display driver" << endl;
        }
};

class LRPD {
    public:
        void print() {
            cout << "Low print driver" << endl;
        }
};

class HRPD {
    public:
        void print() {
            cout << "High print driver" << endl;
        }
};

class DisplayDriver {
    public:
        virtual void wykonaj() {}
};

class PrinterDriver {
    public:
        virtual void wykonaj() {}
};

class LowResDispDrvr : public DisplayDriver {
    public:
        void wykonaj() override {
            display.display();
        }

    private:
        LRDD display;
};

class HighResDispDrvr : public DisplayDriver {
    public:
        void wykonaj() override {
            display.display();
        }

    private:
        HRDD display;
};

class LowResPrtDrvr : public PrinterDriver {
    public:
        void wykonaj() override {
            display.print();
        }

    private:
        LRPD display;
};

class HighResPrtDrvr : public PrinterDriver {
    public:
        void wykonaj() override {
            display.print();
        }

    private:
        HRPD display;
};

class ResFactory {
    public:
        virtual unique_ptr<DisplayDriver> getDispDrv() {
            return nullptr; 
        }
        virtual unique_ptr<PrinterDriver> getPrintDrv() {
            return nullptr;
        }
};

class LowResFactory : public ResFactory {
    public:
        unique_ptr<DisplayDriver> getDispDrv() {
            return unique_ptr<DisplayDriver>(new LowResDispDrvr);
        }

        unique_ptr<PrinterDriver> getPrintDrv() {
            return unique_ptr<PrinterDriver>(new LowResPrtDrvr);
        }
};

class HighResFactory : public ResFactory {
    public:
        unique_ptr<DisplayDriver> getDispDrv() {
            return unique_ptr<DisplayDriver>(new HighResDispDrvr);
        }

        unique_ptr<PrinterDriver> getPrintDrv() {
            return unique_ptr<PrinterDriver>(new HighResPrtDrvr);
        }
};

int main()
{
    unique_ptr<ResFactory> fabryka(new LowResFactory);
    unique_ptr<DisplayDriver> ddrv = fabryka->getDispDrv();
    unique_ptr<PrinterDriver> pdrv = fabryka->getPrintDrv();
    ddrv->wykonaj();
    pdrv->wykonaj();

    fabryka.reset(new HighResFactory);
    ddrv = fabryka->getDispDrv();
    pdrv = fabryka->getPrintDrv();
    ddrv->wykonaj();
    pdrv->wykonaj();
}