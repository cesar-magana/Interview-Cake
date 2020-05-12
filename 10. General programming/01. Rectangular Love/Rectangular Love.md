# Rectangular Love

**A crack team of love scientists from OkEros (a hot new dating site) have devised a way to represent dating profiles as rectangles on a two-dimensional plane.**

**They need help writing an algorithm to find the intersection of two users' love rectangles.** They suspect finding that intersection is the key to a matching algorithm *so powerful* it will cause an immediate acquisition by Google or Facebook or Obama or something.

![Two rectangles overlapping a little. It must be love.](https://www.interviewcake.com/images/svgs/rectangular_love__it_must_be_love.svg?bust=205)

**Write a function to find the rectangular intersection of two given love rectangles.**

As with the example above, love rectangles are always "straight" and never "diagonal." More rigorously: each side is parallel with either the x-axis or the y-axis.

They are defined as instances of the Rectangle class:

```cpp
class Rectangle
{
private:
    // coordinates of bottom left corner
    int leftX_;
    int bottomY_;

    // dimensions
    int width_;
    int height_;

public:
    Rectangle() :
        leftX_(0),
        bottomY_(0),
        width_(0),
        height_(0)
    {
    }

    Rectangle(int leftX, int bottomY, int width, int height) :
        leftX_(leftX),
        bottomY_(bottomY),
        width_(width),
        height_(height)
    {
    }

    int getLeftX() const
    {
        return  leftX_;
    }

    int getBottomY() const
    {
        return  bottomY_;
    }

    int getWidth() const
    {
        return  width_;
    }

    int getHeight() const
    {
        return  height_;
    }

    bool operator==(const Rectangle& other) const
    {
        return
            leftX_ == other.leftX_
            && bottomY_ == other.bottomY_
            && width_ == other.width_
            && height_ == other.height_;
    }

    bool operator!=(const Rectangle& other) const
    {
        return !(*this == other);
    }
};
```



Your output rectangle should be a Rectangle object as well.