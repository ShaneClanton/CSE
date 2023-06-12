#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsPixmapItem>

// constructor creates the screense size and position with the backgorund image
widget::widget(QWidget *parent) : QMainWindow(parent), ui(new Ui::widget)
{
    ui->setupUi(this);

    scene = new Scene(this);
    scene->setSceneRect(-250, -300, 500, 600);

    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/images/bg001.png"));
    scene-> addItem(pixItem);
    pixItem->setPos(QPointF(0,0) - QPointF(pixItem->boundingRect().width()/2,
                                            pixItem->boundingRect().height()/2));

    ui->graphicsView->setScene(scene);

    scene->addBird();
}

// deletes the ui object
widget::~widget()
{
    delete ui;
}

// function calls startGame() to begin game when start game is clicked
void widget::on_startGameButton_clicked()
{
    scene->startGame();
}
