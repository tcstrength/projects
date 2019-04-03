#ifndef WIDGET_H
#define WIDGET_H

#include "../Context.h"
#include "../Renderers/RoundedRectangleShape.h"

class Widget
{
public:
    enum State {
        PRELIGHT = 1,
        SELECTED = 2,
        FOCUSED = 4
    };

    Widget(Context& context);

    virtual ~Widget() {}

    virtual void handleEvents();

    virtual void draw();

    const uint& getState() const;

    bool stateIsOn(const State& state);

    void onState(const State& state);

    void offState(const State& state);

    const sf::Vector2f& getPosition() const;

    void setPosition(const sf::Vector2f& position);

    const sf::Vector2f& getSize() const;

    void setSize(const sf::Vector2f& size);

    void setWidth(float width);

    void setHeight(float height);

    const sf::String& getTextString() const;

    void setTextString(const sf::String& textString);

    const uint& getTextSize() const;

    void setTextSize(const uint& textSize);

    const uint& getBorderRadius() const;

    void setBorderRadius(const uint& borderRadius);

    const uint& getBorderSize() const;

    void setBorderSize(const uint& borderSize);

    const sf::Vector2f& getPadding() const;

    void setPadding(uint leftRight, int topBot = -1);

    const sf::Color& getBorderColor() const;

    void setBorderColor(const sf::Color& borderColor);

    const sf::Color& getBackgroundColor() const;

    void setBackgroundColor(const sf::Color& backgroundColor);

    const sf::Color& getTextColor() const;

    void setTextColor(const sf::Color& textColor);

    bool wasPressed();

protected:

    virtual void updateState() = 0;

    void update();

    void centerText();

    bool hitWidget();

    Context&        m_context;
    uint            m_borderRadius;
    uint            m_borderSize;
    sf::Vector2f    m_padding;
    sf::Vector2f    m_position;
    sf::Vector2f    m_size;
    sf::String      m_textString;
    uint            m_textSize;
    sf::Color       m_borderColor;
    sf::Color       m_backgroundColor;
    sf::Color       m_textColor;

private:
    uint            m_state;
    uint            m_oldState;
    bool            m_wasPressed;
    sf::Text        m_text;
    sf::RoundedRectangleShape
                    m_background;
};

#endif // WIDGET_H
