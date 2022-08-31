#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <SFML/Audio.hpp>
#include <fstream>
using namespace std;
using namespace sf;
class footpath {
protected:
    float xcord[4], ycord[4], timesx[4], timesy[4];
public:
    ConvexShape s;
    footpath()
    {
        s.setPointCount(4);
        s.setOutlineThickness(1);
        s.setOutlineColor(Color::White);
    }
    void setcolor(int in)
    {
        if (in == 0 || in == 3 || in == 6)
            s.setFillColor(Color::Black);
        else if (in == 1 || in == 4 || in == 7)
            s.setFillColor(Color::White);
        else
            s.setFillColor(Color::Red);
    }
    void incrementspeed(int sign)
    {

        timesx[0] = 0.20, timesy[0] = 0.12, timesx[1] = 0.20, timesy[1] = 0.12, timesx[2] = 0.23, timesy[2] = 0.12, timesx[3] = 0.23, timesy[3] = 0.12;
        for (int i = 1; i <= sign; i++)
        {
            timesx[0] += 0.038;
            timesy[0] += 0.031;
            timesx[1] += 0.053;
            timesy[1] += 0.043;
            timesx[2] += 0.05;
            timesy[2] += 0.038;
            timesx[3] += 0.035;
            timesy[3] += 0.027;
        }
    }
};
class rightfootpath :public footpath
{
public:
    void set()
    {
        s.setPosition(695, 412);
        xcord[0] = 0, ycord[0] = 0, xcord[1] = 12, ycord[1] = 10, xcord[2] = 15, ycord[2] = 10, ycord[3] = 0, xcord[3] = 2; //initial cords

    }

    void speed(int sign)
    {

        incrementspeed(sign);
        if (sign <= 0)
        {
            timesx[3] = 0.02;
            s.setPoint(0, Vector2f(xcord[0] -= 0.015, ycord[0]));
            s.setPoint(1, Vector2f(xcord[1] += timesx[1], ycord[1] += timesy[1]));
            s.setPoint(2, Vector2f(xcord[2] += timesx[2], ycord[2] += timesy[2]));
            s.setPoint(3, Vector2f(xcord[3] += timesx[3] - 0.028, ycord[3]));
        }
        else
        {
            s.setPoint(0, Vector2f(xcord[0] += timesx[0], ycord[0] += timesy[0]));//(x1,y1)
            s.setPoint(1, Vector2f(xcord[1] += timesx[1], ycord[1] += timesy[1]));//(x1+110,y2)
            s.setPoint(2, Vector2f(xcord[2] += timesx[2], ycord[2] += timesy[2]));//(x2+40,y2)
            s.setPoint(3, Vector2f(xcord[3] += timesx[3], ycord[3] += timesy[3]));//(x1+40,y1
        }

    }
};
class leftfootpath :public footpath
{
public:
    void set()
    {
        s.setPosition(600, 412);

        xcord[0] = -2, ycord[0] = 0, xcord[1] = -15, ycord[1] = 10, xcord[2] = -12, ycord[2] = 10, ycord[3] = 0, xcord[3] = 0; //initial cords

    }
    void speed(int sign)
    {
        incrementspeed(sign);
        if (sign <= 0)
        {
            timesx[0] = 0.02;
            s.setPoint(0, Vector2f(xcord[0], ycord[0]));//(x1,y1)
            s.setPoint(1, Vector2f(xcord[1] -= timesx[2], ycord[1] += timesy[2]));//(x1+110,y2)
            s.setPoint(2, Vector2f(xcord[2] -= timesx[1], ycord[2] += timesy[1]));//(x2+40,y2)
            s.setPoint(3, Vector2f(xcord[3] += 0.015, ycord[3]));//(x1+40,y1
        }
        else
        {
            s.setPoint(0, Vector2f(xcord[0] -= timesx[3], ycord[0] += timesy[3]));//(x1,y1)
            s.setPoint(1, Vector2f(xcord[1] -= timesx[2], ycord[1] += timesy[2]));//(x1+110,y2)
            s.setPoint(2, Vector2f(xcord[2] -= timesx[1], ycord[2] += timesy[1]));//(x2+40,y2)
            s.setPoint(3, Vector2f(xcord[3] -= timesx[0], ycord[3] += timesy[0]));//(x1+40,y1
        }
    }
};
class stripes
{
    float xcordinates[4], ycordinates[4];
public:
    ConvexShape sh;
    stripes()
    {
        sh.setPointCount(4);
        sh.setFillColor(Color::White);
    }
    void set()
    {
        sh.setPosition(650, 410);
        sh.setPoint(0, Vector2f(0, 0));
        sh.setPoint(1, Vector2f(0, +2));
        sh.setPoint(2, Vector2f(+1, +2));
        sh.setPoint(3, Vector2f(+1, 0));
        xcordinates[0] = 0, ycordinates[0] = 0, xcordinates[1] = 0, ycordinates[1] = 0.5, xcordinates[2] = 2, ycordinates[2] = 0.5, ycordinates[3] = 0, xcordinates[3] = 2;
    }
    void speed(int sign)
    {
        float timesx1 = 0.001, timesy1 = 0.01, timesx2 = 0.001, timesy2 = 0.012, timesx3 = 0.001, timesy3 = 0.012, timesx4 = 0.001, timesy4 = 0.01;
        for (int i = 1; i <= sign - 1; i++)
        {
            timesx1 += 0.001;
            timesy1 += 0.1;
            timesx2 += 0.001;
            timesy2 += 0.12;
            timesx3 += 0.004;
            timesy3 += 0.12;
            timesx4 += 0.004;
            timesy4 += 0.1;
        }
        if (sign <= 0)
        {
            sh.setPoint(0, Vector2f(xcordinates[0] - timesx1, ycordinates[0]));//(x1,y1)
            sh.setPoint(1, Vector2f(xcordinates[1] -= timesx2, ycordinates[1] += timesy2));//(x1+110,y2)
            sh.setPoint(2, Vector2f(xcordinates[2] += timesx3, ycordinates[2] += timesy3));//(x2+40,y2)
            sh.setPoint(3, Vector2f(xcordinates[3] += timesx4, ycordinates[3]));//(x1+40,y1
        }
        else
        {
            sh.setPoint(0, Vector2f(xcordinates[0] -= timesx1, ycordinates[0] += timesy1));//(x1,y1)
            sh.setPoint(1, Vector2f(xcordinates[1] -= timesx2, ycordinates[1] += timesy2));//(x1+110,y2)
            sh.setPoint(2, Vector2f(xcordinates[2] += timesx3, ycordinates[2] += timesy3));//(x2+40,y2)
            sh.setPoint(3, Vector2f(xcordinates[3] += timesx4, ycordinates[3] += timesy4));//(x1+40,y1
        }
    }
};
class trees
{
protected:
    float xcordinates[4], ycordinates[4], timesx[4], timesy[4];
public:
    ConvexShape sh;
    trees()
    {
        sh.setPointCount(4);

    }
    void settexture(Texture* tx)
    {
        sh.setTexture(tx);
    }
    void incrementspeed(int sign)
    {
        timesx[0] = 0.0005, timesx[1] = 0.0005, timesx[2] = 0.001, timesx[3] = 0.001, timesy[0] = 0.002, timesy[1] = 0.0012, timesy[2] = 0.0012, timesy[3] = 0.002;
        for (int i = 0; i <= sign; i++)
        {
            timesx[0] += 0.14;
            timesy[0] += 0.01;
            timesx[1] += 0.14;
            timesy[1] += 0.1;
            timesx[2] += 0.24;
            timesy[2] += 0.1;
            timesx[3] += 0.24;
            timesy[3] += 0.01;
        }
    }
};
class righttrees :public trees
{
public:
    void set()
    {
        xcordinates[0] = 0, xcordinates[1] = 0, xcordinates[2] = 5, xcordinates[3] = 5;
        ycordinates[0] = 0, ycordinates[1] = 5, ycordinates[2] = 5, ycordinates[3] = 0;
        sh.setPosition(689, 402);
    }
    void speed(int sign)
    {
        incrementspeed(sign);
        sh.setPoint(0, Vector2f(xcordinates[0] += timesx[0], ycordinates[0] += timesy[0]));
        sh.setPoint(1, Vector2f(xcordinates[1] += timesx[1], ycordinates[1] += timesy[1]));
        sh.setPoint(2, Vector2f(xcordinates[2] += timesx[2], ycordinates[2] += timesy[2]));
        sh.setPoint(3, Vector2f(xcordinates[3] += timesx[3], ycordinates[3] += timesy[3]));
    }
};
class lefttrees : public trees
{
public:
    void set()
    {
        xcordinates[0] = -5, xcordinates[1] = -5, xcordinates[2] = 0, xcordinates[3] = 0;
        ycordinates[0] = 0, ycordinates[1] = 5, ycordinates[2] = 5, ycordinates[3] = 0;
        sh.setPosition(604, 402);
    }
    void speed(int sign)
    {
        incrementspeed(sign);
        sh.setPoint(0, Vector2f(xcordinates[0] -= timesx[3], ycordinates[0] += timesy[3]));
        sh.setPoint(1, Vector2f(xcordinates[1] -= timesx[2], ycordinates[1] += timesy[2]));
        sh.setPoint(2, Vector2f(xcordinates[2] -= timesx[1], ycordinates[2] += timesy[1]));
        sh.setPoint(3, Vector2f(xcordinates[3] -= timesx[0], ycordinates[3] += timesy[0]));
    }
};
class obstacle
{
protected:
    float xcordinates[4], ycordinates[4], timesx[4], timesy[4];
public:
    ConvexShape sh;
    obstacle()
    {
        sh.setPointCount(4);

    }
    void settexture(Texture* tx)
    {
        sh.setTexture(tx);
    }
    void incrementspeed(int sign)
    {

        for (int i = 0; i <= sign - 1; i++)
        {
            timesy[0] += 0.045;
            timesy[1] += 0.05;
            timesy[2] += 0.05;
            timesy[3] += 0.045;
            timesx[0] += 0.01;
            timesx[1] += 0.01;
            timesx[2] += 0.02;
            timesx[3] += 0.02;

        }
    }

};
class rightcoin :public obstacle
{
public:
    void set()
    {
        xcordinates[0] = 0, xcordinates[1] = 0, xcordinates[2] = 0.1, xcordinates[3] = 0.1;
        ycordinates[0] = 0, ycordinates[1] = 0.2, ycordinates[2] = 0.2, ycordinates[3] = 0;
        sh.setPosition(670, 405);
    }
    void speed(int sign)
    {
        timesx[0] = 0.05, timesx[1] = 0.05, timesx[2] = 0.09, timesx[3] = 0.09, timesy[0] = 0.03, timesy[1] = 0.06, timesy[2] = 0.06, timesy[3] = 0.03;
        incrementspeed(sign);
        sh.setPoint(0, Vector2f(xcordinates[0] += timesx[0], ycordinates[0] += timesy[0]));
        sh.setPoint(1, Vector2f(xcordinates[1] += timesx[1], ycordinates[1] += timesy[1]));
        sh.setPoint(2, Vector2f(xcordinates[2] += timesx[2], ycordinates[2] += timesy[2]));
        sh.setPoint(3, Vector2f(xcordinates[3] += timesx[3], ycordinates[3] += timesy[3]));
    }
};
class leftcoin :public obstacle
{
public:
    void set()
    {
        xcordinates[0] = -0.1, xcordinates[1] = -0.1, xcordinates[2] = 0, xcordinates[3] = 0;
        ycordinates[0] = 0, ycordinates[1] = 0.2, ycordinates[2] = 0.2, ycordinates[3] = 0;
        sh.setPosition(640, 400);
    }
    void speed(int sign)
    {
        timesx[0] = 0.05, timesx[1] = 0.05, timesx[2] = 0.09, timesx[3] = 0.09, timesy[0] = 0.03, timesy[1] = 0.06, timesy[2] = 0.06, timesy[3] = 0.03;
        incrementspeed(sign);
        sh.setPoint(0, Vector2f(xcordinates[0] -= timesx[3], ycordinates[0] += timesy[3]));
        sh.setPoint(1, Vector2f(xcordinates[1] -= timesx[2], ycordinates[1] += timesy[2]));
        sh.setPoint(2, Vector2f(xcordinates[2] -= timesx[1], ycordinates[2] += timesy[1]));
        sh.setPoint(3, Vector2f(xcordinates[3] -= timesx[0], ycordinates[3] += timesy[0]));
    }
};
class rightcone :public obstacle
{
public:
    void set()
    {
        xcordinates[0] = 0, xcordinates[1] = 0, xcordinates[2] = 1, xcordinates[3] = 1;
        ycordinates[0] = 0, ycordinates[1] = 2, ycordinates[2] = 2, ycordinates[3] = 0;
        sh.setPosition(660, 400);
    }
    void speed(int sign)
    {
        timesx[0] = 0.05, timesx[1] = 0.05, timesx[2] = 0.09, timesx[3] = 0.09, timesy[0] = 0.03, timesy[1] = 0.06, timesy[2] = 0.06, timesy[3] = 0.03;
        incrementspeed(sign);
        sh.setPoint(0, Vector2f(xcordinates[0] += timesx[0], ycordinates[0] += timesy[0]));
        sh.setPoint(1, Vector2f(xcordinates[1] += timesx[1], ycordinates[1] += timesy[1]));
        sh.setPoint(2, Vector2f(xcordinates[2] += timesx[2], ycordinates[2] += timesy[2]));
        sh.setPoint(3, Vector2f(xcordinates[3] += timesx[3], ycordinates[3] += timesy[3]));
    }
};
class leftcone :public obstacle
{
public:
    void set()
    {
        xcordinates[0] = -1, xcordinates[1] = -1, xcordinates[2] = 0, xcordinates[3] = 0;
        ycordinates[0] = 0, ycordinates[1] = 2, ycordinates[2] = 2, ycordinates[3] = 0;
        sh.setPosition(640, 400);
    }
    void speed(int sign)
    {
        timesx[0] = 0.05, timesx[1] = 0.05, timesx[2] = 0.09, timesx[3] = 0.09, timesy[0] = 0.03, timesy[1] = 0.06, timesy[2] = 0.06, timesy[3] = 0.03;
        incrementspeed(sign);
        sh.setPoint(0, Vector2f(xcordinates[0] -= timesx[3], ycordinates[0] += timesy[3]));
        sh.setPoint(1, Vector2f(xcordinates[1] -= timesx[2], ycordinates[1] += timesy[2]));
        sh.setPoint(2, Vector2f(xcordinates[2] -= timesx[1], ycordinates[2] += timesy[1]));
        sh.setPoint(3, Vector2f(xcordinates[3] -= timesx[0], ycordinates[3] += timesy[0]));
    }
};
class rightbarrier :public obstacle
{
public:
    void set()
    {
        xcordinates[0] = 0, xcordinates[1] = 0, xcordinates[2] = 1, xcordinates[3] = 1;
        ycordinates[0] = 0, ycordinates[1] = 2, ycordinates[2] = 2, ycordinates[3] = 0;
        sh.setPosition(660, 400);
    }
    void speed(int sign)
    {
        timesx[0] = 0.05, timesx[1] = 0.05, timesx[2] = 0.09, timesx[3] = 0.09, timesy[0] = 0.03, timesy[1] = 0.06, timesy[2] = 0.06, timesy[3] = 0.03;
        incrementspeed(sign);
        sh.setPoint(0, Vector2f(xcordinates[0] += timesx[0], ycordinates[0] += timesy[0]));
        sh.setPoint(1, Vector2f(xcordinates[1] += timesx[1], ycordinates[1] += timesy[1]));
        sh.setPoint(2, Vector2f(xcordinates[2] += timesx[2], ycordinates[2] += timesy[2]));
        sh.setPoint(3, Vector2f(xcordinates[3] += timesx[3], ycordinates[3] += timesy[3]));
    }
};
class leftbarrier :public obstacle
{
public:
    void set()
    {
        xcordinates[0] = -1, xcordinates[1] = -1, xcordinates[2] = 0, xcordinates[3] = 0;
        ycordinates[0] = 0, ycordinates[1] = 2, ycordinates[2] = 2, ycordinates[3] = 0;
        sh.setPosition(640, 400);
    }
    void speed(int sign)
    {
        timesx[0] = 0.05, timesx[1] = 0.05, timesx[2] = 0.09, timesx[3] = 0.09, timesy[0] = 0.03, timesy[1] = 0.06, timesy[2] = 0.06, timesy[3] = 0.03;
        incrementspeed(sign);
        sh.setPoint(0, Vector2f(xcordinates[0] -= timesx[3], ycordinates[0] += timesy[3]));
        sh.setPoint(1, Vector2f(xcordinates[1] -= timesx[2], ycordinates[1] += timesy[2]));
        sh.setPoint(2, Vector2f(xcordinates[2] -= timesx[1], ycordinates[2] += timesy[1]));
        sh.setPoint(3, Vector2f(xcordinates[3] -= timesx[0], ycordinates[3] += timesy[0]));
    }
};
class info
{
    char name_info[16], pass_info[16], email_info[16];
    int coins, high_score, characters_bought[2], last_character[3];
public:
    int get()
    {
        for (int i = 0; i < 3; i++)
        {
            if (last_character[i] == 1)
            {
                return i;
            }
        }
    }
    info()
    {
        coins = 0;
        characters_bought[0] = 0;
        characters_bought[1] = 0;
        last_character[0] = 1;
        last_character[1] = 0;
        last_character[2] = 0;
        high_score = 0;
    }
    char* getname()
    {
        return name_info;
    }
    char* getpassword()
    {
        return pass_info;
    }
    char* getemail()
    {
        return email_info;
    }
    int getcoins()
    {
        return coins;
    }
    int getscore()
    {
        return high_score;
    }
    int getcharacterbought1()
    {
        return characters_bought[0];
    }
    int getcharacterbought2()
    {
        return characters_bought[1];
    }
    int getlastcharater1()
    {
        return last_character[0];
    }
    int getlastcharater2()
    {
        return last_character[1];
    }
    int getlastcharater3()
    {
        return last_character[2];
    }
    void setname(char* name_info)
    {
        strcpy_s(this->name_info, name_info);
    }
    void setpassword(char* pass_info)
    {
        strcpy_s(this->pass_info, pass_info);
    }
    void setemail(char* email_info)
    {
        strcpy_s(this->email_info, email_info);
    }
    void setcoins(int coin)
    {
        coins = coin;
    }
    void setbought1(int characterboughtt)
    {
        characters_bought[0] = characterboughtt;
    }
    void setbought2(int characterboughtt)
    {
        characters_bought[1] = characterboughtt;
    }
    void setlastcharacter1(int lastcharacter)
    {
        last_character[0] = lastcharacter;
    }
    void setlastcharacter2(int lastcharacter)
    {
        last_character[1] = lastcharacter;
    }
    void setlastcharacter3(int lastcharacter)
    {
        last_character[2] = lastcharacter;
    }
    void setscore(int score)
    {
        this->high_score = score;
    }
};
class Grass
{
    float xcordinates[4], ycordinates[4];
public:
    ConvexShape sh;
    void setcolor(int i)
    {

        sh.setPointCount(4);
        if (i % 2 == 0)
            sh.setFillColor(Color::Green);
        else
            sh.setFillColor(Color(0, 128, 0));
    }
    void set()
    {
        sh.setPosition(0, 410);
        sh.setPoint(0, Vector2f(0, 0));
        sh.setPoint(1, Vector2f(0, +1));
        sh.setPoint(2, Vector2f(+1400, +1));
        sh.setPoint(3, Vector2f(+1400, 0));
        xcordinates[0] = 0, ycordinates[0] = 0, xcordinates[1] = 0, ycordinates[1] = 2, xcordinates[2] = 1400, ycordinates[2] = 2, ycordinates[3] = 0, xcordinates[3] = 1400;
    }
    void speed(int sign)
    {

        float  timesy1 = 0.01, timesy2 = 0.027, timesy3 = 0.027, timesy4 = 0.01;
        for (int i = 1; i <= sign; i++)
        {
            timesy1 += 0.03;
            timesy2 += 0.04;
            timesy3 += 0.04;
            timesy4 += 0.03;
        }
        if (sign <= 0)
        {
            sh.setPoint(0, Vector2f(xcordinates[0], ycordinates[0]));//(x1,y1)
            sh.setPoint(1, Vector2f(xcordinates[1], ycordinates[1] += timesy2));//(x1+110,y2)
            sh.setPoint(2, Vector2f(xcordinates[2], ycordinates[2] += timesy3));//(x2+40,y2)
            sh.setPoint(3, Vector2f(xcordinates[3], ycordinates[3]));//(x1+40,y1
        }
        else
        {
            sh.setPoint(0, Vector2f(xcordinates[0], ycordinates[0] += timesy1));//(x1,y1)
            sh.setPoint(1, Vector2f(xcordinates[1], ycordinates[1] += timesy2));//(x1+110,y2)
            sh.setPoint(2, Vector2f(xcordinates[2], ycordinates[2] += timesy3));//(x2+40,y2)
            sh.setPoint(3, Vector2f(xcordinates[3], ycordinates[3] += timesy4));//(x1+40,y1
        }


    }

};
class shop
{
    RenderWindow* w;
    RectangleShape rec, rec1, rec2, rec3, rec4, rec5;
    Texture tex, tex1, tex2, tex3, tex4, tex5;
    int transition, i, bought[2], select[3], symbol[3], sign;
    Font ff;
    string str;
    Text text;
    Sound sound, sound1, sound2;
    SoundBuffer buffer, buffer1, buffer2;
    info* in;

public:
    shop(RenderWindow* ww)
    {
        w = ww;
        // this->in = inn;
        i = 0, sign = 1;
        ff.loadFromFile("dub.ttf");
        text.setFont(ff);
        str = "00000000";
        //  cointostr();
        text.setString(str);
        text.setPosition(Vector2f(1190, 50));
        text.setFillColor(Color::White);
        text.setCharacterSize(46);
        rec.setSize(Vector2f(100, 100));
        rec.setPosition(Vector2f(1200, 325));
        rec.setFillColor(Color::Blue);
        tex.loadFromFile("Spikebackground.png");
        tex1.loadFromFile("front.png");
        tex2.loadFromFile("back.png");
        tex3.loadFromFile("selectedo.png");
        tex4.loadFromFile("Bought.png");
        tex5.loadFromFile("m.png");
        rec1.setTexture(&tex);
        rec1.setPosition(Vector2f(0, 0));
        rec1.setSize(Vector2f(1400, 700));
        rec.setTexture(&tex1);
        rec.setFillColor(Color::White);
        rec2.setTexture(&tex2);
        rec2.setPosition(50, 325);
        rec2.setSize(Vector2f(200, 100));
        rec3.setTexture(&tex3);
        rec3.setPosition(530, 370);
        rec3.setSize(Vector2f(300, 120));
        rec4.setTexture(&tex4);
        rec4.setPosition(530, 530);
        rec4.setSize(Vector2f(300, 120));
        rec5.setTexture(&tex5);
        rec5.setPosition(40, 40);
        rec5.setSize(Vector2f(150, 100));
        transition = 0;
        bought[0] = 0, bought[1] = 0; select[0] = 1, select[1] = 0, select[2] = 0;
        buffer.loadFromFile("buying.wav");
        buffer1.loadFromFile("sellect1.wav");
        buffer2.loadFromFile("cantdoit.wav");
        sound.setBuffer(buffer);
        sound1.setBuffer(buffer1);
        sound2.setBuffer(buffer2);
        sound.setVolume(100);
        sound1.setVolume(100);
    }
    void setinfo(info* inn)
    {
        in = inn;
    }
    string getstr()
    {
        return str;
    }
    int purchase()
    {
        int sign = 0;
        if (str[0] >= '1' || str[1] >= '1' || str[2] >= '1' || str[3] >= '2')
            sign = 1;
        else
        {
            if (str[3] >= '1' && str[4] >= '5')
                sign = 1;
        }
        return sign;
    }
    void settinginfo()
    {
        bought[0] = in->getcharacterbought1();
        bought[1] = in->getcharacterbought2();
        select[0] = in->getlastcharater1();
        select[1] = in->getlastcharater2();
        select[2] = in->getlastcharater3();

        if (select[0] == 0)
            tex3.loadFromFile("selecto.png");
        int ii = 7;
        int c = in->getcoins();
        while (ii != -1)
        {
            str[ii] = (c % 10) + 48;
            c /= 10;
            ii--;
        }
        text.setString(str);
    }
    void successfulpurchase()
    {

        int num = 0;
        num = in->getcoins();
        num -= 15000;
        in->setcoins(num);
        int i = 7;
        while (i != -1)
        {
            str[i] = (num % 10) + 48;
            num /= 10;
            i--;
        }

        text.setString(str);
        sound.play();
    }
    void Display()
    {
        sign = 1;
        int num = in->getcoins();
        int i = 7;
        while (i != -1)
        {
            str[i] = (num % 10) + 48;
            num /= 10;
            i--;
        }
        text.setString(str);
        Vector2i v1 = Mouse::getPosition(*w);
        if ((v1.x >= 40 && v1.x <= 190) && (v1.y >= 40 && v1.y <= 140))
        {
            rec5.setPosition(30, 30);
            rec5.setSize(Vector2f(170, 120));

        }
        else
        {
            rec5.setPosition(40, 40);
            rec5.setSize(Vector2f(150, 100));
        }
        if (select[0] == 1 || select[1] == 1 || select[2] == 1)
        {
            tex5.loadFromFile("m.png");
            rec5.setTexture(&tex5);
        }
        else
        {
            tex5.loadFromFile("cantmenu.png");
            rec5.setTexture(&tex5);
        }
        if (transition == 0 || transition == 1)
        {
            if ((v1.x >= 1200 && v1.x <= 1300) && (v1.y >= 325 && v1.y <= 425))
            {
                rec.setPosition(Vector2f(1190, 315));
                rec.setSize(Vector2f(120, 120));
            }
            else
            {
                rec.setPosition(Vector2f(1200, 325));
                rec.setSize(Vector2f(100, 100));
            }
        }
        if ((v1.x >= 530 && v1.x <= 830) && (v1.y >= 370 && v1.y <= 490))
        {
            rec3.setPosition(520, 360);
            rec3.setSize(Vector2f(320, 140));
        }
        else
        {
            rec3.setPosition(530, 370);
            rec3.setSize(Vector2f(300, 120));
        }
        if ((v1.x >= 530 && v1.x <= 830) && (v1.y >= 530 && v1.y <= 650))
        {
            rec4.setPosition(520, 520);
            rec4.setSize(Vector2f(320, 140));
        }
        else
        {
            rec4.setPosition(530, 530);
            rec4.setSize(Vector2f(300, 120));
        }
        if (transition == 1 || transition == 2)
        {
            if ((v1.x >= 50 && v1.x <= 150) && (v1.y >= 325 && v1.y <= 425))
            {
                rec2.setPosition(40, 315);
                rec2.setSize(Vector2f(120, 120));
            }
            else
            {
                rec2.setPosition(50, 325);
                rec2.setSize(Vector2f(100, 100));
            }
        }
    }
    int Transition()
    {
        Vector2i v1 = Mouse::getPosition(*w);
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if ((v1.x >= 40 && v1.x <= 190) && (v1.y >= 40 && v1.y <= 140))
            {
                if (select[0] == 1 || select[1] == 1 || select[2] == 1)
                {

                    in->setbought1(bought[0]);
                    in->setbought2(bought[1]);
                    in->setlastcharacter1(select[0]);
                    in->setlastcharacter2(select[1]);
                    in->setlastcharacter3(select[2]);
                    sound1.play();
                    sign = 0;
                }
                else
                {
                    sound2.play();
                    //sign= 1;
                }
            }
            if ((v1.x >= 1200 && v1.x <= 1300) && (v1.y >= 325 && v1.y <= 425))
            {
                if (transition == 0)
                {
                    sound1.play();
                    tex.loadFromFile("Arthur.png");
                    if (select[1] == 1)
                        tex3.loadFromFile("selectedo.png");
                    else
                        tex3.loadFromFile("selecto.png");
                    if (bought[0] == 1)
                        tex4.loadFromFile("Bought.png");
                    else
                    {
                        if (purchase())
                            tex4.loadFromFile("buy.png");
                        else
                            tex4.loadFromFile("cant.png");
                    }
                    transition++;
                }
                else if (transition == 1)
                {
                    sound1.play();
                    tex.loadFromFile("Ninja.png");
                    if (select[2] == 1)
                        tex3.loadFromFile("selectedo.png");
                    else
                        tex3.loadFromFile("selecto.png");
                    if (bought[1] == 1)
                        tex4.loadFromFile("Bought.png");
                    else
                    {
                        if (purchase())
                            tex4.loadFromFile("buy.png");
                        else
                            tex4.loadFromFile("cant.png");
                    }
                    transition++;
                }
            }

            if ((v1.x >= 50 && v1.x <= 150) && (v1.y >= 325 && v1.y <= 425))
            {
                if (transition == 1)
                {
                    sound1.play();
                    tex.loadFromFile("Spikebackground.png");
                    if (select[0] == 1)
                        tex3.loadFromFile("selectedo.png");
                    else
                        tex3.loadFromFile("selecto.png");
                    tex4.loadFromFile("Bought.png");
                    transition--;
                }
                else if (transition == 2)
                {
                    sound1.play();
                    tex.loadFromFile("Arthur.png");
                    if (select[1] == 1)
                        tex3.loadFromFile("selectedo.png");
                    else
                        tex3.loadFromFile("selecto.png");
                    if (bought[0] == 1)
                        tex4.loadFromFile("Bought.png");
                    else
                    {
                        if (purchase())
                            tex4.loadFromFile("buy.png");
                        else
                            tex4.loadFromFile("cant.png");
                    }
                    transition--;
                }

            }
            else if ((v1.x >= 530 && v1.x <= 830) && (v1.y >= 370 && v1.y <= 490))
            {
                if (transition == 0)
                {
                    sound1.play();
                    if (select[0] == 0)
                    {
                        tex3.loadFromFile("Selectedo.png");
                        select[0] = 1;
                        select[2] = 0;
                        select[1] = 0;
                    }
                    rec3.setTexture(&tex3);
                }
                if (transition == 1)
                {

                    if (bought[0] == 1)
                    {
                        sound1.play();
                        if (select[1] == 0)
                        {
                            tex3.loadFromFile("Selectedo.png");
                            select[1] = 1;
                            select[0] = 0;
                            select[2] = 0;
                        }
                    }
                    else
                        sound2.play();
                    rec3.setTexture(&tex3);
                }
                if (transition == 2)
                {

                    if (bought[1] == 1)
                    {
                        sound1.play();
                        if (select[2] == 0)
                        {
                            tex3.loadFromFile("Selectedo.png");
                            select[2] = 1;
                            select[0] = 0;
                            select[1] = 0;
                        }
                    }
                    else
                        sound2.play();
                    rec3.setTexture(&tex3);
                }
            }
            else if ((v1.x >= 530 && v1.x <= 830) && (v1.y >= 530 && v1.y <= 650))
            {
                //sound1.play();
                int saiyan = 0;
                if (str[0] >= '1' || str[1] >= '1' || str[2] >= '1' || str[3] >= '2')
                    saiyan = 1;
                else
                {
                    if (str[3] >= '1' && str[4] >= '5')
                        saiyan = 1;
                }
                if (saiyan == 1)
                {
                    if (transition == 1)
                    {
                        if (bought[0] == 0)
                        {
                            bought[0] = 1;
                            tex4.loadFromFile("Bought.png");
                            successfulpurchase();
                        }
                    }

                    else if (transition == 2)
                    {
                        if (bought[1] == 0)
                        {
                            int num;
                            bought[1] = 1;
                            tex4.loadFromFile("Bought.png");
                            successfulpurchase();
                        }
                    }
                    rec4.setTexture(&tex4);
                }
                else
                    sound2.play();
            }

        }
        else if (Mouse::isButtonPressed(Mouse::Right))
        {
            if ((v1.x >= 530 && v1.x <= 830) && (v1.y >= 370 && v1.y <= 490))
            {
                if (transition == 0)
                {
                    sound1.play();
                    if (select[0] == 1)
                    {
                        tex3.loadFromFile("selecto.png");
                        select[0] = 0;
                        select[2] = 0;
                        select[1] = 0;
                    }
                    rec3.setTexture(&tex3);
                }
                if (transition == 1)
                {

                    if (bought[0] == 1)
                    {
                        sound1.play();
                        if (select[1] == 1)
                        {
                            tex3.loadFromFile("selecto.png");
                            select[1] = 0;
                            select[0] = 0;
                            select[2] = 0;
                        }
                    }
                    else
                        sound2.play();
                    rec3.setTexture(&tex3);
                }
                if (transition == 2)
                {

                    if (bought[1] == 1)
                    {
                        sound1.play();
                        if (select[2] == 1)
                        {
                            tex3.loadFromFile("selecto.png");
                            select[0] = 0;
                            select[2] = 0;
                            select[1] = 0;
                        }
                    }
                    else
                        sound2.play();
                    rec3.setTexture(&tex3);
                }
            }
        }
        return sign;
    }
    void damdam()
    {
        w->clear();
        w->draw(rec1);
        if (transition == 0 || transition == 1)
            w->draw(rec);
        if (transition == 1 || transition == 2)
            w->draw(rec2);
        w->draw(rec3);
        w->draw(rec4);
        w->draw(rec5);
        w->draw(text);
        w->display();
    }
};
class Mouvment
{
public:
    Mouvment() {};

    void goDirection(const int& dir, sf::Sprite& spritesheet)
    {
        switch (dir) {


        case 0:
            spritesheet.move(sf::Vector2f(420, 0));
            break;
        case 1:
            spritesheet.move(sf::Vector2f(-420, 0));
        case 2:
            spritesheet.move(sf::Vector2f(0, -4));
        case 3:
            spritesheet.move(sf::Vector2f(0, 2));

        }
    }
};
template<class T>int fun_for_returning_integer_value(T str_int, int size)
{
    int i = 0, returning_value = 0;
    for (i = 0; i < size; i++)
    {
        if (str_int[i] == '0') returning_value = (returning_value * 10) + 0;
        if (str_int[i] == '1') returning_value = (returning_value * 10) + 1;;
        if (str_int[i] == '2') returning_value = (returning_value * 10) + 2;;
        if (str_int[i] == '3') returning_value = (returning_value * 10) + 3;;
        if (str_int[i] == '4') returning_value = (returning_value * 10) + 4;;
        if (str_int[i] == '5') returning_value = (returning_value * 10) + 5;;
        if (str_int[i] == '6') returning_value = (returning_value * 10) + 6;;
        if (str_int[i] == '7') returning_value = (returning_value * 10) + 7;;
        if (str_int[i] == '8') returning_value = (returning_value * 10) + 8;;
        if (str_int[i] == '9') returning_value = (returning_value * 10) + 9;;
    }
    return returning_value;
}
class game
{
    ConvexShape middle, grass, khaad, borderofkhaad;
    rightfootpath RightFootPath[9];
    leftfootpath LeftFootPath[9];
    righttrees RightTrees[9];
    lefttrees LeftTrees[9];
    stripes MiddleStripes[9];
    rightcoin RightSideCoins[9];
    rightcone RightSideCones[9];
    rightbarrier RightSideBarriers[9];
    leftcoin LeftSideCoins[9];
    int collisionforleftcoins[9], collisionforrightcions[9];
    leftcone LeftSideCones[9];
    leftbarrier LeftSideBarriers[9];
    Grass rightgrass[16];
    Texture TextureForTree, TextureForCoin, TextureForBarrier, TextureForCone, bg, textureforscore, textureforexitgame;
    RenderWindow* Renderwindow, window2;
    int gamesignal, HighScore, currentscore, CountForRightCoins, countt, CountForRightCones, Counterforgrass, CountForRIghtBarriers, CounterForLeftCoins, CounterForLeftCones, CountForLeftBarriers, SpeedOfRightCoin[9];
    int SpeedOfRightCone[9], SpeedForGrass[16], SpeedOfRightBarrier[9], SpeedOfLeftCoins[9], SpeedOfLeftCones[9], SpeedOfLeftBarriers[9], SpeedOfTrees[9], CountForTrees, CounterForFootPath, SpeedOfFootPath[9];
    Font font;
    Text TextforScore, TextForWord, TextForWordCoins, TextForHighScore, TextForCoins, Textforwordhighscore;
    string  StringForWord, StringForScore, StringForCoins, Stringforhighscore;
    Sprite sBackground;
    SoundBuffer buffer, crashbuffer, coinbuffer;
    RectangleShape recforscore, recforcoins, recforhighscore, recforexitgame;
    Sound sound, crashsound, coinsound;
    Event event;
    info* in;
    Sprite sp;
    Vector2i source;
    int up;
    int Rcoins[15];
    int Lcoins[15];
    int Rcones[15];
    int Lcones[15];
    int Rbarriers[15];
    int Lbarriers[15];
    int flag;
public:

    void stgame(RenderWindow* ww)
    {
        Renderwindow = ww;
        gamesignal = 2;
        TextureForTree.loadFromFile("22.png");
        TextureForCoin.loadFromFile("ggg.png");
        TextureForBarrier.loadFromFile("mess1.png");
        TextureForCone.loadFromFile("mess.JPG");
        textureforscore.loadFromFile("scoring.png");
        textureforexitgame.loadFromFile("exitgame.png");
        coinbuffer.loadFromFile("coin.wav");
        crashbuffer.loadFromFile("crash.wav");
        coinsound.setBuffer(coinbuffer);
        crashsound.setBuffer(crashbuffer);
        currentscore = 0, HighScore = 0;
        CountForRightCoins = 0, countt = 1, CountForRightCones = 0, Counterforgrass = 0, CountForRIghtBarriers = 0, CounterForLeftCoins = 0, CounterForLeftCones = 0, CountForLeftBarriers = 0, CountForTrees = 0, CounterForFootPath = 0;;
        for (int i = 0; i < 9; i++)
        {
            RightFootPath[i].setcolor(i);
            LeftFootPath[i].setcolor(i);

            RightTrees[i].settexture(&TextureForTree);
            LeftTrees[i].settexture(&TextureForTree);
            RightSideCoins[i].settexture(&TextureForCoin);
            RightSideCones[i].settexture(&TextureForCone);
            RightSideBarriers[i].settexture(&TextureForBarrier);
            LeftSideCoins[i].settexture(&TextureForCoin);
            LeftSideCones[i].settexture(&TextureForCone);
            LeftSideBarriers[i].settexture(&TextureForBarrier);
            SpeedOfFootPath[i] = 0;
            SpeedOfRightCoin[i] = 0;
            SpeedOfRightCone[i] = 0;
            SpeedOfRightBarrier[i] = 0;
            SpeedOfLeftCones[i] = 0;
            SpeedOfLeftCoins[i] = 0;
            SpeedOfLeftBarriers[i] = 0;
            SpeedOfTrees[i] = 0;
            collisionforleftcoins[i] = 0;
            collisionforrightcions[i] = 0;
        }
        StringForScore = "00000000";
        StringForCoins = "00000000";
        Stringforhighscore = "00000000";
        for (int i = 0; i < 16; i++)
        {
            rightgrass[i].setcolor(i);
            SpeedForGrass[i] = 0;

        }
        recforexitgame.setTexture(&textureforexitgame);
        recforexitgame.setPosition(400, 5);
        recforexitgame.setSize(Vector2f(500, 120));
        font.loadFromFile("dub.ttf");
        TextforScore.setFont(font);
        TextForWord.setFont(font);
        StringForWord = " SCORE";
        Textforwordhighscore.setFont(font);
        TextForHighScore.setFont(font);
        Textforwordhighscore.setPosition(70, 25);
        TextForHighScore.setPosition(70, 52);
        TextForWord.setString(StringForWord);
        TextforScore.setString(StringForScore);
        TextForCoins.setString(StringForCoins);
        TextforScore.setPosition(Vector2f(1145, 52));
        recforscore.setPosition(1050, 5);
        recforscore.setSize(Vector2f(300, 80));
        recforcoins.setSize(Vector2f(300, 80));
        recforcoins.setPosition(Vector2f(1050, 90));
        recforcoins.setTexture(&textureforscore);
        recforhighscore.setTexture(&textureforscore);
        recforhighscore.setPosition(10, 5);
        recforhighscore.setSize(Vector2f(300, 80));
        TextForWordCoins.setFont(font);
        Textforwordhighscore.setString("Highest Score");
        TextForHighScore.setString(Stringforhighscore);
        Textforwordhighscore.setFillColor(Color::White);
        TextForHighScore.setFillColor(Color::White);
        TextForCoins.setFont(font);
        TextForWordCoins.setString("Coins");
        TextForWordCoins.setPosition(1150, 110);
        TextForCoins.setPosition(1145, 137);
        recforscore.setTexture(&textureforscore);
        TextForWord.setPosition(Vector2f(1145, 25));
        TextForWord.setFillColor(Color::White);
        TextforScore.setFillColor(Color::White);
        middle.setPointCount(4);
        grass.setPointCount(4);
        middle.setPoint(0, Vector2f(-50, 0));
        middle.setPoint(1, Vector2f(-610, +350));
        middle.setPoint(2, Vector2f(+610, +350));
        middle.setPoint(3, Vector2f(+40, 0));
        middle.setPosition(650, 410);
        grass.setPosition(0, 410);
        grass.setPoint(0, Vector2f(0, 0));
        grass.setPoint(1, Vector2f(0, +350));
        grass.setPoint(2, Vector2f(+1400, +350));
        grass.setPoint(3, Vector2f(+1400, 0));
        grass.setFillColor(Color(20, 230, 20));
        middle.setFillColor(Color::Black);
        khaad.setPointCount(4);
        khaad.setPosition(650, 410);
        khaad.setFillColor(Color::Color(128, 80, 32));
        khaad.setPoint(0, Vector2f(-50, 0));
        khaad.setPoint(1, Vector2f(-860, +350));
        khaad.setPoint(2, Vector2f(+860, +350));
        khaad.setPoint(3, Vector2f(+50, 0));
        borderofkhaad.setPointCount(4);
        borderofkhaad.setPosition(650, 410);
        borderofkhaad.setFillColor(Color(128, 128, 128));
        borderofkhaad.setPoint(0, Vector2f(-52, 0));
        borderofkhaad.setPoint(1, Vector2f(-950, +350));
        borderofkhaad.setPoint(2, Vector2f(+950, +350));
        borderofkhaad.setPoint(3, Vector2f(+52, 0));
        bg.loadFromFile("bg.png");
        bg.setRepeated(true);
        sBackground.setTexture(bg);
        sBackground.setTextureRect(IntRect(0, 0, 5000, 411));
        sBackground.setPosition(-2000, 0);
        buffer.loadFromFile("police.wav");
        sound.setBuffer(buffer);
    }
    void setcoins()
    {
        int coins = fun_for_returning_integer_value(StringForCoins, StringForCoins.length());
        int totalcoins = in->getcoins();
        totalcoins += 1;
        in->setcoins(totalcoins);
        coins += 1;
        int i = 7;
        while (i != -1)
        {
            StringForCoins[i] = (coins % 10) + 48;
            coins /= 10;
            i--;
        }
        TextForCoins.setString(StringForCoins);
    }
    void movingborders()
    {
        if (CounterForFootPath < 8)
        {
            CounterForFootPath += 1;
            RightFootPath[CounterForFootPath].set();
            LeftFootPath[CounterForFootPath].set();
            Renderwindow->clear(Color::Blue);
            for (int x = 0; x < CounterForFootPath; x += 1)
            {
                SpeedOfFootPath[x] += 1;
            }
        }
        else if (CounterForFootPath >= 8)
        {
            for (int i = 0; i < 9; i++)
            {
                if (SpeedOfFootPath[i] == 8)
                {
                    SpeedOfFootPath[i] = 0;
                    RightFootPath[i].set();
                    LeftFootPath[i].set();
                    Renderwindow->clear(Color::Blue);
                }
                else
                {
                    SpeedOfFootPath[i] += 1;
                }
            }
        }
    }
    void movinggrass()
    {
        if (Counterforgrass < 15)
        {
            Counterforgrass += 1;
            rightgrass[Counterforgrass].set();
            for (int i = 0; i < Counterforgrass; i++)
            {
                SpeedForGrass[i] += 1;
            }
        }
        else if (Counterforgrass >= 15)
        {
            for (int i = 0; i < 16; i++)
            {
                if (SpeedForGrass[i] == 15)
                {
                    SpeedForGrass[i] = 0;
                    rightgrass[i].set();
                }
                else
                {
                    SpeedForGrass[i] += 1;
                }
            }
        }
    }
    void setinfo(info* inn)
    {
        in = inn;
    }
    void movingobstacles()
    {
        int ran = rand() % 3;
        if (ran == 0)
        {
            if (CountForRightCoins < 8)
            {
                RightSideCoins[CountForRightCoins].set();

                for (int x = 0; x < CountForRightCoins; x += 1)
                {
                    SpeedOfRightCoin[x] += 1;
                }
                for (int x = 0; x < CountForRightCones; x += 1)
                {
                    SpeedOfRightCone[x] += 1;
                }
                for (int x = 0; x < CountForRIghtBarriers; x += 1)
                {
                    SpeedOfRightBarrier[x] += 1;
                }
                CountForRightCoins++;
            }
            else
            {
                int mint = 7;
                for (int i = 0; i < 9; i++)
                {
                    if (SpeedOfRightCoin[i] >= mint)
                    {

                        RightSideCoins[i].set();
                        collisionforrightcions[i] = 0;
                        SpeedOfRightCoin[i] = 0;
                        mint = 100;
                    }
                    else
                        SpeedOfRightCoin[i]++;
                }
                for (int x = 0; x < CountForRightCones; x += 1)
                {
                    if (SpeedOfRightCone[x] < 7)
                        SpeedOfRightCone[x] += 1;
                }
                for (int x = 0; x < CountForRIghtBarriers; x += 1)
                {
                    if (SpeedOfRightBarrier[x] < 7)
                        SpeedOfRightBarrier[x] += 1;
                }
            }
        }
        else if (ran == 1)
        {
            if (CountForRightCones < 8)
            {
                RightSideCones[CountForRightCones].set();

                for (int x = 0; x < CountForRightCones; x += 1)
                {
                    SpeedOfRightCone[x] += 1;
                }

                for (int x = 0; x < CountForRightCoins; x += 1)
                {
                    SpeedOfRightCoin[x] += 1;
                }
                for (int x = 0; x < CountForRIghtBarriers; x += 1)
                {
                    SpeedOfRightBarrier[x] += 1;
                }
                CountForRightCones++;

            }
            else
            {
                int mint = 7;
                for (int i = 0; i < 9; i++)
                {
                    if (SpeedOfRightCone[i] >= mint)
                    {

                        RightSideCones[i].set();
                        SpeedOfRightCone[i] = 0;
                        mint = 100;
                    }
                    else
                        SpeedOfRightCone[i]++;
                }
                for (int x = 0; x < CountForRightCoins; x += 1)
                {
                    if (SpeedOfRightCoin[x] < 7)
                        SpeedOfRightCoin[x] += 1;
                }
                for (int x = 0; x < CountForRIghtBarriers; x += 1)
                {
                    if (SpeedOfRightBarrier[x] < 7)
                        SpeedOfRightBarrier[x] += 1;
                }
            }
        }
        else if (ran == 2)
        {
            if (CountForRIghtBarriers < 8)
            {
                RightSideBarriers[CountForRIghtBarriers].set();

                for (int x = 0; x < CountForRIghtBarriers; x += 1)
                {
                    SpeedOfRightBarrier[x] += 1;
                }
                for (int x = 0; x < CountForRightCones; x += 1)
                {
                    SpeedOfRightCone[x] += 1;
                }

                for (int x = 0; x < CountForRightCoins; x += 1)
                {
                    SpeedOfRightCoin[x] += 1;
                }
                CountForRIghtBarriers++;
            }
            else
            {
                int mint = 7;
                for (int i = 0; i < 9; i++)
                {
                    if (SpeedOfRightBarrier[i] >= mint)
                    {

                        RightSideBarriers[i].set();
                        SpeedOfRightBarrier[i] = 0;
                        mint = 100;
                    }
                    else
                        SpeedOfRightBarrier[i]++;
                }
                for (int x = 0; x < CountForRightCones; x += 1)
                {
                    if (SpeedOfRightCone[x] < 7)
                        SpeedOfRightCone[x] += 1;
                }

                for (int x = 0; x < CountForRightCoins; x += 1)
                {
                    if (SpeedOfRightCoin[x] < 7)
                        SpeedOfRightCoin[x] += 1;
                }
            }
        }
        ran = rand() % 3;
        if (ran == 2)
        {
            if (CounterForLeftCoins < 8)
            {
                LeftSideCoins[CounterForLeftCoins].set();

                for (int x = 0; x < CounterForLeftCoins; x += 1)
                {
                    SpeedOfLeftCoins[x] += 1;
                }
                for (int x = 0; x < CounterForLeftCones; x += 1)
                {
                    SpeedOfLeftCones[x] += 1;
                }
                for (int x = 0; x < CountForLeftBarriers; x += 1)
                {
                    SpeedOfLeftBarriers[x] += 1;
                }
                CounterForLeftCoins++;
            }
            else
            {
                int mint = 7;
                for (int i = 0; i < 9; i++)
                {
                    if (SpeedOfLeftCoins[i] >= mint)
                    {

                        LeftSideCoins[i].set();
                        SpeedOfLeftCoins[i] = 0;
                        collisionforleftcoins[i] = 0;
                        mint = 100;
                    }
                    else
                        SpeedOfLeftCoins[i]++;
                }
                for (int x = 0; x < CounterForLeftCones; x += 1)
                {
                    if (SpeedOfLeftCones[x] < 7)
                        SpeedOfLeftCones[x] += 1;
                }
                for (int x = 0; x < CountForLeftBarriers; x += 1)
                {
                    if (SpeedOfLeftBarriers[x] < 7)
                        SpeedOfLeftBarriers[x] += 1;
                }
            }
        }
        else if (ran == 0)
        {
            if (CounterForLeftCones < 8)
            {
                LeftSideCones[CounterForLeftCones].set();

                for (int x = 0; x < CounterForLeftCones; x += 1)
                {
                    SpeedOfLeftCones[x] += 1;
                }

                for (int x = 0; x < CounterForLeftCoins; x += 1)
                {
                    SpeedOfLeftCoins[x] += 1;
                }
                for (int x = 0; x < CountForLeftBarriers; x += 1)
                {
                    SpeedOfLeftBarriers[x] += 1;
                }
                CounterForLeftCones++;

            }
            else
            {
                int mint = 7;
                for (int i = 0; i < 9; i++)
                {
                    if (SpeedOfLeftCones[i] >= mint)
                    {

                        LeftSideCones[i].set();
                        SpeedOfLeftCones[i] = 0;
                        mint = 100;
                    }
                    else
                        SpeedOfLeftCones[i]++;
                }
                for (int x = 0; x < CounterForLeftCoins; x += 1)
                {
                    if (SpeedOfLeftCoins[x] < 7)
                        SpeedOfLeftCoins[x] += 1;
                }
                for (int x = 0; x < CountForLeftBarriers; x += 1)
                {
                    if (SpeedOfLeftBarriers[x] < 7)
                        SpeedOfLeftBarriers[x] += 1;
                }
            }
        }
        else if (ran == 1)
        {
            if (CountForLeftBarriers < 8)
            {
                LeftSideBarriers[CountForLeftBarriers].set();

                for (int x = 0; x < CountForLeftBarriers; x += 1)
                {
                    SpeedOfLeftBarriers[x] += 1;
                }
                for (int x = 0; x < CounterForLeftCones; x += 1)
                {
                    SpeedOfLeftCones[x] += 1;
                }

                for (int x = 0; x < CounterForLeftCoins; x += 1)
                {
                    SpeedOfLeftCoins[x] += 1;
                }
                CountForLeftBarriers++;
            }
            else
            {
                int mint = 7;
                for (int i = 0; i < 9; i++)
                {
                    if (SpeedOfLeftBarriers[i] >= mint)
                    {

                        LeftSideBarriers[i].set();
                        SpeedOfLeftBarriers[i] = 0;
                        mint = 100;
                    }
                    else
                        SpeedOfLeftBarriers[i]++;
                }
                for (int x = 0; x < CounterForLeftCones; x += 1)
                {
                    if (SpeedOfLeftCones[x] < 7)
                        SpeedOfLeftCones[x] += 1;
                }

                for (int x = 0; x < CounterForLeftCoins; x += 1)
                {
                    if (SpeedOfLeftCoins[x] < 7)
                        SpeedOfLeftCoins[x] += 1;
                }
            }
        }
    }
    void movingtrees()
    {

        if (countt % 305 == 0)
        {
            if (CountForTrees < 8)
            {
                CountForTrees += 1;
                RightTrees[CountForTrees].set();
                LeftTrees[CountForTrees].set();
                MiddleStripes[CountForTrees].set();
                for (int x = 0; x < CountForTrees; x += 1)
                {
                    SpeedOfTrees[x] += 1;
                }
            }
            else if (CountForTrees >= 8)
            {
                for (int ass = 0; ass < 9; ass++)
                {
                    if (SpeedOfTrees[ass] == 8)
                    {
                        SpeedOfTrees[ass] = 0;
                        RightTrees[ass].set();
                        LeftTrees[ass].set();
                        MiddleStripes[ass].set();
                    }
                    else
                    {
                        SpeedOfTrees[ass] += 1;
                    }
                }
            }
        }
    }
    void score()
    {
        if (countt % 50 == 0)
        {
            if (StringForScore[0] == '9')
                exit(0);
            else
            {
                if (StringForScore[7] == '9')
                {
                    StringForScore[7] = '0';
                    if (StringForScore[6] == '9')
                    {
                        StringForScore[6] = '0';
                        if (StringForScore[5] == '9')
                        {
                            StringForScore[5] == '0';
                            if (StringForScore[4] == '9')
                            {
                                StringForScore[4] = '0';
                                if (StringForScore[3] == '9')
                                {
                                    StringForScore[3] = '0';
                                    if (StringForScore[2] == '9')
                                    {
                                        StringForScore[2] = 0;
                                        if (StringForScore[1] == '9')
                                        {
                                            StringForScore[1] = '0';
                                            if (StringForScore[0] == '9')
                                            {
                                                StringForScore[0] = '0';
                                            }
                                            else
                                                StringForScore[0]++;
                                        }
                                        else
                                            StringForScore[1]++;
                                    }
                                    else
                                        StringForScore[2]++;
                                }
                                else
                                    StringForScore[3]++;
                            }
                            else
                                StringForScore[4]++;
                        }
                        else
                            StringForScore[5]++;
                    }
                    else
                        StringForScore[6] += 1;
                }
                else
                    StringForScore[7] += 1;
            }
        }
        TextforScore.setString(StringForScore);
        currentscore = fun_for_returning_integer_value(StringForScore, StringForScore.length());
        HighScore = in->getscore();
        if (currentscore >= HighScore)
        {
            in->setscore(currentscore);
            HighScore = currentscore;
        }
        int i = 7;
        while (i != -1)
        {
            Stringforhighscore[i] = (HighScore % 10) + 48;
            HighScore /= 10;
            i -= 1;
        }
        TextForHighScore.setString(Stringforhighscore);


    }
    void setting()
    {
        RightFootPath[0].set();
        LeftFootPath[0].set();
        RightTrees[0].set();
        LeftTrees[0].set();
        MiddleStripes[0].set();
        rightgrass[0].set();
        //   tdd[0].set();
        Renderwindow->clear(Color::Blue);
    }
    void movingeverything()
    {
        for (int xx = 0; xx <= CounterForFootPath; xx++)
        {
            RightFootPath[xx].speed(SpeedOfFootPath[xx]);
            LeftFootPath[xx].speed(SpeedOfFootPath[xx]);

        }
        for (int xx = 0; xx <= Counterforgrass; xx++)
        {
            rightgrass[xx].speed(SpeedForGrass[xx]);
        }
        for (int x = 0; x <= CountForTrees; x++)
        {
            RightTrees[x].speed(SpeedOfTrees[x]);
            LeftTrees[x].speed(SpeedOfTrees[x]);
            MiddleStripes[x].speed(SpeedOfTrees[x]);
            //  tdd[x].speed(counter[x]);
        }
        for (int x = 0; x <= CountForRightCoins; x++)
            RightSideCoins[x].speed(SpeedOfRightCoin[x]);
        for (int x = 0; x <= CountForRightCones; x++)
            RightSideCones[x].speed(SpeedOfRightCone[x]);
        for (int x = 0; x <= CountForRIghtBarriers; x++)
            RightSideBarriers[x].speed(SpeedOfRightBarrier[x]);
        for (int x = 0; x <= CounterForLeftCoins; x++)
            LeftSideCoins[x].speed(SpeedOfLeftCoins[x]);
        for (int x = 0; x <= CounterForLeftCones; x++)
            LeftSideCones[x].speed(SpeedOfLeftCones[x]);
        for (int x = 0; x <= CountForLeftBarriers; x++)
            LeftSideBarriers[x].speed(SpeedOfLeftBarriers[x]);
    }
    int Startgame(Sprite spp, Vector2i sourcee, int upp)
    {
        gamesignal = 0;
        if (countt % 150 == 0)
        {
            movingborders();
            movinggrass();
        }
        else if (countt == 1)
        {
            setting();
        }
        if (countt % 50 == 0)
        {
            score();

        }
        else if (countt % 305 == 0)
        {
            movingtrees();
        }
        else if (countt % 301 == 0)
        {
            movingobstacles();
        }
        if (countt % 8003 == 0)
            sound.play();
        movingeverything();
        countt++;
        this->sp = spp;
        this->source = sourcee;

        this->up = upp;
        sp.setTextureRect(sf::IntRect(source.x * 80, source.y * 150, 80, 150));

        gamesignal = Output();
        return gamesignal;
    }
    int transition()
    {
        window2.create(sf::VideoMode(550, 380), "", Style::None);
        Texture txx1, yesop, noop;
        txx1.loadFromFile("option.png");
        yesop.loadFromFile("yesbutton.png");
        noop.loadFromFile("nobutton.png");
        RectangleShape background1(Vector2f(550, 380)), yesoption(Vector2f(100, 100)), nooption(Vector2f(100, 100));
        background1.setPosition(0, 0);
        Event e1;
        background1.setTexture(&txx1);
        yesoption.setTexture(&yesop);
        nooption.setTexture(&noop);
        yesoption.setPosition(150, 170);
        nooption.setPosition(300, 170);
        //  int signer = 0;
        while (window2.isOpen())
        {

            Vector2i mousi = Mouse::getPosition(window2);
            if ((mousi.x >= 150 && mousi.x <= 250) && (mousi.y >= 170 && mousi.y <= 270))
            {
                txx1.loadFromFile("yassoption.png");
                yesoption.setPosition(145, 165);
                yesoption.setSize(Vector2f(115, 115));
            }
            else if ((mousi.x >= 300 && mousi.x <= 400) && (mousi.y >= 170 && mousi.y <= 270))
            {
                txx1.loadFromFile("nooption.png");
                nooption.setPosition(295, 165);
                nooption.setSize(Vector2f(115, 115));
            }
            else
            {
                txx1.loadFromFile("option.png");
                yesoption.setPosition(150, 170);
                yesoption.setSize(Vector2f(100, 100));
                nooption.setPosition(300, 170);
                nooption.setSize(Vector2f(100, 100));
            }
            while (window2.pollEvent(e1))
            {
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    if ((mousi.x >= 150 && mousi.x <= 250) && (mousi.y >= 170 && mousi.y <= 270))
                    {
                        gamesignal = 1;
                        window2.close();

                    }

                    else if ((mousi.x >= 300 && mousi.x <= 400) && (mousi.y >= 170 && mousi.y <= 270))
                    {
                        window2.close();
                        // signer = 2;
                    }
                }
            }
            background1.setTexture(&txx1);
            window2.draw(background1);
            window2.draw(yesoption);
            window2.draw(nooption);
            window2.display();
        }
        return gamesignal;

    }
    int Output()
    {
        gamesignal = 0;
        flag = 0;
        Renderwindow->clear(Color::Blue);
        Renderwindow->draw(sBackground);
        Renderwindow->draw(grass);

        

        for (int i = 0; i < CountForRightCoins; i++)
        {
            if (Rcoins[i] == 1 && RightSideCoins[i].sh.getGlobalBounds().top + RightSideCoins[i].sh.getGlobalBounds().height >= 640 && RightSideCoins[i].sh.getGlobalBounds().top + RightSideCoins[i].sh.getGlobalBounds().height <= 670)
            {
                Renderwindow->draw(sp);
               // flag = 1;
            }

        }


        for (int i = 0; i < CountForRightCones; i++)
        {
            if (Rcones[i] == 1 && RightSideCones[i].sh.getGlobalBounds().top + RightSideCones[i].sh.getGlobalBounds().height >= 640 && RightSideCones[i].sh.getGlobalBounds().top + RightSideCones[i].sh.getGlobalBounds().height <= 670)
            {
                Renderwindow->draw(sp);

                flag = 1;
            }

        }


        for (int i = 0; i < CountForRIghtBarriers; i++)
        {
            if (Rbarriers[i] == 1 && RightSideBarriers[i].sh.getGlobalBounds().top + RightSideBarriers[i].sh.getGlobalBounds().height >= 640 && RightSideBarriers[i].sh.getGlobalBounds().top + RightSideBarriers[i].sh.getGlobalBounds().height <= 670)
            {
                Renderwindow->draw(sp);
                flag = 1;
            }

        }




        for (int i = 0; i < CounterForLeftCoins; i++)
        {
            if (Lcoins[i] == 1 && LeftSideCoins[i].sh.getGlobalBounds().top + LeftSideCoins[i].sh.getGlobalBounds().height >= 640 && LeftSideCoins[i].sh.getGlobalBounds().top + LeftSideCoins[i].sh.getGlobalBounds().height <= 670)
            {
                Renderwindow->draw(sp);
               flag = 1;
            }

        }


        for (int i = 0; i < CounterForLeftCones; i++)
        {
            if (Lcones[i] == 1 && LeftSideCones[i].sh.getGlobalBounds().top + LeftSideCones[i].sh.getGlobalBounds().height >= 640 && LeftSideCones[i].sh.getGlobalBounds().top + LeftSideCones[i].sh.getGlobalBounds().height <= 670)
            {
                Renderwindow->draw(sp);

                flag = 1;
            }

        }


        for (int i = 0; i < CountForLeftBarriers; i++)
        {
            if (Lbarriers[i] == 1 && LeftSideBarriers[i].sh.getGlobalBounds().top + LeftSideBarriers[i].sh.getGlobalBounds().height >= 640 && LeftSideBarriers[i].sh.getGlobalBounds().top + LeftSideBarriers[i].sh.getGlobalBounds().height <= 670)
            {
                Renderwindow->draw(sp);
                flag = 1;
            }

        }






        for (int yy = 0; yy <= Counterforgrass; yy++)
        {
            Renderwindow->draw(rightgrass[yy].sh);
        }

        Renderwindow->draw(borderofkhaad);
        Renderwindow->draw(khaad);

        Renderwindow->draw(middle); 
        Renderwindow->draw(sp);
        for (int yy = 0; yy <= CounterForFootPath; yy++)
        {
            Renderwindow->draw(RightFootPath[yy].s);
            Renderwindow->draw(LeftFootPath[yy].s);
        }
        for (int yy = CountForTrees; yy >= 0; yy--)
        {
            Renderwindow->draw(MiddleStripes[yy].sh);
        }
        for (int i = CountForTrees; i >= 0; i--)
        {
            Renderwindow->draw(RightTrees[i].sh);
            Renderwindow->draw(LeftTrees[i].sh);
        }
        for (int i = 0; i < CountForRightCoins; i++)
        {


            if (sp.getGlobalBounds().left < 650)
            {
                Rcoins[i] = 1;
            }

            if (sp.getGlobalBounds().left >= 650)
                if (RightSideCoins[i].sh.getGlobalBounds().top + RightSideCoins[i].sh.getGlobalBounds().height < 600)
                {
                    Rcoins[i] = 0;
                }
            if (RightSideCoins[i].sh.getGlobalBounds().top + RightSideCoins[i].sh.getGlobalBounds().height > 670 && up > 0 && RightSideCoins[i].sh.getGlobalBounds().top + RightSideCoins[i].sh.getGlobalBounds().height <= 750)
            {
                Rcoins[i] = 1;
                Renderwindow->draw(RightSideCoins[i].sh);


            }
            else if (RightSideCoins[i].sh.getGlobalBounds().top + RightSideCoins[i].sh.getGlobalBounds().height <= 680 && sp.getGlobalBounds().left >= 650)
            {
                Renderwindow->draw(RightSideCoins[i].sh);


            }
            else if (Rcoins[i] == 1)
            {
                Renderwindow->draw(RightSideCoins[i].sh);


            }
            else if (sp.getGlobalBounds().left < 650)
            {
                Renderwindow->draw(RightSideCoins[i].sh);
            }
            else
            {
                if (collisionforrightcions[i] == 0)
                {
                    coinsound.play();
                    collisionforrightcions[i] = 1;
                    setcoins();
                }
            }

        }
        for (int i = 0; i < CountForRightCones; i++)
        {
            if (sp.getGlobalBounds().left < 650)
            {
                Rcones[i] = 1;
            }
            if (RightSideCones[i].sh.getGlobalBounds().top + RightSideCones[i].sh.getGlobalBounds().height < 600)
            {
                Rcones[i] = 0;
            }
            if (RightSideCones[i].sh.getGlobalBounds().top + RightSideCones[i].sh.getGlobalBounds().height > 680 && up > 0 && RightSideCones[i].sh.getGlobalBounds().top + RightSideCones[i].sh.getGlobalBounds().height <= 750)
            {
                Rcones[i] = 1;
                Renderwindow->draw(RightSideCones[i].sh);


            }
            else if (RightSideCones[i].sh.getGlobalBounds().top + RightSideCones[i].sh.getGlobalBounds().height <= 720)
            {
                Renderwindow->draw(RightSideCones[i].sh);

            }
            else if (Rcones[i] == 1)
            {
                Renderwindow->draw(RightSideCones[i].sh);

            }
            else if (sp.getGlobalBounds().left < 650)
            {
                Renderwindow->draw(RightSideCones[i].sh);
            }
            else
            {
                crashsound.play();
                gamesignal = 1;
            }
        }
        for (int i = 0; i < CountForRIghtBarriers; i++)
        {
            if (sp.getGlobalBounds().left < 650)
            {
                Rbarriers[i] = 1;
            }
            if (RightSideBarriers[i].sh.getGlobalBounds().top + RightSideBarriers[i].sh.getGlobalBounds().height < 600)
            {
                Rbarriers[i] = 0;
            }
            if (RightSideBarriers[i].sh.getGlobalBounds().top + RightSideBarriers[i].sh.getGlobalBounds().height > 680 && up > 0 && RightSideBarriers[i].sh.getGlobalBounds().top + RightSideBarriers[i].sh.getGlobalBounds().height <= 750)
            {
                Rbarriers[i] = 1;
                Renderwindow->draw(RightSideBarriers[i].sh);
            }
            else if (RightSideBarriers[i].sh.getGlobalBounds().top + RightSideBarriers[i].sh.getGlobalBounds().height <= 720)
            {
                Renderwindow->draw(RightSideBarriers[i].sh);

            }
            else if (Rbarriers[i] == 1)
            {
                Renderwindow->draw(RightSideBarriers[i].sh);

            }
            else if (sp.getGlobalBounds().left < 650)
            {
                Renderwindow->draw(RightSideBarriers[i].sh);
            }
            else
            {
                crashsound.play();
                gamesignal = 1;
            }
        }
        for (int i = 0; i < CounterForLeftCoins; i++)
        {
            if (sp.getGlobalBounds().left >= 650)
            {
                Lcoins[i] = 1;
            }

            if (LeftSideCoins[i].sh.getGlobalBounds().top + LeftSideCoins[i].sh.getGlobalBounds().height < 600)
            {
                Lcoins[i] = 0;
            }
            if (LeftSideCoins[i].sh.getGlobalBounds().top + LeftSideCoins[i].sh.getGlobalBounds().height > 670 && up > 0 && LeftSideCoins[i].sh.getGlobalBounds().top + LeftSideCoins[i].sh.getGlobalBounds().height <= 750)
            {
                Lcoins[i] = 1;
                Renderwindow->draw(LeftSideCoins[i].sh);
            }
            else if (LeftSideCoins[i].sh.getGlobalBounds().top + LeftSideCoins[i].sh.getGlobalBounds().height <= 680)
            {
                Renderwindow->draw(LeftSideCoins[i].sh);

            }
            else if (Lcoins[i] == 1)
            {
                Renderwindow->draw(LeftSideCoins[i].sh);

            }
            else if (sp.getGlobalBounds().left >= 650)
            {
                Renderwindow->draw(LeftSideCoins[i].sh);
            }
            else
            {
                if (collisionforleftcoins[i] == 0)
                {
                    coinsound.play();
                    collisionforleftcoins[i] = 1;
                    setcoins();
                }
            }


        }

        for (int i = 0; i < CounterForLeftCones; i++)
        {
            if (sp.getGlobalBounds().left >= 650)
            {
                Lcones[i] = 1;
            }
            if (LeftSideCones[i].sh.getGlobalBounds().top + LeftSideCones[i].sh.getGlobalBounds().height < 600)
            {
                Lcones[i] = 0;
            }
            if (LeftSideCones[i].sh.getGlobalBounds().top + LeftSideCones[i].sh.getGlobalBounds().height > 670 && up > 0 && LeftSideCones[i].sh.getGlobalBounds().top + LeftSideCones[i].sh.getGlobalBounds().height <= 750)
            {
                Lcones[i] = 1;
                Renderwindow->draw(LeftSideCones[i].sh);


            }
            else if (LeftSideCones[i].sh.getGlobalBounds().top + LeftSideCones[i].sh.getGlobalBounds().height <= 720)
            {
                Renderwindow->draw(LeftSideCones[i].sh);

            }
            else if (Lcones[i] == 1)
            {
                Renderwindow->draw(LeftSideCones[i].sh);

            }
            else if (sp.getGlobalBounds().left >= 650)
            {
                Renderwindow->draw(LeftSideCones[i].sh);
            }
            else
            {
                crashsound.play();
                gamesignal = 1;
            }

        }
        for (int i = 0; i < CountForLeftBarriers; i++)
        {
            if (sp.getGlobalBounds().left >= 650)
            {
                Lbarriers[i] = 1;
            }
            if (LeftSideBarriers[i].sh.getGlobalBounds().top + LeftSideBarriers[i].sh.getGlobalBounds().height < 600)
            {
                Lbarriers[i] = 0;
            }
            if (LeftSideBarriers[i].sh.getGlobalBounds().top + LeftSideBarriers[i].sh.getGlobalBounds().height > 670 && up > 0 && LeftSideBarriers[i].sh.getGlobalBounds().top + LeftSideBarriers[i].sh.getGlobalBounds().height <= 750)
            {
                Lbarriers[i] = 1;
                Renderwindow->draw(LeftSideBarriers[i].sh);
            }
            else if (LeftSideBarriers[i].sh.getGlobalBounds().top + LeftSideBarriers[i].sh.getGlobalBounds().height <= 720)
            {
                Renderwindow->draw(LeftSideBarriers[i].sh);

            }
            else if (Lbarriers[i] == 1)
            {
                Renderwindow->draw(LeftSideBarriers[i].sh);

            }
            else if (sp.getGlobalBounds().left >= 650)
            {
                Renderwindow->draw(LeftSideBarriers[i].sh);
            }
            else
            {
                crashsound.play();
                gamesignal = 1;
            }
        }

        if (flag == 0)
        {
            Renderwindow->draw(sp);
        }
        Renderwindow->draw(recforscore);
        Renderwindow->draw(recforcoins);
        Renderwindow->draw(recforexitgame);
        Renderwindow->draw(recforhighscore);
        Renderwindow->draw(TextforScore);
        Renderwindow->draw(TextForWord);
        Renderwindow->draw(TextForWordCoins);
        Renderwindow->draw(TextForCoins);
        Renderwindow->draw(Textforwordhighscore);
        Renderwindow->draw(TextForHighScore);
       // Renderwindow->draw(sp);
        Renderwindow->display();
        return gamesignal;
    }

};
class signing_up
{
    info* in;
    char name_info[16], pass_info[16], email_info[16];
public:

    signing_up(char* name_infoo, char* pass_infoo, char* email_infoo, info* in)
    {
        this->in = in;
        in->setname(name_info);
        in->setpassword(pass_info);
        in->setemail(email_info);
        for (int i = 0; i < 16; i++)
        {
            name_info[i] = '\0';
            pass_info[i] = '\0';
            email_info[i] = '\0';
        }
        strcpy_s(this->name_info, name_infoo);
        strcpy_s(this->pass_info, pass_infoo);
        strcpy_s(this->email_info, email_infoo);
    }
    void putting_in_file()
    {
        ofstream storing;
        storing.open("information.txt", ios::out | ios::app);
        if (!storing)
        {
            cout << "ERROR OPENING FILE!!!!!!!!" << endl;
            exit(1);
        }
        storing << endl << name_info << " " << pass_info << " " << email_info << " " << in->getcoins() << " " << in->getcharacterbought1() << " " << in->getcharacterbought2() << " " << in->getlastcharater1() << " " << in->getlastcharater2() << " " << in->getlastcharater3() << " " << in->getscore();
        storing.close();
    }

    int existing_name_checking()
    {
        int yl = 0;
        ifstream storing;
        storing.open("information.txt");
        char ch[16] = "               ", nnn[16];

        int ii = 0;
        for (ii = 0; ii < 16; ii++)
        {
            nnn[ii] = '\0';

        }
        for (ii = 0; ii < 16; ii++)
        {
            if (name_info[ii] != ' ')
            {
                nnn[ii] = name_info[ii];
            }
        }
        ii = 0;
        int yyyyy = 0;
        while (storing >> ch && !storing.eof())
        {
            if ((ii % 10) == 0)
            {
                if (strcmp(nnn, ch) == 0)
                {
                    yyyyy = 1;
                }
            }
            ii++;
        }
        return yyyyy;
    }
};
class signupwindow
{
    int username_indication, password_indication, register_indication, confirmation_indication, email_indication, cancel_req;
    char filing_signup_uname[16], filing_signup_pass[16], filing_signup_confirm[16], filing_signup_email[16], passwordstar[16], confirmpasswordstar[16];
    char check[16];
    sf::Text __uname_, __pass_, __cpass_, __email_, sign_up_failing_text;
    int sign_email, sign_password, sign_username, sign_confirm_password, uu, up, ucp, ue, uuu;
    Font f1;
    RectangleShape  _register_, _cancel_, recc;
    Texture canceltexture, registertexture, tm;
    RenderWindow window3;
    Event event;
    info* in;
    SoundBuffer buff, select;
    Sound sound, selectt;
public:
    void windoww()
    {
        window3.create(sf::VideoMode(550, 320), "SIGN UP", Style::None);
    }
    void infoo(info* in)
    {
        this->in = in;
    }
    signupwindow()
    {
        buff.loadFromFile("keyboard.wav");
        sound.setBuffer(buff);
        select.loadFromFile("sellect1.wav");
        selectt.setBuffer(select);
        username_indication = 2, password_indication = 0, register_indication = 0, confirmation_indication = 0, email_indication = 0;
        sign_email = 0, sign_password = 0, sign_username = 0, sign_confirm_password = 0;
        uu = 0, up = 0, ucp = 0, ue = 0, uuu = 0, cancel_req = 0;
        filing_signup_uname[0] = '|', filing_signup_pass[0] = '\0', filing_signup_confirm[0] = '\0', filing_signup_email[0] = '\0';
        for (int i = 0; i < 16; i++)
        {
            filing_signup_uname[i] = '\0';
            filing_signup_pass[i] = '\0';
            filing_signup_confirm[i] = '\0';
            filing_signup_email[i] = '\0';
            passwordstar[i] = '\0';
            confirmpasswordstar[i] = '\0';
        }

        tm.loadFromFile("fire1.png");
        recc.setTexture(&tm);
        recc.setSize(Vector2f(550, 320));
        recc.setPosition(0, 0);
        for (int looop = 0; looop < 16; looop++)
        {
            check[looop] = '\0';
        }
        f1.loadFromFile("username1.ttf");
        sign_email = 0, sign_password = 0, sign_username = 0, sign_confirm_password = 0;
        __uname_.setFont(f1);
        __uname_.setPosition(sf::Vector2f(133, 7));
        __uname_.setFillColor(sf::Color::Black);
        __uname_.setCharacterSize(30);
        __pass_.setFont(f1);
        __pass_.setPosition(sf::Vector2f(133, 52));
        __pass_.setFillColor(sf::Color::Black);
        __pass_.setCharacterSize(30);
        __cpass_.setFont(f1);
        __cpass_.setPosition(sf::Vector2f(133, 98));
        __cpass_.setFillColor(sf::Color::Black);
        __cpass_.setCharacterSize(30);
        __email_.setFont(f1);
        __email_.setPosition(sf::Vector2f(133, 142));
        __email_.setFillColor(sf::Color::Black);
        __email_.setCharacterSize(30);
        _register_.setSize(sf::Vector2f(320, 40)),
            _cancel_.setSize(sf::Vector2f(174, 40));
        canceltexture.loadFromFile("cancel.png");
        registertexture.loadFromFile("register.png");
        _register_.setTexture(&registertexture);
        _cancel_.setTexture(&canceltexture);
    }

    int transition()
    {

        while (window3.isOpen())
        {
            sf::Text at_least_three, at_least_eight, username_signup_text, password_signup_text, confirmation_pass_signup_text, email_signup_text, register_text, cancel_text;
            while (window3.pollEvent(event))
            {
                if (uu != 14 || up != 14 || ucp != 14 || ue != 14)
                {
                    if (event.type == sf::Event::KeyPressed)
                    {
                        if (event.key.code == sf::Keyboard::A)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'a';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'a';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'a';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'a';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::B)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'b';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'b';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'b';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'b';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::C)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'c';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'c';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'c';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'c';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::D)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'd';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'd';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'd';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'd';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::E)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'e';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'e';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'e';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'e';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::F)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'f';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'f';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'f';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'f';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::G)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'g';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'g';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'g';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'g';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::H)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'h';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'h';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'h';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'h';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::I)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'i';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'i';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'i';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'i';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::J)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'j';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'j';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'j';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'j';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::K)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'k';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'k';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'k';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'k';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::L)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'l';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'l';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'l';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'l';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::M)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'm';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'm';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'm';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'm';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::N)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'n';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'n';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'n';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'n';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::O)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'o';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'o';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'o';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'o';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::P)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'p';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'p';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'p';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'p';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::Q)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'q';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'q';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'q';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'q';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::R)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'r';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'r';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'r';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'r';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::S)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 's';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 's';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 's';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 's';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::T)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 't';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 't';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 't';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 't';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::U)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'u';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'u';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'u';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'u';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::V)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'v';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'v';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'v';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'v';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::W)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'w';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'w';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'w';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'w';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::X)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'x';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'x';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'x';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'x';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::Y)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'y';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'y';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'y';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'y';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::Z)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = 'z';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = 'z';
                                passwordstar[up] = '*';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = 'z';
                                confirmpasswordstar[ucp] = '*';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = 'z';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::Space)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu != 14)
                            {
                                filing_signup_uname[uu] = ' ';
                                uu++;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up != 14)
                            {
                                filing_signup_pass[up] = ' ';
                                passwordstar[up] = ' ';
                                up++;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp != 14)
                            {
                                filing_signup_confirm[ucp] = ' ';
                                confirmpasswordstar[ucp] = ' ';
                                ucp++;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue != 14)
                            {
                                filing_signup_email[ue] = ' ';
                                ue++;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::BackSpace)
                        {
                            if ((username_indication == 1 || username_indication == 2) && uu > 0)
                            {
                                filing_signup_uname[uu] = ' ';
                                uu--;
                                filing_signup_uname[uu] = '|';
                            }
                            else if (password_indication == 1 && up > 0)
                            {
                                filing_signup_pass[up] = ' ';
                                passwordstar[up] = ' ';
                                up--;
                                filing_signup_pass[up] = '|';
                                passwordstar[up] = '|';
                            }
                            else if (confirmation_indication == 1 && ucp > 0)
                            {
                                filing_signup_confirm[ucp] = ' ';
                                confirmpasswordstar[ucp] = ' ';
                                ucp--;
                                filing_signup_confirm[ucp] = '|';
                                confirmpasswordstar[ucp] = '|';
                            }
                            else if (email_indication == 1 && ue > 0)
                            {
                                filing_signup_email[ue] = ' ';
                                ue--;
                                filing_signup_email[ue] = '|';
                            }
                        }
                        sound.play();
                    }
                }
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    Vector2i get_pos_mouse_sign_up = Mouse::getPosition(window3);
                    if (get_pos_mouse_sign_up.x >= 130 && get_pos_mouse_sign_up.x <= 330 && get_pos_mouse_sign_up.y >= 15 && get_pos_mouse_sign_up.y <= 40) // Username box
                    {
                        selectt.play();
                        username_indication = 1;
                        password_indication = 0;
                        confirmation_indication = 0;
                        email_indication = 0;
                        filing_signup_confirm[ucp] = ' ';
                        confirmpasswordstar[ucp] = ' ';
                        passwordstar[up] = ' ';
                        filing_signup_email[ue] = ' ';
                        filing_signup_pass[up] = ' ';
                        filing_signup_uname[uu] = '|';
                    }
                    if (get_pos_mouse_sign_up.x >= 130 && get_pos_mouse_sign_up.x <= 330 && get_pos_mouse_sign_up.y >= 150 && get_pos_mouse_sign_up.y <= 175)
                    {
                        selectt.play();
                        username_indication = 0;
                        password_indication = 0;
                        confirmation_indication = 0;
                        email_indication = 1;
                        filing_signup_confirm[ucp] = ' ';
                        confirmpasswordstar[ucp] = ' ';
                        passwordstar[up] = ' ';
                        filing_signup_email[ue] = '|';
                        filing_signup_pass[up] = ' ';
                        filing_signup_uname[uu] = ' ';
                    }
                    if (get_pos_mouse_sign_up.x >= 130 && get_pos_mouse_sign_up.x <= 330 && get_pos_mouse_sign_up.y >= 60 && get_pos_mouse_sign_up.y <= 85)
                    {
                        selectt.play();
                        username_indication = 0;
                        password_indication = 1;
                        confirmation_indication = 0;
                        email_indication = 0;
                        filing_signup_confirm[ucp] = ' ';
                        confirmpasswordstar[ucp] = ' ';
                        passwordstar[up] = '|';
                        filing_signup_email[ue] = ' ';
                        filing_signup_pass[up] = '|';
                        filing_signup_uname[uu] = ' ';
                    }
                    if (get_pos_mouse_sign_up.x >= 130 && get_pos_mouse_sign_up.x <= 330 && get_pos_mouse_sign_up.y >= 105 && get_pos_mouse_sign_up.y <= 130)
                    {
                        selectt.play();
                        username_indication = 0;
                        password_indication = 0;
                        confirmation_indication = 1;
                        email_indication = 0;
                        filing_signup_confirm[ucp] = '|';
                        confirmpasswordstar[ucp] = '|';
                        passwordstar[up] = ' ';
                        filing_signup_email[ue] = ' ';
                        filing_signup_pass[up] = ' ';
                        filing_signup_uname[uu] = ' ';
                    }
                    if (get_pos_mouse_sign_up.x >= 15 && get_pos_mouse_sign_up.x <= 345 && get_pos_mouse_sign_up.y >= 207 && get_pos_mouse_sign_up.y <= 247)
                    {
                        selectt.play();
                        if (sign_email == 1 && sign_username == 1 && sign_confirm_password == 1 && sign_password == 1)
                        {
                            register_indication = 1;
                            username_indication = 0;
                            password_indication = 0;
                            confirmation_indication = 0;
                            email_indication = 0;
                            int ehm;
                            char n[16], e[16], p[16];
                            string nn;
                            for (ehm = 0; ehm < uu; ehm++)
                            {
                                if (filing_signup_uname[ehm] != ' ')
                                {
                                    n[ehm] = filing_signup_uname[ehm];
                                }
                                else
                                {
                                    n[ehm] = '\0';
                                }
                            }
                            for (ehm = 0; ehm < uu; ehm++)
                            {
                                if (filing_signup_pass[ehm] == ' ')
                                {
                                    filing_signup_pass[ehm] = '\0';
                                    break;
                                }
                            }
                            for (ehm = 0; ehm < uu; ehm++)
                            {
                                if (filing_signup_email[ehm] == ' ')
                                {
                                    filing_signup_email[ehm] = '\0';
                                    break;
                                }
                            }
                            signing_up s1(filing_signup_uname, filing_signup_pass, filing_signup_email, in);

                            uuu = s1.existing_name_checking();
                            if (uuu == 0)
                            {
                                s1.putting_in_file();
                                window3.close();
                                return 0;

                            }

                        }
                    }
                    if (get_pos_mouse_sign_up.x >= 353 && get_pos_mouse_sign_up.x <= 353 + 174 && get_pos_mouse_sign_up.y >= 207 && get_pos_mouse_sign_up.y <= 247)
                    {
                        selectt.play();
                        cancel_req = 1;
                        window3.close();
                        return 0;
                    }
                }

                __uname_.setString(filing_signup_uname);
                __pass_.setString(passwordstar);
                __cpass_.setString(confirmpasswordstar);
                __email_.setString(filing_signup_email);
            }
            if (uuu == 1)
            {
                sign_up_failing_text.setFont(f1);
                sign_up_failing_text.setString("NAME ALREADY TAKEN!!! TRY ANOTHER!!!");
                sign_up_failing_text.setPosition(sf::Vector2f(12, 280));
                sign_up_failing_text.setFillColor(sf::Color::White);
                sign_up_failing_text.setCharacterSize(18);
            }
            if (username_indication == 1 || username_indication == 2)
            {
                if (uu < 3)
                {
                    at_least_three.setFont(f1);
                    at_least_three.setString("SHOULD CONTAIN AT LEAST THREE \n                      LETTERS!!!");
                    at_least_three.setPosition(sf::Vector2f(339, 7));
                    at_least_three.setFillColor(sf::Color::White);
                    at_least_three.setCharacterSize(17);
                    sign_username = 0;
                }
                if (uu >= 3)
                {
                    sign_username = 1;
                }
            }
            if (password_indication == 1)
            {
                if (up < 8)
                {
                    at_least_eight.setFont(f1);
                    at_least_eight.setString("SHOULD CONTAIN AT LEAST EIGHT \n                      LETTERS!!!");
                    at_least_eight.setPosition(sf::Vector2f(342, 53));
                    at_least_eight.setFillColor(sf::Color::White);
                    at_least_eight.setCharacterSize(17);
                    sign_password = 0;
                }
                if (up >= 8)
                {
                    sign_password = 1;
                }
            }
            if (confirmation_indication == 1)
            {

                for (int looop = 0; looop < strlen(filing_signup_confirm); looop++)
                {
                    if (filing_signup_confirm[looop] != '|')
                    {
                        check[looop] = filing_signup_confirm[looop];
                    }
                    else
                    {
                        check[looop] = ' ';
                    }
                }

                if (strcmp(check, filing_signup_pass) != 0)
                {

                    at_least_eight.setFont(f1);
                    at_least_eight.setString("PASSWORD UNMATCHED!!!");
                    at_least_eight.setPosition(sf::Vector2f(342, 98));
                    at_least_eight.setFillColor(sf::Color::White);
                    at_least_eight.setCharacterSize(22);
                    sign_confirm_password = 0;
                }
                if (strcmp(check, filing_signup_pass) == 0)
                {
                    sign_confirm_password = 1;
                }
            }

            if (email_indication == 1)
            {
                if (ue > 0)
                {
                    sign_email = 1;
                }
                if (ue == 0)
                {
                    sign_email = 0;
                }
            }
            Vector2i get_pos_mouse_sign_up = Mouse::getPosition(window3);
            if (get_pos_mouse_sign_up.x >= 35 && get_pos_mouse_sign_up.x <= 275 && get_pos_mouse_sign_up.y >= 207 && get_pos_mouse_sign_up.y <= 247)
            {
                _register_.setPosition(25, 47 + 155);
                _register_.setSize(Vector2f(250, 50));
            }
            else
            {
                _register_.setPosition(sf::Vector2f(35, 52 + 155));
                _register_.setSize(Vector2f(240, 40));
            }
            if (get_pos_mouse_sign_up.x >= 353 && get_pos_mouse_sign_up.x <= 353 + 174 && get_pos_mouse_sign_up.y >= 207 && get_pos_mouse_sign_up.y <= 247)
            {
                _cancel_.setPosition(sf::Vector2f(343, 47 + 155));
                _cancel_.setSize(Vector2f(184, 50));
            }
            else
            {
                _cancel_.setSize(Vector2f(174, 40));
                _cancel_.setPosition(sf::Vector2f(353, 52 + 155));
            }

            window3.clear();
            window3.draw(recc);
            window3.draw(_cancel_);
            window3.draw(_register_);
            window3.draw(sign_up_failing_text);
            window3.draw(__uname_);
            window3.draw(__pass_);
            window3.draw(__cpass_);
            window3.draw(__email_);
            window3.draw(at_least_three);
            window3.draw(at_least_eight);
            window3.display();
        }
    }
};
class logging_in
{
    info* in;
    char name_info[16];
    char pass_info[16];
    shop* sh;
public:
    int llogging_in(char* name_infoo, char* pass_infoo, info* inn, shop* shh)
    {

        for (int i = 0; i < 16; i++)
        {
            name_info[i] = '\0';
            pass_info[i] = '\0';
        }
        strcpy_s(name_info, name_infoo);
        strcpy_s(pass_info, pass_infoo);
        this->in = inn;
        sh = shh;
        in->setname(name_infoo);
        in->setpassword(pass_infoo);
        int yy = reading_from_file();
        return yy;
    }
    int reading_from_file()
    {
        ifstream getting;
        getting.open("information.txt");
        if (!getting)
        {
            cout << "ERROR WHILE LOGGING IN!!!";
            exit(1);
        }
        char ch[16] = "               ", nnn[16], nnn2[16];

        int ii = 0;
        for (ii = 0; ii < 16; ii++)
        {
            nnn[ii] = '\0';
            nnn2[ii] = '\0';
        }
        for (ii = 0; ii < 16; ii++)
        {
            if (name_info[ii] != ' ' && name_info[ii] != '|')
            {
                nnn[ii] = name_info[ii];
            }
        }
        for (ii = 0; ii < 16; ii++)
        {
            if (pass_info[ii] != ' ' && pass_info[ii] != '|')
            {
                nnn2[ii] = pass_info[ii];
            }
        }

        ii = 0;
        int for_checking_password = 0, signature = 0;
        while (getting >> ch)
        {
            if (for_checking_password + 1 == ii && signature == 1)
            {
                if (strcmp(nnn2, ch) == 0)
                {
                    getting.close();
                    saving_global_variables_for_logout(ii);
                    return 1;
                }
            }
            if ((ii % 10) == 0)
            {

                int lent = strlen(nnn);
                if (strcmp(nnn, ch) == 0)
                {
                    for_checking_password = ii;
                    signature = 1;
                }
            }
            ii++;
        }
        getting.close();
        return 0;
    }
    void saving_global_variables_for_logout(int ii)
    {
        int i;
        ifstream getting;
        getting.open("information.txt");
        if (!getting)
        {
            cout << "ERROR WHILE LOGGING IN!!!";
            exit(1);
        }
        char ch[16];
        for (i = 0; i < 16; i++) ch[i] = '\0';
        i = 0;
        int sign_arriving = 0, incrementing = 0;;
        while (getting >> ch)
        {
            if (i == ii)
            {
                sign_arriving = ii;
            }
            if (sign_arriving + 1 == i)
            {
                in->setemail(ch);
            }
            if (sign_arriving + 2 == i)
            {
                in->setcoins(fun_for_returning_integer_value(ch, strlen(ch)));
            }
            if (sign_arriving + 3 == i)
            {
                in->setbought1(fun_for_returning_integer_value(ch, strlen(ch)));
            }
            if (sign_arriving + 4 == i)
            {
                in->setbought2(fun_for_returning_integer_value(ch, strlen(ch)));
            }
            if (sign_arriving + 5 == i)
            {
                in->setlastcharacter1(fun_for_returning_integer_value(ch, strlen(ch)));
            }
            if (sign_arriving + 6 == i)
            {
                in->setlastcharacter2(fun_for_returning_integer_value(ch, strlen(ch)));
            }
            if (sign_arriving + 7 == i)
            {
                in->setlastcharacter3(fun_for_returning_integer_value(ch, strlen(ch)));
            }
            if (sign_arriving + 8 == i)
            {
                in->setscore(fun_for_returning_integer_value(ch, strlen(ch)));
            }
            i++;
        }
        sh->setinfo(in);
        sh->settinginfo();
    }
};
void logging_out(info& lg)
{
    logging_in llg;
    ifstream purpose_reading;
    ofstream purpose_writing;
    purpose_reading.open("information.txt");
    purpose_writing.open("information2.txt");
    if (!purpose_reading)
    {
        cout << "ERROR WHILE OPENING FILE!!!";
        exit(1);
    }
    if (!purpose_writing)
    {
        cout << "ERROR WHILE OPENING FILE!!!";
        exit(1);
    }
    char ch[16];
    int iii = 0;
    int ii = 0;
    char nnn[16], nnn2[16], nnn3[16];
    for (ii = 0; ii < 16; ii++)
    {
        nnn[ii] = '\0';
        nnn2[ii] = '\0';
        nnn3[ii] = '\0';
    }
    char* name_info, * pass_info, * email_info;
    name_info = lg.getname();
    pass_info = lg.getpassword();
    email_info = lg.getemail();
    for (ii = 0; ii < 16; ii++)
    {
        if (name_info[ii] != ' ' && name_info[ii] != '|')
        {
            nnn[ii] = name_info[ii];
        }
    }
    for (ii = 0; ii < 16; ii++)
    {
        if (pass_info[ii] != ' ' && pass_info[ii] != '|')
        {
            nnn2[ii] = pass_info[ii];
        }

    }
    for (ii = 0; ii < 16; ii++)
    {
        if (email_info[ii] != ' ' && email_info[ii] != '|')
        {
            nnn3[ii] = email_info[ii];
        }
    }
    int yo = 0, ccc = 0;
    while (purpose_reading >> ch)
    {
        if (iii % 10 == 0)
        {
            if (strcmp(nnn, ch) == 0)
            {
                purpose_writing << nnn << " " << nnn2 << " " << email_info << " " << lg.getcoins() << " " << lg.getcharacterbought1() << " " << lg.getcharacterbought2() << " " << lg.getlastcharater1() << " " << lg.getlastcharater2() << " " << lg.getlastcharater3() << " " << lg.getscore();
                yo = 1;
                ccc = 12;
            }
            else
            {
                if (iii != 0)
                {
                    purpose_writing << '\n';
                }
                purpose_writing << ch << " ";
            }

        }
        if (yo == 0 && iii % 10 != 0)
        {
            if (ccc == 0 || ccc == 1)
            {
                purpose_writing << ch << " ";
            }
        }
        if (yo == 1)
        {
            ccc--;
        }
        if (ccc == 1)
        {
            yo = 0;
        }
        iii++;
    }

    purpose_reading.close();
    remove("information.txt");
    purpose_writing.close();
    rename("information2.txt", "information.txt");
}
class Menu
{
    RectangleShape rec1, rec2, rec3, rec4;
    Texture tex1, tex2, tex3, tex4;
    RenderWindow* w, window2;
    int sign, logoutsign;
    info* in;
    SoundBuffer buffer;
    Sound sound;

public:
    Menu(RenderWindow* w2, info* in)
    {
        this->in = in;
        buffer.loadFromFile("sellect.wav");
        sound.setBuffer(buffer);
        tex1.loadFromFile("Menupage.png");
        tex2.loadFromFile("Start.png");
        tex3.loadFromFile("Shop.png");
        tex4.loadFromFile("Logout.png");
        rec1.setTexture(&tex1);
        rec2.setTexture(&tex2);
        rec3.setTexture(&tex3);
        rec1.setPosition(0, 0);
        rec2.setPosition(500, 260);
        rec3.setPosition(500, 400);
        rec1.setSize(Vector2f(1400, 700));
        rec2.setSize(Vector2f(300, 120));
        rec3.setSize(Vector2f(300, 120));
        rec4.setTexture(&tex4);
        rec4.setPosition(4, 40);
        rec4.setSize(Vector2f(200, 100));
        w = w2;
        sign = 0, logoutsign = 0;;
    }
    void Display()
    {
        Vector2i v1 = Mouse::getPosition(*w);
        sign = 0;
        if ((v1.x >= 500 && v1.x <= 800) && (v1.y >= 260 && v1.y <= 380))
        {
            rec2.setSize(Vector2f(330, 150));
            tex2.loadFromFile("Started.png");
            rec2.setTexture(&tex2);
            rec2.setPosition(490, 250);
        }
        else
        {
            rec2.setSize(Vector2f(300, 120));
            tex2.loadFromFile("Start.png");
            rec2.setTexture(&tex2);
            rec2.setPosition(500, 260);
        }
        if ((v1.x >= 500 && v1.x <= 800) && (v1.y >= 400 && v1.y <= 520))
        {
            rec3.setSize(Vector2f(330, 150));
            tex3.loadFromFile("Shoped.png");
            rec3.setTexture(&tex3);
            rec3.setPosition(490, 390);
        }
        else
        {
            rec3.setSize(Vector2f(300, 120));
            tex3.loadFromFile("Shop.png");
            rec3.setTexture(&tex3);
            rec3.setPosition(500, 400);
        }
        if ((v1.x >= 4 && v1.x <= 204) && (v1.y >= 40 && v1.y <= 140))
        {
            rec4.setPosition(-4, 30);
            rec4.setSize(Vector2f(230, 120));
        }
        else
        {
            rec4.setPosition(4, 40);
            rec4.setSize(Vector2f(200, 100));
        }
    }
    int Transition()
    {
        Vector2i v1 = Mouse::getPosition(*w);
        if (Mouse::isButtonPressed(Mouse::Right))
        {
            if ((v1.x >= 4 && v1.x <= 204) && (v1.y >= 40 && v1.y <= 140))
            {
                sound.play();
                logoutsign = log();
                if (logoutsign == 1)
                {
                    logging_out(*in);
                    exit(0);
                }
                else return 0;
            }

        }
        if (Mouse::isButtonPressed(Mouse::Right))
        {
            sound.play();
            if ((v1.x >= 500 && v1.x <= 800) && (v1.y >= 400 && v1.y <= 520))
            {
                return 1;
            }
            if ((v1.x >= 500 && v1.x <= 800) && (v1.y >= 260 && v1.y <= 380))
            {
                return 2;
            }
        }
        //  return sign;
    }
    int log()
    {
        window2.create(sf::VideoMode(550, 380), "", Style::None);
        Texture txx1, yesop, noop;
        txx1.loadFromFile("leaving1.png");
        yesop.loadFromFile("right.png");
        noop.loadFromFile("wrong.png");
        RectangleShape background1(Vector2f(550, 380)), yesoption(Vector2f(100, 100)), nooption(Vector2f(100, 100));
        background1.setPosition(0, 0);
        Event e1;
        background1.setTexture(&txx1);
        yesoption.setTexture(&yesop);
        nooption.setTexture(&noop);
        yesoption.setPosition(150, 170);
        nooption.setPosition(300, 170);
        int signer = 0;
        while (window2.isOpen())
        {

            Vector2i mousi = Mouse::getPosition(window2);
            if ((mousi.x >= 100 && mousi.x <= 200) && (mousi.y >= 170 && mousi.y <= 270))
            {
                yesoption.setPosition(95, 165);
                yesoption.setSize(Vector2f(115, 115));
            }
            else if ((mousi.x >= 350 && mousi.x <= 450) && (mousi.y >= 170 && mousi.y <= 270))
            {
                nooption.setPosition(345, 165);
                nooption.setSize(Vector2f(115, 115));
            }
            else
            {
                yesoption.setPosition(100, 170);
                yesoption.setSize(Vector2f(100, 100));
                nooption.setPosition(350, 170);
                nooption.setSize(Vector2f(100, 100));
            }
            while (window2.pollEvent(e1))
            {
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    if ((mousi.x >= 100 && mousi.x <= 200) && (mousi.y >= 170 && mousi.y <= 270))
                    {
                        sound.play();
                        signer = 1;
                        window2.close();
                    }
                    else if ((mousi.x >= 350 && mousi.x <= 450) && (mousi.y >= 170 && mousi.y <= 270))
                    {
                        sound.play();
                        window2.close();
                    }
                }
            }
            window2.draw(background1);
            window2.draw(yesoption);
            window2.draw(nooption);
            window2.display();
        }
        return signer;
    }
    void Output()
    {
        w->clear();
        w->draw(rec1);
        w->draw(rec2);
        w->draw(rec3);
        w->draw(rec4);
        w->display();

    }
};
class mainpage
{
    Font f1;
    Text login_failing_text, sign_up_failing_text;
    int sign, var_us_name, var_pass, count, i, ii, f_time;
    RectangleShape  sign_up, login, recc, * player;
    Texture back, playerTexture2, loginn, signupp;
    int loginfail;
    char username_input_login[16] = "|              ", username_input_password[16] = "               ", starforpassword[16] = "              ";
    char nmc[21];
    RenderWindow window2, * window;
    Event event;
    signupwindow www;
    logging_in lg;
    info* in;
    SoundBuffer buff, select;
    Sound sound, selectt;
    shop* sh;
public:
    mainpage(RenderWindow* windoww, RectangleShape* player, info* in, shop* shh)
    {
        sh = shh;
        this->in = in;
        www.infoo(in);
        buff.loadFromFile("keyboard.wav");
        select.loadFromFile("Sellect1.wav");
        selectt.setBuffer(select);
        sound.setBuffer(buff);
        this->window = windoww;
        this->player = player;
        f1.loadFromFile("username1.ttf");
        login_failing_text.setFont(f1);
        login_failing_text.setString("INCORRECT USERNAME OR PASSWORD....TRY AGAIN!!!");
        login_failing_text.setPosition(sf::Vector2f(12, 375));
        login_failing_text.setFillColor(sf::Color::White);
        login_failing_text.setCharacterSize(18);
        sign = 0, var_us_name = 2, var_pass = 0, count = 0, i = 0, ii = 0, f_time = 0;
        loginn.loadFromFile("login.png");
        login.setTexture(&loginn);
        signupp.loadFromFile("signup.png");
        sign_up.setTexture(&signupp);
        sign_up.setSize(sf::Vector2f(330, 52)), login.setSize(sf::Vector2f(330, 52)), recc.setSize(Vector2f(350, 420));
        recc.setPosition(0, 0);
        back.loadFromFile("fire2.png");
        recc.setTexture(&back);
        loginfail = 0;
        nmc[0] = 'N', nmc[1] = 'O', nmc[2] = ' ', nmc[3] = 'M', nmc[4] = 'O', nmc[5] = 'R', nmc[6] = 'E', nmc[7] = ' ', nmc[8] = 'C', nmc[9] = 'H', nmc[10] = 'A';
        nmc[11] = 'R', nmc[12] = 'A', nmc[13] = 'C', nmc[14] = 'T', nmc[15] = 'E', nmc[16] = 'R', nmc[17] = 'S', nmc[18] = '!', nmc[19] = '!', nmc[20] = '!';
        window2.create(sf::VideoMode(350, 420), "", sf::Style::Close | sf::Style::Resize);
    }
    int  displayy()
    {
        int zz = 0;
        while (window2.isOpen())
        {
            sign = 1;
            playerTexture2.loadFromFile("escaperun2.png");
            player->setTexture(&playerTexture2);
            window2.clear(sf::Color::Black);
            window->draw(*player);
            window->display();

            sf::Text  no_more_characters;
            no_more_characters.setFont(f1);
            no_more_characters.setString(nmc);
            no_more_characters.setPosition(sf::Vector2f(105, 110));
            no_more_characters.setFillColor(sf::Color::White);
            no_more_characters.setCharacterSize(20);
            sf::Text u_name_for_login, u_name_for_password;
            u_name_for_login.setPosition(sf::Vector2f(138, 10));
            u_name_for_login.setFont(f1);
            u_name_for_login.setFillColor(sf::Color::Black);
            u_name_for_password.setPosition(sf::Vector2f(138, 61));
            u_name_for_password.setFont(f1);
            u_name_for_password.setFillColor(sf::Color::Black);
            sf::Vector2i get_pos_mouse;
            get_pos_mouse = sf::Mouse::getPosition(window2);
            while (window2.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    sign = 0;
                    window2.close();


                }
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    if ((get_pos_mouse.x >= 15 && get_pos_mouse.x <= 320 && get_pos_mouse.y >= 300 && get_pos_mouse.y <= 340)) //Login button
                    {
                        selectt.play();
                        int uu = lg.llogging_in(username_input_login, username_input_password, in, sh);
                        if (uu != 1)
                        {
                            loginfail = 1;
                        }
                        else if (uu == 1)
                        {
                            sign = 5;
                            window2.close();


                        }
                    }
                    if ((get_pos_mouse.x >= 15 && get_pos_mouse.x <= 320 && get_pos_mouse.y >= 200 && get_pos_mouse.y <= 240)) //signup button
                    {
                        selectt.play();
                        window2.close();
                        www.windoww();
                        zz = www.transition();
                        if (zz == 0)
                            sign = 0;
                    }
                    if ((get_pos_mouse.x >= 200 && get_pos_mouse.x <= 335 && get_pos_mouse.y >= 18 && get_pos_mouse.y <= 43))
                    {
                        selectt.play();
                        if (event.type == sf::Event::MouseButtonPressed)
                        {
                            var_pass = 0;
                            var_us_name = 1;
                            username_input_password[ii] = ' ';
                            username_input_login[i] = '|';
                        }
                    }
                    if ((get_pos_mouse.x >= 200 && get_pos_mouse.x <= 335 && get_pos_mouse.y >= 68 && get_pos_mouse.y <= 92))
                    {
                        selectt.play();
                        if (event.type == sf::Event::MouseButtonPressed)
                        {
                            var_pass = 1;
                            var_us_name = 0;
                            username_input_login[i] = ' ';
                            username_input_password[ii] = '|';
                        }
                    }
                }
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::BackSpace)
                    {
                        if (var_us_name == 1 || var_us_name == 2)
                        {
                            if (i > 0)
                            {
                                username_input_login[i] = ' ';
                                i--;
                                username_input_login[i] = '|';
                            }
                        }
                        else if (var_pass == 1)
                        {
                            if (ii > 0)
                            {
                                username_input_password[ii] = ' ';
                                starforpassword[ii] = ' ';
                                ii--;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        if (f_time == 0)
                        {
                            username_input_password[ii] = '|';
                            starforpassword[ii] = '|';
                        }
                        username_input_login[i] = ' ';
                        var_us_name = 0;
                        var_pass = 1;
                    }
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        username_input_login[i] = '|';
                        username_input_password[ii] = ' ';
                        starforpassword[ii] = ' ';
                        var_us_name = 1;
                        var_pass = 0;
                    }

                    if ((var_pass == 1 && ii < 14) || ((var_us_name == 1 || var_us_name == 2) && i < 14))
                    {
                        if (event.key.code == sf::Keyboard::Space)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = ' ';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = ' ';
                                starforpassword[ii] = ' ';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::A)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'a';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'a';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::B)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'b';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'b';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::C)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'c';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'c';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::D)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'd';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'd';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::E)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'e';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'e';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::F)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'f';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'f';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::G)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'g';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'g';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::H)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'h';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'h';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::I)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'i';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'i';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::J)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'j';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'j';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::K)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'k';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'k';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::L)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'l';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'l';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::M)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'm';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'm';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::N)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'n';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'n';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::O)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'o';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'o';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::P)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'p';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'p';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::Q)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'q';
                                i++;
                                username_input_login[i] = '|';

                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'q';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::R)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'r';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'r';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::S)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 's';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 's';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::T)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 't';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 't';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::U)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'u';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'u';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::V)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'v';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'v';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::W)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'w';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'w';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::X)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'x';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'x';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::Y)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'y';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'y';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        if (event.key.code == sf::Keyboard::Z)
                        {
                            if (var_us_name == 1 || var_us_name == 2)
                            {
                                username_input_login[i] = 'z';
                                i++;
                                username_input_login[i] = '|';
                            }
                            else if (var_pass == 1)
                            {
                                username_input_password[ii] = 'z';
                                starforpassword[ii] = '*';
                                ii++;
                                username_input_password[ii] = '|';
                                starforpassword[ii] = '|';
                            }
                        }
                        sound.play();
                    }
                }
            }
            u_name_for_password.setString(starforpassword);
            u_name_for_login.setString(username_input_login);
            if ((var_pass == 1 && ii == 14) || ((var_us_name == 1 || var_us_name == 2) && i == 14))
            {
                window2.draw(no_more_characters);
            }
            if ((get_pos_mouse.x >= 10 && get_pos_mouse.x <= 340 && get_pos_mouse.y >= 294 && get_pos_mouse.y <= 346))
            {
                login.setPosition(sf::Vector2f(2, 289));
                login.setSize(sf::Vector2f(345, 52 + 15));
            }
            else
            {
                login.setPosition(sf::Vector2f(10, 294));
                login.setSize(sf::Vector2f(330, 52));
            }
            if ((get_pos_mouse.x >= 10 && get_pos_mouse.x <= 340 && get_pos_mouse.y >= 194 && get_pos_mouse.y <= 246))
            {
                sign_up.setPosition(sf::Vector2f(2, 189));
                sign_up.setSize(sf::Vector2f(345, 52 + 15));
            }
            else
            {
                sign_up.setPosition(sf::Vector2f(10, 194));
                sign_up.setSize(sf::Vector2f(330, 52));
            }
            window2.draw(recc);
            window2.draw(login);
            window2.draw(sign_up);
            window2.draw(u_name_for_login);
            window2.draw(u_name_for_password);
            if (loginfail == 1)
                window2.draw(login_failing_text);
            window2.display();
        }

        return sign;
    }
};
int main()
{
    int t = 1, l;
    int left = 1;
    int right = 0;
    int i = 0, s = 0, s1 = 0;
    SoundBuffer* buffer;
    buffer = new SoundBuffer;
    buffer->loadFromFile("intro.wav");
    Sound sound;
    sound.setBuffer(*buffer);
    sound.setVolume(10);
    sound.play();
    RenderWindow window(VideoMode::getDesktopMode(), "ESCAPE RUN");

    info in;
    shop sh(&window);
    Menu men(&window, &in);
    RectangleShape player(Vector2f(1400, 700));
    player.setPosition(0, 0);
    Texture playerTexture;
    playerTexture.loadFromFile("escaperun.png");
    player.setTexture(&playerTexture);
    game ggg;
    int ret = 0, z = 0;
    Event event;
    sf::Texture texture;
    sf::Vector2i source(0, 0);


    static int aa = 0;
    static int dd = 0;
    static int bb11 = 0;
    sf::Sprite sp;






    Mouvment mouvment;
    int temp = 0, z1 = 0;

    while (window.isOpen())
    {
        window.clear(sf::Color::Blue);

        if (ret == 5)
        {

            if (i == 1)
                sh.Display();
            if (i == 0)
            {
                men.Display();
                if (s1 == 0)
                {
                    buffer->loadFromFile("wig.wav");
                    sound.setBuffer(*buffer);
                    sound.play();

                }
                s1 = 1;
                sound.setLoop(true);
            }
            if (i == 2)
            {
                if (s == 0)
                {
                    l = in.get();

                    if (l == 0)
                    {
                        texture.loadFromFile("character1.png");
                    }
                    else if (l == 1)
                    {
                        texture.loadFromFile("character2.png");
                    }
                    else if (l == 2)
                    {
                        texture.loadFromFile("character3.png");
                    }


                    sp.setTexture(texture);
                    sp.setOrigin(-400, -600);
                    t = 0;
                    ggg.stgame(&window);
                    buffer->loadFromFile("blindinglights.wav");
                    sound.setBuffer(*buffer);
                    sound.play();
                    ggg.setinfo(&in);
                }

                z1 = ggg.Startgame(sp, source, aa);
                s = 1;
                if (z1 == 1)
                {
                    i = 0;
                    s = 0;
                    s1 = 0;
                    i = 0;
                    z = 0;
                    z1 = 1;
                }

            }
        }
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();


            switch (event.type)
            {

            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Right:
                    if (right == 0)
                    {
                        mouvment.goDirection(0, sp);
                        left = 0;
                        right = 1;
                    }
                    temp = 1;

                    break;
                case sf::Keyboard::Left:
                    if (left == 0)
                    {
                        mouvment.goDirection(1, sp);
                        right = 0;
                        left = 1;
                    }
                    temp = 1;

                    break;
                case sf::Keyboard::Up:
                    //mouvment.goDirection(2, sp);

                    if (aa == 0)
                    {
                        aa = 1;
                    }

                    break;


                }


            }

        }
        if (aa > 0 && aa < 100)
        {
            mouvment.goDirection(2, sp);

            aa = aa + 1;
            bb11 = 1;
        }
        else if (bb11 > 0 && bb11 < 100)
        {

            mouvment.goDirection(3, sp);

            bb11 = bb11 + 1;

        }
        else
        {
            bb11 = 0;
            aa = 0;
        }


        //w.clear(Color::Blue);


        if (ret != 5)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                mainpage mm(&window, &player, &in, &sh);
                ret = mm.displayy();
            }
        }
        if (ret == 5)
        {
            if (event.type == Event::EventType::Closed)
                window.close();
            if (i == 1)
                i = sh.Transition();
            if (i == 0)
                i = men.Transition();
            if (i == 2)
            {

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    //  z = 0;
                    z = ggg.transition();

                    if (z == 1)
                    {
                        i = 0;
                        s = 0;
                        s1 = 0;
                        i = 0;
                        z = 0;
                    }
                }
            }

        }


        static int x5 = 0;
        static int y5 = 0;
        static int aaaa = 1;




        static int count = 0;
        count++;

        if (count % 70 == 1)
        {
            if (x5 == 0)
            {
                aaaa = 1;
            }
            else if (x5 == 4)
            {
                aaaa = -1;
            }
            source.x = x5;
            source.y = y5;
            x5 = x5 + aaaa;
        }


        if (ret == 5)
        {
            if (i == 1)
                sh.damdam();
            if (i == 0)
                men.Output();
        }
        if (ret != 5)
        {
            playerTexture.loadFromFile("escaperun.png");
            player.setTexture(&playerTexture);
            window.draw(player);
            window.display();
        }
    }
}