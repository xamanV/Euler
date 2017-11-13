#ifndef EULER_H
#define EULER_H

#include <QMainWindow>

namespace Ui {
class Euler;
}

class Euler : public QMainWindow
{
    Q_OBJECT

public:
    explicit Euler(QWidget *parent = 0);
    ~Euler();
    double Ls, Li, h;
    double x(double a);
    double y(double b);
    double r,p,q;

private:
    Ui::Euler *ui;
private slots:
    void procesar();
    void borrar();
};

#endif // EULER_H
