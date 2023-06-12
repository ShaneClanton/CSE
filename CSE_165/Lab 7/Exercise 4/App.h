#ifndef APP_H
#define APP_H

#include <iostream>

using namespace std;

class Rect {
public:
    Rect() : x(0), y(0), w(0), h(0) {}
    Rect(float _x, float _y, float _w, float _h) : x(_x), y(_y), w(_w), h(_h) {}

    float x, y, w, h;
};

class AppWindow {
protected:
    Rect rect;

public:
    AppWindow() : rect(Rect()) {}
    AppWindow(float x, float y, float w, float h) : rect(Rect(x, y, w, h)) {}
    AppWindow(const Rect& r) : rect(r) {}

    const Rect& get_rect() {
        return rect;
    }

    virtual void resize(int w, int h) {
        rect.w = w;
        rect.h = h;
    }
};

class CircleWin : public AppWindow {
protected:
    float radius;

public:
    CircleWin() : AppWindow(), radius(0) {}
    CircleWin(float x, float y, float w, float h) : AppWindow(x, y, w, h) {
        radius = max(w, h);
    }
    CircleWin(const Rect& r) : AppWindow(r) {
        radius = max(rect.w, rect.h);
    }

    void resize(int w, int h) override {
        AppWindow::resize(w, h);
        radius = max(w, h);
        cout << "radius: " << radius << endl;
    }
};

class RectWin : public AppWindow {
protected:
    float area;

public:
    RectWin() : AppWindow(), area(0) {}
    RectWin(float x, float y, float w, float h) : AppWindow(x, y, w, h) {
        area = w * h;
    }
    RectWin(const Rect& r) : AppWindow(r) {
        area = rect.w * rect.h;
    }

    void resize(int w, int h) override {
        AppWindow::resize(w, h);
        area = w * h;
        cout << "area: " << area << endl;
    }
};

#endif
