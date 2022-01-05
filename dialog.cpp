 #include "dialog.h"
#include "ui_dialog.h"
#include "Shape.h"
#include <string>
#include <algorithm>
#include "Sortshape.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
     ui->setupUi(this);

    ellipse = new QGraphicsEllipseItem  ;
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    // hide all lable and text input
    ui->btn_do_search->hide();
    ui->btn_do_sort->hide();
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
    QString name = ui->lineEdit_name->text();

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
       Shape * clc = new Circle( name.toStdString() ,  color.toStdString() ,  radiusint ,  radiusint);
       shapes.push_back(clc);
     // cout<< clc->getperimeter2();
       // declare object of kind
       // Circle * circle1  = new Circle( name.toStdString() ,  color.toStdString() ,  radiusint ,  radiusint);
       // searchcircle.push_back(circle1);
       // QMessageBox::question(this,"errooor", x_pos ,  QMessageBox::Yes |  QMessageBox:: No);
       // draw ellipse and add it to the scene
       ellipse = scene->addEllipse(x_posint,y_posint ,radiusint*2,radiusint*2,blackpen,redbrush);
       // make  ellipse movable
       ellipse->setFlag(QGraphicsItem::ItemIsMovable);
    }
    else if (clc==2){ // that mean the rect btn is pushed
        // same as befor
       // circle1 = new Rectangl();
       // circle1->getlength();
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
        Shape * rec = new Rectangl( name.toStdString() ,  color.toStdString() ,  lengthint ,  widthint);
        shapes.push_back(rec);
        // Rectangl * rect1 = new Rectangl(name.toStdString() ,  color.toStdString() ,lengthint,widthint);
         //searchrect.push_back(rect1);
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
        Shape * line2 = new Line(name.toStdString() , color.toStdString(),x_posint,y_posint,x_posfinalint ,y_posfinalint);
        shapes.push_back(line2);
       // Line* line1= new Line(name.toStdString() , color.toStdString(),x_posint,y_posint,x_posfinalint ,y_posfinalint);
        //searchline.push_back(line1);
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
     ui->btn_do_search->hide();
     ui->btn_do_sort->hide();
}
void Dialog::on_btn_circle_clicked()
{
    ui->btn_do_search->hide();
    ui->btn_do_sort->hide();
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
    ui->btn_do_search->hide();
    ui->btn_do_sort->hide();
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
    ui->btn_do_search->hide();
    ui->btn_do_sort->hide();
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
    ui->btn_do_search->hide();
    ui->btn_do_sort->hide();
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


void Dialog::on_btn_search_clicked()
{
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
    ui->label_name->show();
    ui->lineEdit_name->show();
    ui->lineEdit_name->setText("");
    ui->lineEdit_y_pos_final->hide();
    ui->label_y_pos_final->hide();
    ui->lineEdit_x_pos_final->hide();
    ui->label_x_pos_final->hide();
    ui->btn_do_search->show();
    ui->btn_do_sort->hide();
}


void Dialog::on_btn_do_search_clicked()
{
     QString name = ui->lineEdit_name->text();
     ui->btn_do_search->hide();
      ui->lineEdit_name->setText("");
       ui->lineEdit_name->hide();
        ui->label_name->hide();




        for(int i =0 ; i<shapes.size();i++){
            if(name.toStdString()==shapes[i]->getName()){
              //  string rad = to_string(searchcircle[i]->getradius());
                string s =  "Name->" + shapes[i]->getName() +'\n' +"color->" +shapes[i]->getColor() +'\n' + "primeter->" +to_string(shapes[i]->getperimeter2()) ;
                QString ss = QString::fromStdString(s);
                QMessageBox::information(this,"data of shape ", ss);
              return;
            }
        }
         QMessageBox::information(this,"data of shape", "item not found");
}


void Dialog::on_btn_save_clicked()
{


}
void Dialog::on_btn_sort_clicked()
{

     Shape * min;
      vector<Shape *> v ;
      for (int i = 0 ;i < shapes.size();i++){
          v.push_back(shapes[i]);
      }
      for(int i = 0 ;i < v.size();i++){
          for (int j = i+1; j< v.size();j++){
              if (v[j]->getperimeter2()<v[i]->getperimeter2()){
                  min = v[i];
              v[i]=v[j];
              v[j]=min;}
          }
      }
      string s;
     for (int i =0; i <v.size(); i++){
       s  = s + "name    "+ v[i]->getName()+'\n'+"perimeter"+to_string(v[i]->getperimeter2()) +'\n' ;
     }
     QString ss = QString::fromStdString(s);
      QMessageBox::information(this,"shapes sorted", ss);
}

