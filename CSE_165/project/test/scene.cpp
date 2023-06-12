#include "scene.h"
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
//#include <QDebug>
#include <QGraphicsTextItem>

// Constructor, initializes meber variables and sets up piller spawn timer
Scene::Scene(QObject *parent) : QGraphicsScene(parent),
    gameOn(false),score(0),
    bestScore(0)
{
    setUpPillarTimer();
}

// Creates and adds bird to scene
void Scene::addBird()
{
    bird = new BirdItem(QPixmap(":/images/left-4.png"));
    addItem(bird);
}

// Starts the game. Does nothing if game is alreading running
void Scene::startGame()
{
    //bird
    bird->startFlying();
    //pillars
    if(!pillarTimer->isActive())
    {
        cleanPillars();
        setGameOn(true);
        setScore(0);
        hideGameOverGraphics();
        pillarTimer->start(1000);
    }
}

// Sets up a timer that creates a new pillar at regular intervals, and connects to collideFail() to call if collision occurs
void Scene::setUpPillarTimer()
{
    pillarTimer = new QTimer(this);
    connect(pillarTimer,&QTimer::timeout,[=]()
            {
                PillarItem * pillarItem = new PillarItem();
                connect(pillarItem,&PillarItem::collideFail,[=]()
                        {
                            pillarTimer->stop();
                            freezeBirdAndPillarsInPlace();
                            setGameOn(false);
                            showGameOverGraphics();
                        });
                addItem(pillarItem);
            });
}

// Freezes the bird and all pillars currently in the scene
void Scene::freezeBirdAndPillarsInPlace()
{
    // freezing bird
    bird->freezeInPlace();

    //freezingpillars
    QList<QGraphicsItem *> sceneItems = items();
    foreach (QGraphicsItem *item, sceneItems)
    {
        PillarItem * pillar = dynamic_cast<PillarItem *>(item);
        if(pillar)
        {
            pillar->freezeInPlace();
        }
    }
}

// Sets the current score to the given value
void Scene::setScore(int value)
{
    score = value;
}

// Returns whether the game is currently running or not
bool Scene::getGameOn() const
{
    return gameOn;
}

// Sets the gameOn member variable to the given value
void Scene::setGameOn(bool value)
{
    gameOn = value;
}

// Increments the score by 1 and updates the best score if necessary
void Scene::incrementScore()
{
    score++;
    if(score > bestScore)
    {
        bestScore = score;
    }
}

// If the space bar is pressed and the game is running, the bird is instructed to jump.
void Scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        if(gameOn)
        {
            bird->shootUP();
        }
    }
    QGraphicsScene::keyPressEvent(event);
}

// If the left mouse button is pressed and the game is running, the bird is instructed to jump.
void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(gameOn)
        {
            bird->shootUP();
        }
    }
    QGraphicsScene::mousePressEvent(event);
}

// Displays a game over and the player's score. Called when the game ends due to a collision with a pillar.
void Scene::showGameOverGraphics()
{
    gameOverPix = new QGraphicsPixmapItem(QPixmap(":/images/gameOver.png"));
    addItem(gameOverPix);
    gameOverPix->setPos(QPointF(0,0) - QPointF(gameOverPix->boundingRect().width()/2,
                                                gameOverPix->boundingRect().height()/2));

    scoreTextItem = new QGraphicsTextItem;

    QString htmlString = "<p> Score : " + QString::number(score) + " </p>"
                         + "<p> Best Score : " + QString::number(bestScore) + "</p>";

    QFont mFont("Times New Roman", 30, QFont::Bold);

    scoreTextItem->setHtml(htmlString);
    scoreTextItem->setFont(mFont);
    scoreTextItem->setDefaultTextColor(Qt::black);
    addItem(scoreTextItem);

    scoreTextItem->setPos(QPointF(0,0) - QPointF(scoreTextItem->boundingRect().width()/2,
                                                  -gameOverPix->boundingRect().height()/2));
}

// Hides the game over and players score as they're playing
void Scene::hideGameOverGraphics()
{
    if(gameOverPix)
    {
        removeItem(gameOverPix);
        delete gameOverPix;
        gameOverPix = nullptr;
    }
    if(scoreTextItem)
    {
        removeItem(scoreTextItem);
        delete scoreTextItem;
        scoreTextItem = nullptr;
    }
}

// Removes all pillars from the scene
void Scene::cleanPillars()
{
    QList<QGraphicsItem *> sceneItems = items();
    foreach (QGraphicsItem *item, sceneItems)
    {
        PillarItem * pillar = dynamic_cast<PillarItem *>(item);
        if(pillar)
        {
            removeItem(pillar);
            delete pillar;
        }
    }
}
