#include <qapplication.h>
#include <qpushbutton.h>
#include <qslider.h>
#include <qlcdnumber.h>

#include <qvbox.h>

class ConnectWidget : public QVBox{
   public:
      ConnectWidget( QWidget *parent=0, const char *name=0);
};

ConnectWidget::ConnectWidget( QWidget *parent, const char *name) : QVBox(parent,name){
   QPushButton *button = new QPushButton("Sair",this,"quit");

   connect(button, SIGNAL(clicked()), qApp, SLOT(quit()));

   QLCDNumber *lcd = new QLCDNumber(2,this,"lcd");
   QSlider *slider = new QSlider(Horizontal,this,"Slider");
   slider->setRange(0, 99);
   slider->setValue(0);
   slider->setPageStep(1);

   connect( slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)) );

   QPushButton *add = new QPushButton("Somar",this,"add");
   connect(add, SIGNAL(clicked()), slider, SLOT(addStep()));
   QPushButton *subtract = new QPushButton("Subtrair",this,"subtract");
   connect(subtract, SIGNAL(clicked()), slider, SLOT(subtractStep()));
} 

int main(int argc, char **argv)
{
   QApplication app(argc, argv);

   ConnectWidget w;
   app.setMainWidget(&w);
   w.show();
   
   return app.exec();
}
