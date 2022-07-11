#pragma once


class Gunda : public Character
{
protected:
    RectangleShape gunda;
    Texture gundaTexture;

    float posDiffx;
    float posDiffy;
    Vector2f enemySpeed = Vector2f(-1.0f, 0.0f);
    pos enemypositions[5] = {
         {-400.0f,-600.0f},
        {-1500.0f,-800.0f},
        {433.0f,77.0f},
        {800.0f,544.0f},
        {211.0f,900.0f}
        
       
      
       
        
    };

public:
    Gunda();
    void updateEnemyPosition(Vector2f, Vector2f &,RectangleShape &);
    friend class Game;
};

Gunda ::Gunda() : gunda(Vector2f(100.0f, 100.0f))
{
    gunda.setPosition(Vector2f(100.0f, 100.0f));
    gundaTexture.loadFromFile(IMG_PATH "/enemy2Up.png");
    gunda.setTexture(&gundaTexture);
}

void Gunda ::updateEnemyPosition(Vector2f p, Vector2f &s,RectangleShape &e)
{
    posDiffx = e.getPosition().x - p.x;
    posDiffy = e.getPosition().y - p.y;
    // cout << " X Difference : " << posDiffx << endl;
    // cout << " Y Difference : " << posDiffy << endl;

    if (posDiffx >= 50)
    {
        s.x = -1.0f;
        s.y = 0.0f;
        gundaTexture.loadFromFile(IMG_PATH"/bigEnemyLeft.png");
        e.setTexture(&gundaTexture);
    }
    else if (posDiffx <= -50)
    {
        s.x = 1.0f;
        s.y = 0.0f;
        gundaTexture.loadFromFile(IMG_PATH"/bigEnemyRight.png");
        e.setTexture(&gundaTexture);
    }
    else
    {
        if (posDiffy >= 50)
        {
            s.x = 0.0f;
            s.y = -1.0f;
            gundaTexture.loadFromFile(IMG_PATH"/bigEnemy.png");
            e.setTexture(&gundaTexture);
        }
        else if (posDiffy <= -50)
        {
            s.x = 0.0f;
            s.y = 1.0f;
            gundaTexture.loadFromFile(IMG_PATH"/bigEnemyDown.png");
            e.setTexture(&gundaTexture);
        }
        else
        {
            s.x = 0.0f;
            s.y = 0.0f;
        }
    }
}

class Gundas
{
protected:
    vector<Gunda> gunda_group;
    int enemyspawnTimer = 0;
    int enemyShootTimer = 50;
    int enemySpawnNo;
    friend class Game;
    friend class Gunda;
};



