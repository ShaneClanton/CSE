#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include "pillaritem.h"
#include "birditem.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    // Constructor
    explicit Scene(QObject *parent = nullptr);

    // Adds a bird item to the scene
    void addBird();

    // Starts the game by resetting the score, showing the bird and starting the timer for the pillars
    void startGame();

    // Returns whether the game is currently on
    bool getGameOn() const;

    // Sets whether the game is currently on
    void setGameOn(bool value);

    // Increments the score by 1
    void incrementScore();

    // Sets the score to the given value
    void setScore(int value);

signals:

public slots:
    // QGraphicsScene interface
protected:
    // Handles key press events
    void keyPressEvent(QKeyEvent *event) override;

    // Handles mouse press events
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;


private:

    // Shows the game over graphics
    void showGameOverGraphics();

    // Hides the game over graphics
    void hideGameOverGraphics();

    // Cleans up the pillars in the scene
    void cleanPillars();

    // Sets up the timer for the pillars
    void setUpPillarTimer();

    // Freezes the bird and pillars in place
    void freezeBirdAndPillarsInPlace();

    // Member variables
    QTimer * pillarTimer;
    BirdItem * bird;
    bool gameOn;
    int score;
    int bestScore;

    QGraphicsPixmapItem * gameOverPix;
    QGraphicsTextItem  * scoreTextItem;
};

#endif // SCENE_H
