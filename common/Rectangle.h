struct Rectangle {
    int x1;
    int x2;
    int y1;
    int y2;

    Rectangle();
    Rectangle(int x1, int x2, int y1, int y2);

    void move(const int xdist, const int ydist);
    bool collides(const Rectangle &other) const;
    bool in_shoot_range(const Rectangle &shooter) const;
};