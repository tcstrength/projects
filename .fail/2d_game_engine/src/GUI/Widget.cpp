#include "Widget.h"

Widget::Widget(Context& context)
:   m_context(context)
,   m_borderRadius(0)
,   m_borderSize(0)
,   m_padding({0, 0})
,   m_position(sf::Vector2f(0.f, 0.f))
,   m_size({0, 0})
,   m_textString("Example")
,   m_textSize(0)
,   m_borderColor(sf::Color(0))
,   m_backgroundColor(sf::Color(0))
,   m_textColor(sf::Color(0))
,   m_state(0)
,   m_oldState(0)
,   m_wasPressed(false)
{
    update();
}

const sf::Color& Widget::getTextColor() const
{
    return m_textColor;
}

void Widget::setTextColor(const sf::Color& textColor)
{
    m_textColor = textColor;
    update();
}

bool Widget::wasPressed()
{
    return m_wasPressed;
}

const sf::Color& Widget::getBackgroundColor() const
{
    return m_backgroundColor;
}

void Widget::setBackgroundColor(const sf::Color& backgroundColor)
{
    m_backgroundColor = backgroundColor;
    update();
}

const sf::Color& Widget::getBorderColor() const
{
    return m_borderColor;
}

void Widget::setBorderColor(const sf::Color& borderColor)
{
    m_borderColor = borderColor;
    update();
}

const sf::Vector2f& Widget::getPadding() const
{
    return m_padding;
}

void Widget::setPadding(uint leftRight, int topBot)
{
    if (topBot < 0)
        topBot = leftRight;

    m_padding.x = leftRight;
    m_padding.y = topBot;
    update();
}

const uint& Widget::getBorderSize() const
{
    return m_borderSize;
}

void Widget::setBorderSize(const uint& borderSize)
{
    m_borderSize = borderSize;
    update();
}

const uint& Widget::getBorderRadius() const
{
    return m_borderRadius;
}

void Widget::setBorderRadius(const uint& borderRadius)
{
    m_borderRadius = borderRadius;
    update();
}

const uint& Widget::getTextSize() const
{
    return m_textSize;
}

void Widget::setTextSize(const uint& textSize)
{
    m_textSize = textSize;
    update();
}

const sf::String& Widget::getTextString() const
{
    return m_textString;
}

void Widget::setTextString(const sf::String& textString)
{
    m_textString = textString;
    update();
}

const sf::Vector2f& Widget::getSize() const
{
    return m_size;
}

void Widget::setSize(const sf::Vector2f& size)
{
    m_size = size;
    update();
}

void Widget::setWidth(float width)
{
    m_size.x = width;
    update();
}

void Widget::setHeight(float height)
{
    m_size.y = height;
    update();
}

const sf::Vector2f& Widget::getPosition() const
{
    return m_position;
}

void Widget::setPosition(const sf::Vector2f& position)
{
    m_position = position;
    update();
}

const uint& Widget::getState() const
{
    return m_state;
}

bool Widget::stateIsOn(const Widget::State& state)
{
    return m_state & state;
}

void Widget::onState(const State& state)
{
    m_oldState = m_state;
    m_state |= state;

    if (state == State::FOCUSED)
    {
        /// \todo onFocus.send()
    }

    if (m_oldState != m_state)
    {
        updateState();
        /// \todo onStateChange.send()
    }
}

void Widget::offState(const State &state)
{
    m_oldState = m_state;
    m_state &= ~state;

    if (state == State::FOCUSED)
    {
        /// \todo onUnfocus.send()
    }

    if (m_oldState != m_state)
    {
        updateState();
        /// \todo onStateChange.send()
    }
}

void Widget::draw()
{
    m_context.window.draw(m_background);
    m_context.window.draw(m_text);
}

void Widget::handleEvents()
{
    m_wasPressed = false;

    switch(m_context.event.type)
    {
        case sf::Event::MouseMoved:
            if (hitWidget())
            {
                onState(State::PRELIGHT);
                /// \todo onMouseEnter.send();
            }
            else
            {
                offState(State::PRELIGHT);
                /// \todo onMouseLeave.send();
            }
            break;

        case sf::Event::MouseButtonPressed:
            if (stateIsOn(State::PRELIGHT))
            {
                if (m_context.event.mouseButton.button == sf::Mouse::Left)
                {
                    onState(State::SELECTED);
                    onState(State::FOCUSED);
                    /// \todo onLeftMousePress.send();
                }
                else if (m_context.event.mouseButton.button == sf::Mouse::Right)
                {
                    /// \todo onRightMousePress.send();
                }
            }
            else
            {
                offState(State::FOCUSED);
            }

            break;

        case sf::Event::MouseButtonReleased:

            if (stateIsOn(State::PRELIGHT) && stateIsOn(State::SELECTED))
            {
                if (m_context.event.mouseButton.button == sf::Mouse::Left)
                {
                    /// \todo onLeftMouseRelease.send();

                    m_wasPressed = true;
                }
                else if (m_context.event.mouseButton.button == sf::Mouse::Right)
                {
                    /// \todo onRightMouseRelease.send();
                }
            }

            offState(State::SELECTED);
            break;

        default:
            break;
    }
}

void Widget::update()
{
    m_background.setSize(m_size);
    m_background.setPosition(m_position);
    m_background.setFillColor(m_backgroundColor);
    m_background.setCornersRadius(m_borderRadius);
    m_background.setCornerPointCount(m_borderRadius);
    m_background.setOutlineThickness(m_borderSize);
    m_background.setOutlineColor(m_borderColor);

    m_text.setPosition(m_position);
    m_text.setFont(m_context.font);
    m_text.setString(m_textString);
    m_text.setCharacterSize(m_textSize);
    m_text.setFillColor(m_textColor);

    sf::FloatRect textRect = m_text.getLocalBounds();
    sf::FloatRect backgroundRect = m_background.getLocalBounds();

    if (textRect.width + m_padding.x * 2 > backgroundRect.width)
    {
        m_size.x = textRect.width + m_padding.x * 2;
        update();
    }

    if (textRect.height + m_padding.y * 2 > backgroundRect.height)
    {
        m_size.y = textRect.height + m_padding.y * 2;
        update();
    }

    centerText();
}

void Widget::centerText()
{
    sf::FloatRect textRect = m_text.getLocalBounds();
    sf::Vector2f origin;

    origin.x = textRect.left + textRect.width / 2.0f;
    origin.y = textRect.top + textRect.height / 2.0f;

    m_text.setOrigin(origin);
    m_text.setPosition(sf::Vector2f(m_position.x + m_size.x / 2.0f, 1 + m_position.y + m_size.y / 2.0f));
}

bool Widget::hitWidget()
{
    sf::Vector2i mp = sf::Mouse::getPosition(m_context.window);
//    LOG_DEBUG(mp.x << " , " << mp.y);
    return  mp.x > m_position.x &&
            mp.y > m_position.y &&
            mp.x < m_position.x + m_size.x &&
            mp.y < m_position.y + m_size.y;
}
