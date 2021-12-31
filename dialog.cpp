 #include "dialog.h"
#include "ui_dialog.h"
#include "Shape.h"
#include "setter.h"
#include "Circle.h"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
     ui->setupUi(this);

    ellipse = new QGraphicsEllipseItem  ;
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    // hide all lable and text input
    ui->lab_x_pos->hide();
    ui->lab_color->hide();
    ui->label_y_pos->hide();
    ui->lab_width->hide();
    ui->label_legth->hide();
    ui->lineEdit_x_pos->hide();
    ui->lineEdit_color->hide();
    ui->lineEdit_width->hide();
    ui->lineEdit_y_pos->hide();
    ui->lineEdit_length->hide();
    ui->lineEdit_radius->hide();
    ui->label_radius->hide();
    ui->pushButton->hide();
    ui->btn_cancel->hide();
    ui->label_name->hide();
    ui->lineEdit_name->hide();
    ui->lineEdit_y_pos_final->hide();
    ui->label_y_pos_final->hide();
    ui->lineEdit_x_pos_final->hide();
    ui->label_x_pos_final->hide();
    //
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_pushButton_clicked()
{
    // create two  bollen
    bool ok ;
    bool ook ;
    // take the input from the text box in a form of string
    QString x_pos =ui->lineEdit_x_pos->text();
    QString y_pos =ui->lineEdit_y_pos->text();
    // convert string to int
    int x_posint = x_pos.toInt(&ok);
    // check if the opration is done or not
    if (!ok){ //if not show error message
         QMessageBox::warning(this,"errooor","invaled x postion");
         return; // stop function
    }
    // convert string to int
    int y_posint = y_pos.toInt(&ook);
     // check if the opration is done or not
    if (!ook){//if not show error message
         QMessageBox::warning(this,"errooor","invaled y postion");
         return;// stop function
    }
    // take color from the text box
    QString color =   ui->lineEdit_color->text();
    // check if color is correct
    if(color!="red"&& color!="black" && color!="blue" && color!="green" && color!="pink" && color!="gray"){
        QMessageBox::warning(this,"errooor","color not matched");
        return;
    }
    // creat new pen and brush
    QPen blackpen (Qt::black);
    blackpen.setWidth(6);
    QBrush redbrush(Qt::red);
    // make color of the brush same as input
    redbrush.setColor(color);
    if (clc==1){// that mean the circle btn is pushed
        //take the radius  in form of string
       QString radius =ui->lineEdit_radius->text();
       // covert it to double
       double radiusint = radius.toDouble(&ok);
        // check if the opration is done or not
       if (!ok||radiusint<=0){ //if not or if it -  show error message
           QMessageBox::warning(this,"errooor","invaled radius");
           return;
       }
       // QMessageBox::question(this,"errooor", x_pos ,  QMessageBox::Yes |  QMessageBox:: No);
       // draw ellipse and add it to the scene
       ellipse = scene->addEllipse(x_posint,y_posint ,radiusint*2,radiusint*2,blackpen,redbrush);
       // make  ellipse movable
       ellipse->setFlag(QGraphicsItem::ItemIsMovable);
    }
    else if (clc==2){ // that mean the rect btn is pushed
        // same as befor
        QString length =ui->lineEdit_width->text();
        QString width = ui->lineEdit_length->text();
        double widthint = width .toDouble(&ok);
        if (!ok||widthint<=0){
             QMessageBox::warning(this,"errooor","invaled width");
             return;
        }
        double lengthint = length .toDouble(&ok);
        if (!ok||lengthint<=0){
             QMessageBox::warning(this,"errooor","invaled length");
             return;
        }
       rect = scene->addRect(x_posint,y_posint,lengthint,widthint,blackpen,redbrush);
        rect->setFlag(QGraphicsItem::ItemIsMovable);
     }
    else if (clc==3)
    { // that mean the line btn is pushed
         // same as befor
        QString x_posfinal =ui->lineEdit_x_pos_final->text();
        QString y_posfinal =ui->lineEdit_y_pos_final->text();
        int x_posfinalint = x_posfinal.toInt(&ok);
        if (!ok){
             QMessageBox::warning(this,"errooor","invaled final x postion");
             return;
        }
        int y_posfinalint = y_posfinal.toInt(&ok);
        if (!ok){
             QMessageBox::warning(this,"errooor"," invaledfinal y postion");
             return;
        }
        blackpen.setColor(color);
        line = scene->addLine(x_posint,y_posint,x_posfinalint,y_posfinalint,blackpen);
         line->setFlag(QGraphicsItem::ItemIsMovable);
     }
    // after all hide all lable and text box
     ui->lab_x_pos->hide();
     ui->lab_color->hide();
     ui->label_y_pos->hide();
     ui->lab_width->hide();
     ui->label_legth->hide();
     ui->lineEdit_x_pos->hide();
     ui->lineEdit_color->hide();
     ui->lineEdit_width->hide();
     ui->lineEdit_y_pos->hide();
     ui->lineEdit_length->hide();
     ui->pushButton->hide();
     ui->btn_cancel->hide();
     ui->label_name->hide();
     ui->lineEdit_name->hide();
     ui->lineEdit_y_pos_final->hide();
     ui->label_y_pos_final->hide();
     ui->lineEdit_x_pos_final->hide();
     ui->label_x_pos_final->hide();
     ui->label_radius->hide();
     ui->lineEdit_radius->hide();
     // empty text box from prev input
     ui->lineEdit_x_pos->setText(""); 
     ui->lineEdit_color->setText("");
     ui->lineEdit_width->setText("");
     ui->lineEdit_y_pos->setText("");
     ui->lineEdit_length->setText("");
     ui->lineEdit_name->setText("");
     ui->lineEdit_y_pos_final->setText("");
     ui->lineEdit_x_pos_final->setText("");
     ui->lineEdit_radius->setText("");
}
void Dialog::on_btn_circle_clicked()
{

    ui->lab_x_pos->show();
    ui->lab_color->show();
    ui->label_y_pos->show();
    ui->lineEdit_x_pos->show();
    ui->lineEdit_color->show();
    ui->lineEdit_y_pos->show();
    ui->pushButton->show();
    ui->btn_cancel->show();
    ui->label_name->show();
    ui->lineEdit_name->show();
    ui->lineEdit_radius->show();
    ui->label_radius->show();
     //empty text box from prev input
    ui->lineEdit_x_pos->setText("");
    ui->lineEdit_color->setText("");
    ui->lineEdit_y_pos->setText("");
    ui->lineEdit_name->setText("");
    ui->lineEdit_radius->setText("");
   // hide lable and text box we do not need it
    ui->lineEdit_length->hide();
    ui->label_legth->hide();
    ui->lineEdit_width->hide();
    ui->lab_width->hide();
    ui->lineEdit_y_pos_final->hide();
    ui->label_y_pos_final->hide();
    ui->lineEdit_x_pos_final->hide();
    ui->label_x_pos_final->hide();

                 clc = 1;
}
void Dialog::on_btn_cancel_clicked()
{
     // hide all
    ui->lab_x_pos->hide();
    ui->lab_color->hide();
    ui->label_y_pos->hide();
    ui->lab_width->hide();
    ui->label_legth->hide();
    ui->lineEdit_x_pos->hide();
    ui->lineEdit_x_pos->setText("");
    ui->lineEdit_color->hide();
    ui->lineEdit_color->setText("");
    ui->lineEdit_width->hide();
    ui->lineEdit_width->setText("");
    ui->lineEdit_y_pos->hide();
    ui->lineEdit_y_pos->setText("");
    ui->lineEdit_length->hide();
    ui->lineEdit_length->setText("");
    ui->lineEdit_name->hide();
    ui->lineEdit_name->setText("");
    ui->pushButton->hide();
    ui->btn_cancel->hide();
    ui->label_name->hide();
    ui->lineEdit_y_pos_final->hide();
    ui->lineEdit_y_pos_final->setText("");
    ui->label_y_pos_final->hide();
    ui->lineEdit_x_pos_final->hide();
    ui->lineEdit_x_pos_final->setText("");
    ui->label_x_pos_final->hide();
    ui->label_radius->hide();
    ui->lineEdit_radius->hide();
    ui->lineEdit_radius->setText("");
}
void Dialog::on_btn_line_clicked()
{
    ui->lab_x_pos->show();
    ui->lab_color->show();
    ui->label_y_pos->show();
    ui->lineEdit_x_pos->show();
    ui->lineEdit_color->show();
    ui->lineEdit_y_pos->show();
    ui->lineEdit_x_pos_final->show();
    ui->lineEdit_name->show();
    ui->lineEdit_y_pos_final->show();
    ui->pushButton->show();
    ui->btn_cancel->show();
    ui->label_name->show();
    ui->label_y_pos_final->show();
    ui->label_x_pos_final->show();

    ui->lineEdit_x_pos->setText("");
    ui->lineEdit_color->setText("");
    ui->lineEdit_y_pos->setText("");
    ui->lineEdit_x_pos_final->setText("");
    ui->lineEdit_name->setText("");
    ui->lineEdit_y_pos_final->setText("");


    ui->lineEdit_radius->hide();
    ui->label_radius->hide();
    ui->lineEdit_width->hide();
    ui->lab_width->hide();
    ui->lineEdit_length->hide();
    ui->label_legth->hide();
    clc = 3;
}
void Dialog::on_btn_rect_clicked()
{
    ui->lab_x_pos->show();
    ui->lab_color->show();
    ui->label_y_pos->show();
    ui->lab_width->show();
    ui->label_legth->show();
    ui->lineEdit_x_pos->show();
    ui->lineEdit_x_pos->setText("");
    ui->lineEdit_color->show();
    ui->lineEdit_color->setText("");
    ui->lineEdit_width->show();
     ui->lineEdit_width->setText("");
    ui->lineEdit_y_pos->show();
     ui->lineEdit_y_pos->setText("");
    ui->lineEdit_length->show();
     ui->lineEdit_length->setText("");
    ui->pushButton->show();
    ui->btn_cancel->show();
    ui->label_name->show();
    ui->lineEdit_name->show();
     ui->lineEdit_name->setText("");
    ui->lineEdit_radius->hide();
    ui->label_radius->hide();
    ui->lineEdit_y_pos_final->hide();
     ui->lineEdit_y_pos_final->setText("");
    ui->label_y_pos_final->hide();
    ui->lineEdit_x_pos_final->hide();
     ui->lineEdit_x_pos_final->setText("");
    ui->label_x_pos_final->hide();
    clc = 2;
}
void Dialog::on_btn_redo_clicked()
{

}

