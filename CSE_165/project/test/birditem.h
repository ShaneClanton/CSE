#ifndef BIRDITEM_H
#define BIRDITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class BirdItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)
    Q_PROPERTY(qreal y READ y WRITE setY)
public:

    // Class constructor to take a QPixmap object as an argument
    explicit BirdItem(QPixmap pixmap);

    // public methods used to get values of the rotation and y properties
    qreal rotation() const;
    qreal y() const;

    // Method used to make the bird move up
    void shootUP();

    // Method used to make the bird start flying
    void startFlying();

    // Method used to freeze the bird in place
    void freezeInPlace();

signals:

    // Public slots used to set the value of the rotation and y properties
public slots:
    void setRotation(qreal rotation);
    void setY(qreal y);

    // Slot used to rotate the bird to a specific angle
    void rotateTo(const qreal &end, const int& duration, const QEasingCurve& curve);

    // Slot used to maek the bird fall to ground if necessary
    void fallToGroundIfNecessary();

private:
    enum WingPosition{
        Up,
        Middle,
        Down
    };
    void updatePixmap();

    WingPosition wingPosition;
    bool wingDirection; // 0 : down, 1; UP
    qreal m_rotation;
    qreal m_y;
    QPropertyAnimation * yAnimation;
    QPropertyAnimation * rotationAnimation;
    qreal groundPosition;
};

#endif // BIRDITEM_H
