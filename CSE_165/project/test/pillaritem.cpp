#include "pillaritem.h"
#include <QRandomGenerator>
//#include <QDebug>
#include <QGraphicsScene>
#include "scene.h"
#include "birditem.h"

// Constructor of the class and sets the position of the pillars and initializes movements for the both on x-axis
PillarItem::PillarItem() :
    topPillar(new QGraphicsPixmapItem(QPixmap(":/images/pipe_down.png"))),
    bottomPillar(new QGraphicsPixmapItem(QPixmap(":/images/pipe_up.png"))),
    pastBird(false)
{
    topPillar->setPos(QPointF(0,0) - QPointF(topPillar->boundingRect().width()/2,
                                              topPillar->boundingRect().height() + 61));

    bottomPillar->setPos(QPointF(0,0) + QPointF(-bottomPillar->boundingRect().width()/2, 61));

    addToGroup(topPillar);
    addToGroup(bottomPillar);

    yPos = QRandomGenerator::global()->bounded(150);
    int xRandomizer = QRandomGenerator::global()->bounded(200);

    setPos(QPoint(0,0) + QPoint(260 + xRandomizer,yPos));

    xAnimation = new QPropertyAnimation(this,"x",this);
    xAnimation->setStartValue(260 + xRandomizer);
    xAnimation->setEndValue(-260);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(1500);

    connect(xAnimation, &QPropertyAnimation::finished,[=]()
            {
                scene()->removeItem(this);
                delete this;
            });

    xAnimation->start();
}

// Destructor for top and bottom pillars
PillarItem::~PillarItem()
{
    delete topPillar;
    delete bottomPillar;
}

// Getter for x position of pillars
qreal PillarItem::x() const
{
    return m_x;
}

// Stops x-axis animation of pillars
void PillarItem::freezeInPlace()
{
    xAnimation->stop();
}

// Setter for x position of pillars, updates pillar positon and checks for bird collision
void PillarItem::setX(qreal x)
{
    m_x = x;

    // if pillar is offscreen and birds isn't past yet, score of game is incremented
    if(x < 0 && !pastBird)
    {
        pastBird = true;
        QGraphicsScene * mScene = scene();
        Scene * myScene = dynamic_cast<Scene * >(mScene);
        if(myScene)
        {
            myScene->incrementScore();
        }
    }
    if(collidesWithBird())
    {
        emit collideFail();
    }
    setPos(QPointF(0,0) + QPointF(x,yPos));
}

// Checks if the pillar collides with bird item if so returns true
bool PillarItem::collidesWithBird()
{
    QList<QGraphicsItem*> collidingItems = topPillar->collidingItems();
    collidingItems.append(bottomPillar->collidingItems());

    foreach (QGraphicsItem * item, collidingItems)
    {
        BirdItem * birdItem = dynamic_cast<BirdItem*>(item);
        if(birdItem)
        {
            return true;
        }
    }
    return false;
}
