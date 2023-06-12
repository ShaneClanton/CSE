#ifndef PILLARITEM_H
#define PILLARITEM_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class PillarItem :public QObject , public QGraphicsItemGroup
{
    Q_OBJECT
    // define a Qt property for x position
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
    // constructor
    explicit PillarItem();
    // destructor
    ~PillarItem();

    // get x position
    qreal x() const;

    // stop the animation of the pillars
    void freezeInPlace();

signals:
    // signal emitted when the bird collides with the pillars
    void collideFail();

public slots:
    // set x position
    void setX(qreal x);

private:
    // check if the bird collides with the pillars
    bool collidesWithBird();

    // QGraphicsPixmapItem representing the top pillar
    QGraphicsPixmapItem * topPillar;

    // QGraphicsPixmapItem representing the bottom pillar
    QGraphicsPixmapItem * bottomPillar;

    // animation object for moving the pillars horizontally
    QPropertyAnimation * xAnimation;

    // the y position of the gap between the pillars
    int yPos;

    // flag indicating whether the pillars have passed the bird or not
    bool pastBird;

    // internal variable for storing the x position
    qreal m_x;
};

#endif // PILLARITEM_H

