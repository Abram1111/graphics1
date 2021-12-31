#ifndef DIALOG_H
#define DIALOG_H
#include "setter.h"
#include <QDialog>
#include<QtCore>
#include<QtGui>
#include<QGraphicsScene>
#include<QMessageBox>
#include<QGraphicsEllipseItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int clc ;


private slots:





    void on_pushButton_clicked();

    void on_btn_circle_clicked();


    void on_btn_cancel_clicked();

    void on_btn_line_clicked();

    void on_btn_rect_clicked();

    void on_btn_redo_clicked();

private:
    Ui::Dialog *ui;
    QGraphicsScene * scene ;
    QGraphicsEllipseItem * ellipse;
     QGraphicsRectItem * rect;
     QGraphicsLineItem * line;


};
#endif // DIALOG_H
