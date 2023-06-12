#include "birditem.h"
#include <QTimer>
#include <QGraphicsScene>

// Constructor
BirdItem::BirdItem(QPixmap pixmap) :
    wingPosition(WingPosition::Up),
    wingDirection(0)
{
    setPixmap(pixmap);

    QTimer * birdWingsTimer = new QTimer(this);
    connect(birdWingsTimer,&QTimer::timeout,[=](){
        updatePixmap();
    });

    birdWingsTimer->start(80);

    groundPosition = scenePos().y() + 290;

    yAnimation = new QPropertyAnimation(this, "y",this);
    yAnimation->setStartValue(scenePos().y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(1000);

    rotationAnimation = new QPropertyAnimation(this, "rotation", this);
}

// Getter for m_rotation member variable
qreal BirdItem::rotation() const
{
    return m_rotation;
}

// Getter function fothe m_y member variable
qreal BirdItem::y() const
{
    return m_y;
}

// when called stops all ongoing animations and creates a new one for the bird going up
void BirdItem::shootUP()
{
    yAnimation->stop();
    rotationAnimation->stop();

    qreal curPosY = y();

    yAnimation->setStartValue(curPosY);
    yAnimation->setEndValue(curPosY -  scene()->sceneRect().height()/8);
    yAnimation->setEasingCurve(QEasingCurve::OutQuad);
    yAnimation->setDuration(285);

    connect(yAnimation,&QPropertyAnimation::finished,[=](){
        fallToGroundIfNecessary();
    });

    yAnimation->start();

    rotateTo(-20, 200, QEasingCurve::OutCubic);
}

// Called to start birds default flying animation
void BirdItem::startFlying()
{
    yAnimation->start();
    rotateTo(90,1200,QEasingCurve::InQuad);
}

// Function to stop any ongling animations for birds position or rotation
void BirdItem::freezeInPlace()
{
    yAnimation->stop();
    rotationAnimation->stop();
}

// Setter function for m_rotation member variable, updates birds transformation matrix to rotate it around its center point
void BirdItem::setRotation(qreal rotation)
{
    m_rotation = rotation;

    QPointF c = boundingRect().center();

    QTransform t;
    t.translate(c.x(), c.y());
    t.rotate(rotation);
    t.translate(-c.x(), -c.y());
    setTransform(t);
}

// Setter function for m_y, moves bird to new Y position relateive to current one
void BirdItem::setY(qreal y)
{
    moveBy(0,y-m_y);
    m_y = y;
}

// Function that create/starts new animation to rotate bird to new angle over specified duration and easing curve
void BirdItem::rotateTo(const qreal &end, const int &duration, const QEasingCurve &curve)
{
    rotationAnimation->setStartValue(rotation());
    rotationAnimation->setEndValue(end);
    rotationAnimation->setEasingCurve(curve);
    rotationAnimation->setDuration(duration);
    rotationAnimation->start();
}

// Function to chekc if bird needs to fall back down to ground
void BirdItem::fallToGroundIfNecessary()
{
    if(y() < groundPosition)
    {
        rotationAnimation->stop();
        yAnimation->setStartValue(y());
        yAnimation->setEasingCurve(QEasingCurve::InQuad);
        yAnimation->setEndValue(groundPosition);
        yAnimation->setDuration(1200);
        yAnimation->start();
        rotateTo(90,1100,QEasingCurve::InCubic);

    }
}

// Function called by timer to update birds image cycling between 3 different images
void BirdItem::updatePixmap()
{
    if(wingPosition == WingPosition::Middle)
    {
        if(wingDirection)
        {
            //Up
            setPixmap(QPixmap(":/images/left-4.png"));
            wingPosition = WingPosition::Up;
            wingDirection = 0;
        }else{
            //down
            setPixmap(QPixmap(":/images/left-1.png"));
            wingPosition = WingPosition::Down;
            wingDirection = 1;
        }
    }else{
        setPixmap(QPixmap(":/images/left-3.png"));
        wingPosition = WingPosition::Middle;
    }
}
