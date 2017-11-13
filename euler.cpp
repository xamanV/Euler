#include "euler.h"
#include "ui_euler.h"
#include"math.h"
#include <cmath>

Euler::Euler(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Euler)
{
    ui->setupUi(this);
    connect(ui->Ejecutar,SIGNAL(clicked()),this,SLOT(procesar()));//Conneccions by pushbottons
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(cerrar()));
//Funcion declaret
}
double Euler::x(double a)
{
    return((-2*(pow(a, 3)))+(12*(pow(a, 2)))-(20*a)+8.5);
}
double Euler::y(double b)
{
    return(-(0.5*(pow(b, 4)))+(4*(pow(b, 3)))-(10*(pow(b, 2)))+(8.5*b)+1);
}
Euler::~Euler()
{
    delete ui;
}
void Euler::procesar()
{
    //Temporal variables
    QString a1,a2,a3,a4,a5;

    //Conections of de spinbox whith variables
    Ls=ui->X1->value();
    Li=ui->X2->value();
    h=ui->H->value();
    //The use variables for easylise the algoritm
    double i;
    i=(Ls-Li)/h;
    r=i;
    double px[r];
    double py[r];
    double pz[r];
    px[0]=Li,px[r]=Ls;
    py[0]=y(Li), pz[0]=y(Li);

    //Use the bucle for by can do the program
    for(p=1;p<=r;p++)
    {
    px[p]=px[p-1]+h;
    py[p]=(py[p-1])+(x(px[i-1]))*h;
    pz[i]=y(px[i]);

//Here declaret display results
    a1.append("\npy Calculo: ").append(a2.setNum(px[p])).append("\npy Real: ").append(a3.setNum(r[i])).append("\n\nIntervalo: ").append(a4.setNum(p)).append("\n\n");
    ui->Resultados->setText(a1);

    }
}

void Euler::borrar()
{
    ui->X1->setValue(0.0);
    ui->X2->setValue(0.0);
    ui->H->setValue(0.0);
    ui->Resultados->clear();
}
